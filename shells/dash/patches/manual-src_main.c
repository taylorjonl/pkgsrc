$NetBSD$

Disable "sh -c" optimisation, fixes SIGPIPE failures.  From Debian.

--- src/main.c.orig	2015-11-30 17:52:08.000000000 +0000
+++ src/main.c
@@ -171,7 +171,7 @@ state2:
 state3:
 	state = 4;
 	if (minusc)
-		evalstring(minusc, sflag ? 0 : EV_EXIT);
+		evalstring(minusc, 0);
 
 	if (sflag || minusc == NULL) {
 state4:	/* XXX ??? - why isn't this before the "if" statement */
