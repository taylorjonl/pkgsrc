# $NetBSD$

#
# Reads a list of commands from stdin using the syntax:
#
#   cmd=commandBATCH_COMMANDS_SEP/path/to/file
#   link=/path/to/srcBATCH_COMMANDS_SEP/path/to/dst
#
# "cmd" is any arbitrary command which supports multiple arguments, "link" is
# a list of symlink targets.  After reading all of the commands in, the script
# will reduce them into the minimum number of commands required, and output
# them back to stdout ready for piping to sh.
#
# The only ordering guarantee is that link target directories will be created
# prior to running the corresponding "ln".
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

BEGIN {
	# A little under 256 to leave space for options and trailing args.
	ARGMAX = 252;
	CMD_LN = "ln -fs";
	CMD_MKDIRP = "mkdir -p";
	FS = BATCH_COMMANDS_SEP;
	numcmds = 0;
}

/^link=/ {
	sub(/^link=/, "", $1);
	src = srcfile = $1;
	dst = dstfile = dstdir = $2;
	sub(/.*\//, "", srcfile);
	sub(/.*\//, "", dstfile);
	sub(/\/[^\/]*$/, "", dstdir);

	# Assume we will always need to create directories.
	if (!(CMD_MKDIRP in commands)) {
		numcmds++;
		cmdorder[numcmds] = CMD_MKDIRP;
		numcmds++;
		cmdorder[numcmds] = CMD_LN;
	}

	# If we're renaming the file, it must be handled separately.
	if (srcfile == dstfile) {
		if (dstdir in links)
			links[dstdir] = links[dstdir] FS src;
		else
			links[dstdir] = src;
	} else {
		links[dst] = src;
	}

	# Batch up mkdir creation for symlink target directories.
	if (!(dstdir in seendirs)) {
		seendirs[dstdir] = 1;
		if (commands[CMD_MKDIRP])
			commands[CMD_MKDIRP] = commands[CMD_MKDIRP] FS dstdir;
		else
			commands[CMD_MKDIRP] = dstdir;
	}
	next;
}

/^cmd=/ {
	sub(/^cmd=/, "", $1);
	cmd = $1; arg = $2;

	if (commands[cmd])
		commands[cmd] = commands[cmd] FS arg;
	else {
		numcmds++;
		cmdorder[numcmds] = cmd;
		commands[cmd] = arg;
	}
	next;
}

END {
	if (numcmds == 0)
		exit;

	for (n = 1; n <= numcmds; n++) {
		cmd = cmdorder[n];
		if (cmd == CMD_LN) {
			for (dst in links) {
				nargs = split(links[dst], args, FS);
				printf(CMD_LN);
				for (i = 1; i <= nargs; i++) {
					if (i > 1 && i % ARGMAX == 0)
						printf(" %s\n" CMD_LN, shquote(dst));
					printf(" %s", shquote(args[i]));
				}
				printf(" %s\n", shquote(dst));
			}
		} else {
			nargs = split(commands[cmd], args, FS);
			printf("%s", cmd);
			for (i = 1; i <= nargs; i++) {
				if (i > 1 && i % ARGMAX == 0)
					printf("\n%s", cmd);
				printf(" %s", shquote(args[i]));
			}
			printf("\n");
		}
	}
}
