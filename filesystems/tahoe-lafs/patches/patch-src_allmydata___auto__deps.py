$NetBSD$

Python no longer likes these multi-version dependencies.

--- src/allmydata/_auto_deps.py.orig	2013-05-01 17:32:45.000000000 +0000
+++ src/allmydata/_auto_deps.py
@@ -16,7 +16,7 @@ install_requires = [
 
     # zope.interface >= 3.6.0 is required for Twisted >= 12.1.0.
     # zope.interface 3.6.3 and 3.6.4 are incompatible with Nevow (#1435).
-    "zope.interface == 3.6.0, == 3.6.1, == 3.6.2, >= 3.6.5",
+    "zope.interface >= 3.6.5",
 
     # * On Windows we need at least Twisted 9.0 to avoid an indirect
     #   dependency on pywin32.
@@ -55,7 +55,7 @@ install_requires = [
     # Needed for SFTP. pyasn1 is needed by twisted.conch in Twisted >= 9.0.
     # pycrypto 2.2 doesn't work due to https://bugs.launchpad.net/pycrypto/+bug/620253
     # pycrypto 2.4 doesn't work due to https://bugs.launchpad.net/pycrypto/+bug/881130
-    "pycrypto == 2.1.0, == 2.3, >= 2.4.1",
+    "pycrypto >= 2.4.1",
     "pyasn1 >= 0.0.8a",
 
     # http://www.voidspace.org.uk/python/mock/ , 0.8.0 provides "call"
