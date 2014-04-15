$NetBSD$

--- gcc/config/sol2.h.orig	2011-08-18 14:47:46.000000000 +0000
+++ gcc/config/sol2.h	2012-08-23 09:24:51.940429748 +0000
@@ -149,8 +149,9 @@
   "%{G:-G} \
    %{YP,*} \
    %{R*} \
-   %{!YP,*:%{p|pg:-Y P,%R/usr/ccs/lib/libp:%R/usr/lib/libp:%R/usr/ccs/lib:%R/lib:%R/usr/lib} \
-	   %{!p:%{!pg:-Y P,%R/usr/ccs/lib:%R/lib:%R/usr/lib}}}"
+   -R@PREFIX@/lib \
+   %{!YP,*:%{p|pg:-Y P,%R/usr/ccs/lib/libp:%R/usr/lib/libp:%R/usr/ccs/lib:%R/lib:%R/usr/lib:%R@PREFIX@/lib} \
+	   %{!p:%{!pg:-Y P,%R/usr/ccs/lib:%R/lib:%R/usr/lib:%R@PREFIX@/lib}}}"
 
 #undef LINK_ARCH32_SPEC
 #define LINK_ARCH32_SPEC LINK_ARCH32_SPEC_BASE
