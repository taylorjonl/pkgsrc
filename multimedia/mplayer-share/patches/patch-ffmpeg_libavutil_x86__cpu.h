$NetBSD$

-fomit-frame-pointer workaround.

--- ffmpeg/libavutil/x86_cpu.h.orig	2013-05-05 18:11:42.000000000 +0000
+++ ffmpeg/libavutil/x86_cpu.h
@@ -68,7 +68,7 @@ typedef int32_t x86_reg;
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS 0
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
