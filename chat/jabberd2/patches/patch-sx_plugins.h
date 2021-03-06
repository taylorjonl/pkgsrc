$NetBSD: patch-sx_plugins.h,v 1.1 2015/12/13 23:46:11 schnoebe Exp $

Don't unconditionally include http_parser and friends, only
include when USE_WEBSOCKET is defined.

From
https://github.com/jabberd2/jabberd2/commit/b861b9c72adc732cbdfbac4eb8a4205126227f6b

--- sx/plugins.h.orig	2015-09-01 09:55:43.000000000 +0000
+++ sx/plugins.h
@@ -159,7 +159,7 @@ typedef struct _sx_compress_conn_st {
 JABBERD2_API int sx_ack_init(sx_env_t env, sx_plugin_t p, va_list args);
 
 /* websocket wrapper plugin */
-//#ifdef USE_WEBSOCKET
+#ifdef USE_WEBSOCKET
 #include <http_parser.h>
 #include <util/util.h>
 
@@ -183,7 +183,7 @@ typedef struct _sx_websocket_conn_st {
     xht                     headers;
     void                    *frame;
 } *_sx_websocket_conn_t;
-//#endif
+#endif
 
 #ifdef __cplusplus
 }
