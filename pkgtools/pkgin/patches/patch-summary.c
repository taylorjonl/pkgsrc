$NetBSD$

Make pkgin compatible with libarchive<3, so that we do not have bring
a major version into the LTS release.

--- summary.c.orig	2015-08-18 19:19:55.000000000 +0000
+++ summary.c
@@ -133,7 +133,7 @@ fetch_summary(char *cur_repo)
 	if ((a = archive_read_new()) == NULL)
 		errx(EXIT_FAILURE, "Cannot initialise archive");
 
-	if (archive_read_support_filter_all(a) != ARCHIVE_OK ||
+	if (archive_read_support_compression_all(a) != ARCHIVE_OK ||
 	    archive_read_support_format_raw(a) != ARCHIVE_OK ||
 	    archive_read_open(a, sum, sum_start, sum_read, sum_close) != ARCHIVE_OK)
 		errx(EXIT_FAILURE, "Cannot open pkg_summary: %s",
@@ -517,7 +517,7 @@ insert_remote_summary(struct archive *a,
 		    archive_error_string(a));
 	}
 
-	archive_read_free(a);
+	archive_read_close(a);
 }
 
 static void
