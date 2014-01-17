$NetBSD: patch-src-post-planar-noise.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

Re-arrange inline asm to resolve 'error: can't find a register' failures.

--- src/post/planar/noise.c.orig	2013-09-18 10:04:54.000000000 +0000
+++ src/post/planar/noise.c
@@ -161,7 +161,11 @@ static inline void lineNoise_MMX(uint8_t
     noise+=shift;
 
     asm volatile(
-        "mov %3, %%"REG_a"      \n\t"
+        "mov %0, %%"REG_a"      \n\t"
+        :: "g" (-mmx_len)
+        : "%"REG_a
+    );
+    asm volatile(
         "pcmpeqb %%mm7, %%mm7       \n\t"
         "psllw $15, %%mm7       \n\t"
         "packsswb %%mm7, %%mm7      \n\t"
@@ -175,7 +179,7 @@ static inline void lineNoise_MMX(uint8_t
         "movq %%mm0, (%2, %%"REG_a")    \n\t"
         "add $8, %%"REG_a"      \n\t"
         " js 1b             \n\t"
-        :: "r" (src+mmx_len), "r" (noise+mmx_len), "r" (dst+mmx_len), "g" (-mmx_len)
+        :: "r" (src+mmx_len), "r" (noise+mmx_len), "r" (dst+mmx_len)
         : "%"REG_a
     );
     if(mmx_len!=len)
@@ -230,13 +234,21 @@ static inline void lineNoiseAvg_MMX(uint
     intarch_t mmx_len= len&(~7);
 
     asm volatile(
-        "mov %5, %%"REG_a"      \n\t"
+        "mov %0, %%"REG_a"      \n\t"
 	ASMALIGN(4)
         "1:             \n\t"
+        :: "g" (-mmx_len)
+        : "%"REG_a
+    );
+    asm volatile(
         "movq (%1, %%"REG_a"), %%mm1    \n\t"
         "movq (%0, %%"REG_a"), %%mm0    \n\t"
-        "paddb (%2, %%"REG_a"), %%mm1   \n\t"
-        "paddb (%3, %%"REG_a"), %%mm1   \n\t"
+        :: "r" (src+mmx_len), "r" (shift[0]+mmx_len)
+        : "%"REG_a
+    );
+    asm volatile(
+        "paddb (%0, %%"REG_a"), %%mm1   \n\t"
+        "paddb (%1, %%"REG_a"), %%mm1   \n\t"
         "movq %%mm0, %%mm2      \n\t"
         "movq %%mm1, %%mm3      \n\t"
         "punpcklbw %%mm0, %%mm0     \n\t"
@@ -252,11 +264,10 @@ static inline void lineNoiseAvg_MMX(uint
         "psrlw $8, %%mm1        \n\t"
         "psrlw $8, %%mm3        \n\t"
                 "packuswb %%mm3, %%mm1      \n\t"
-        "movq %%mm1, (%4, %%"REG_a")    \n\t"
+        "movq %%mm1, (%2, %%"REG_a")    \n\t"
         "add $8, %%"REG_a"      \n\t"
         " js 1b             \n\t"
-        :: "r" (src+mmx_len), "r" (shift[0]+mmx_len), "r" (shift[1]+mmx_len), "r" (shift[2]+mmx_len),
-                   "r" (dst+mmx_len), "g" (-mmx_len)
+        :: "r" (shift[1]+mmx_len), "r" (shift[2]+mmx_len), "r" (dst+mmx_len)
         : "%"REG_a
     );
 
@@ -333,15 +344,20 @@ static const char *const enum_quality[]
  * description of params struct
  */
 START_PARAM_DESCR( noise_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to luma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to chroma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
     "Quality level of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
     "Type of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
     "Mix random noise with a (semi)regular pattern" )
 END_PARAM_DESCR( param_descr )
 
