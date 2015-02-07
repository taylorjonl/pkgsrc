$NetBSD$

Turn off confirmation prompt to install new database, we always want it.

--- pkgindb.c.orig	2015-01-24 17:32:24.000000000 +0000
+++ pkgindb.c
@@ -165,9 +165,11 @@ upgrade_database()
 		 * COMPAT_CHECK query leads to an error for an
 		 * incompatible database
 		 */
+#if 0
 		printf(MSG_DATABASE_NOT_COMPAT);
 		if (!check_yesno(DEFAULT_YES))
 			exit(EXIT_FAILURE);
+#endif
 
 		pkgindb_reset();
 
