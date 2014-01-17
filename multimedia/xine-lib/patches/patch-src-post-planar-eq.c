$NetBSD: patch-src-post-planar-eq.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

Re-arrange inline asm to resolve 'error: can't find a register' failures.

--- src/post/planar/eq.c.orig	2013-09-18 10:04:54.000000000 +0000
+++ src/post/planar/eq.c
@@ -50,8 +50,12 @@ static void process_MMX(unsigned char *d
 
 	while (h--) {
 		asm volatile (
-			"movq (%5), %%mm3 \n\t"
-			"movq (%6), %%mm4 \n\t"
+			"movq (%0), %%mm3 \n\t"
+			"movq (%1), %%mm4 \n\t"
+			:
+			: "r" (brvec), "r" (contvec)
+		);
+		asm volatile (
 			"pxor %%mm0, %%mm0 \n\t"
 			"movl %4, %%eax\n\t"
 			ASMALIGN(4)
@@ -73,7 +77,7 @@ static void process_MMX(unsigned char *d
 			"decl %%eax \n\t"
 			"jnz 1b \n\t"
 			: "=r" (src), "=r" (dest)
-			: "0" (src), "1" (dest), "r" (w>>3), "r" (brvec), "r" (contvec)
+			: "0" (src), "1" (dest), "r" (w>>3)
 			: "%eax"
 		);
 
@@ -138,9 +142,11 @@ typedef struct eq_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( eq_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
             "brightness" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
             "contrast" )
 END_PARAM_DESCR( param_descr )
 
