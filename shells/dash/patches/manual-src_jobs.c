$NetBSD$

Fix format string, from Debian.

--- src/jobs.c.orig	2015-11-30 17:52:08.000000000 +0000
+++ src/jobs.c
@@ -427,7 +427,7 @@ sprint_status(char *s, int status, int s
 				goto out;
 #endif
 		}
-		col = fmtstr(s, 32, strsignal(st));
+		col = fmtstr(s, 32, "%s", strsignal(st));
 #ifdef WCOREDUMP
 		if (WCOREDUMP(status)) {
 			col += fmtstr(s + col, 16, " (core dumped)");
