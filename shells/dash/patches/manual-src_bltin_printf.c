$NetBSD$

Require octal sequences start with \0 to match behaviour of other shells, patch
from gentoo.

--- src/bltin/printf.c.orig	2015-11-30 16:33:12.000000000 +0000
+++ src/bltin/printf.c
@@ -247,18 +247,9 @@ conv_escape_str(char *str)
 		 * They start with a \0, and are followed by 0, 1, 2, 
 		 * or 3 octal digits. 
 		 */
-		if (ch == '0') {
-			unsigned char i;
-			i = 3;
-			ch = 0;
-			do {
-				unsigned k = octtobin(*str);
-				if (k > 7)
-					break;
-				str++;
-				ch <<= 3;
-				ch += k;
-			} while (--i);
+		if (ch >= '1' && ch <= '9') {
+			ch = '\\';
+			--str;
 			continue;
 		}
 
