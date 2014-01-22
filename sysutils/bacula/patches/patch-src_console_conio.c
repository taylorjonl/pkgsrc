$NetBSD$

Spell HAVE_TERM_H correctly.

--- src/console/conio.c.orig	2012-09-13 08:51:19.000000000 +0000
+++ src/console/conio.c
@@ -61,11 +61,12 @@
 
 #endif
 
+#include <termios.h>
 #include <curses.h>
 #include <term.h>
 
 #if defined(HAVE_SUN_OS)
-#if !defined(_TERM_H)
+#if !defined(HAVE_TERM_H)
 extern "C" int tgetent(void *, const char *);
 extern "C" int tgetnum(const char *);
 extern "C" char *tgetstr (const char*, char**);
@@ -245,7 +246,9 @@ static char * getnext(void);
 static char * getprev(void);
 static void putline(char *newl, int newlen);
 static void t_honk_horn(void);
+#undef t_insert_line
 static void t_insert_line(void);
+#undef t_delete_line
 static void t_delete_line(void);
 static void t_clrline(int pos, int width);
 void t_sendl(const char *msg, int len);
