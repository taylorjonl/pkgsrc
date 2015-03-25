$NetBSD$

Handle OpenSSL 1.0.1m header change.

--- Modules/FindOpenSSL.cmake.orig	2014-01-16 17:15:08.000000000 +0000
+++ Modules/FindOpenSSL.cmake
@@ -264,7 +264,7 @@ if (OPENSSL_INCLUDE_DIR)
     set(OPENSSL_VERSION "${_OPENSSL_VERSION}")
   elseif(OPENSSL_INCLUDE_DIR AND EXISTS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h")
     file(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h" openssl_version_str
-         REGEX "^#define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])+.*")
+         REGEX "^# *define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x([0-9a-fA-F])+.*")
 
     # The version number is encoded as 0xMNNFFPPS: major minor fix patch status
     # The status gives if this is a developer or prerelease and is ignored here.
