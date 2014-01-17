$NetBSD: patch-src_post_goom_convolve_fx.c,v 1.1 2012/09/20 15:33:40 jperkin Exp $

Re-arrange inline asm to resolve 'error: can't find a register' failures.

--- src/post/goom/convolve_fx.c.orig	2009-11-30 21:29:12.000000000 +0000
+++ src/post/goom/convolve_fx.c
@@ -173,7 +173,10 @@ static void create_output_with_brightnes
     {
       __asm__ __volatile__
         (
-         "\n\t movd  %1, %%mm0"  /* mm0 = src */
+         "\n\t movd  %0, %%mm0"  /* mm0 = src */
+         ::"g"  (src[i].val));
+      __asm__ __volatile__
+        (
          "\n\t paddd %%mm4, %%mm2"   /* [ ytex | xtex ] += [ -s | s ] */
          "\n\t movd  %%esi, %%mm5"   /* save esi into mm5 */
          "\n\t movq  %%mm2, %%mm3"
@@ -191,7 +194,7 @@ static void create_output_with_brightnes
          "\n\t xorl  %%ecx, %%ecx"
          "\n\t movb  (%%eax,%%esi), %%cl"
 
-         "\n\t movl  %2, %%eax"
+         "\n\t movl  %1, %%eax"
          "\n\t movd  %%mm5, %%esi"    /* restore esi from mm5 */
          "\n\t movd  (%%eax,%%ecx,4), %%mm1" /* mm1 = [0|0|0|iff2] */
 
@@ -205,8 +208,7 @@ static void create_output_with_brightnes
          "\n\t packuswb  %%mm7, %%mm0"
          "\n\t movd      %%mm0, %0"
          : "=g" (dest[i].val)
-         : "g"  (src[i].val)
-         , "g"(&ifftab[0])
+         : "g"(&ifftab[0])
          : "eax","ecx");
 
       i++;
