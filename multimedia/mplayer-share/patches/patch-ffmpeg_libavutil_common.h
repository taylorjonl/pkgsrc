$NetBSD: patch-ffmpeg_libavutil_common.h,v 1.1 2015/11/21 09:47:23 leot Exp $

--- ffmpeg/libavutil/common.h.orig	2013-01-06 21:53:29.000000000 +0000
+++ ffmpeg/libavutil/common.h
@@ -39,6 +39,22 @@
 #include "version.h"
 #include "libavutil/avconfig.h"
 
+#if defined(__cplusplus)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__)
+#undef _STDINT_H_
+#undef _SYS_STDINT_H_
+#undef _STDINT_H
+#undef _GCC_WRAP_STDINT_H
+#ifndef __STDC_CONSTANT_MACROS
+#define __STDC_CONSTANT_MACROS
+#endif
+#include <stdint.h>
+#endif /* FreeBSD | OpenBSD | linux */
+#if defined(__DragonFly__) || defined(__NetBSD__)
+#include <machine/int_const.h>
+#endif /* DragonFly | NetBSD */
+#endif /* __cplusplus */
+
 #if AV_HAVE_BIGENDIAN
 #   define AV_NE(be, le) (be)
 #else
