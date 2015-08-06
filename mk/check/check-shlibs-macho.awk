# $NetBSD$

#
# Read a list of potential Mach-O binaries from stdin.
# For each, check the list of required shared libraries and ensure that
# each of them can be found correctly, and check that the resolved DSO
# belongs to a full dependency.
#

function shquote(IN, out) {
	out = IN;
	gsub("\\\\", "\\\\", out);
	gsub("\\\n", "\\n", out);
	gsub("\\\t", "\\t", out);
	gsub(" ", "\\ ", out);
	gsub("'", "\\'", out);
	gsub("`", "\\`", out);
	gsub("\"", "\\\"", out);
	gsub(";", "\\;", out);
	gsub("&", "\\&", out);
	gsub("<", "\\<", out);
	gsub(">", "\\>", out);
	gsub("\\(", "\\(", out);
	gsub("\\)", "\\)", out);
	gsub("\\|", "\\|", out);
	gsub("\\*", "\\*", out);
	gsub("\\?", "\\?", out);
	gsub("\\{", "\\{", out);
	gsub("\\}", "\\}", out);
	gsub("\\[", "\\[", out);
	gsub("\\]", "\\]", out);
	gsub("\\$", "\\$", out);
	gsub("!", "\\!", out);
	gsub("#", "\\#", out);
	gsub("\\^", "\\^", out);
	gsub("~", "\\~", out);
	return out;
}

function check_pkg(DSO, pkg, found) {
	if (destdir == "")
		return 0
	if (DSO in pkgcache) {
		pkg = pkgcache[DSO]
	} else {
		cmd = pkg_info_cmd " -Fe " shquote(DSO) " 2> /dev/null"
		if ((cmd | getline pkg) < 0) {
			close(cmd)
			return 0
		}
		close(cmd)
		pkgcache[DSO] = pkg
	}
	if (pkg == "")
		return 0
	found=0
	while ((getline < depends_file) > 0) {
		if ($3 == pkg) {
			found=1
			if ($1 != "full")
				continue
			close(depends_file)
			return 0
		}
	}
	if (found)
		print DSO ": " pkg " is not a runtime dependency"
	close(depends_file)
}

function checkshlib(DSO, needed, rpath, found, dso_rath, got_rpath, nrpath) {
	cmd = "otool -XL " shquote(DSO) " 2> /dev/null"
	while ((cmd | getline) > 0) {
		needed[$1] = ""
	}
	close(cmd)
	for (lib in needed) {
		if (lib == wrkdir ||
		    substr(lib, 1, length(wrkdir) + 1) == wrkdir "/") {
			print DSO ": path relative to WRKDIR"
		}
			libfile = cross_destdir lib
			if (!(libfile in libcache)) {
				libcache[libfile] = system("test -f " shquote(libfile))
			}
			if (!libcache[libfile]) {
				check_pkg(lib)
				found = 1
				break
			}
			libfile = destdir lib
			if (!(libfile in libcache)) {
				libcache[libfile] = system("test -f " shquote(libfile))
			}
			if (!libcache[libfile]) {
				check_pkg(lib)
				found = 1
				break
			}
		if (found == 0)
			print DSO ": missing library: " lib;
	}
	delete needed
}

BEGIN {
	cross_destdir = ENVIRON["CROSS_DESTDIR"]
	destdir = ENVIRON["DESTDIR"]
	wrkdir = ENVIRON["WRKDIR"]
	pkg_info_cmd = ENVIRON["PKG_INFO_CMD"]
	depends_file = ENVIRON["DEPENDS_FILE"]
}

{ checkshlib($0); }
