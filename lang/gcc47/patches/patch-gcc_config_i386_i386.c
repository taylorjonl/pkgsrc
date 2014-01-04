$NetBSD$

Disable -fomit-frame-pointer.

--- gcc/config/i386/i386.c.orig	2013-04-02 16:54:39.000000000 +0000
+++ gcc/config/i386/i386.c
@@ -3547,7 +3547,7 @@ ix86_option_override_internal (bool main
     }
 
   /* Keep nonleaf frame pointers.  */
-  if (flag_omit_frame_pointer)
+  if (0)
     target_flags &= ~MASK_OMIT_LEAF_FRAME_POINTER;
   else if (TARGET_OMIT_LEAF_FRAME_POINTER)
     flag_omit_frame_pointer = 1;
@@ -3685,7 +3685,7 @@ ix86_option_override_internal (bool main
      around edges.  */
   if ((flag_unwind_tables || flag_asynchronous_unwind_tables
        || flag_exceptions || flag_non_call_exceptions)
-      && flag_omit_frame_pointer
+      && 0
       && !(target_flags & MASK_ACCUMULATE_OUTGOING_ARGS))
     {
       if (target_flags_explicit & MASK_ACCUMULATE_OUTGOING_ARGS)
@@ -9973,7 +9973,7 @@ ix86_finalize_stack_realign_flags (void)
       && !crtl->need_drap
       && frame_pointer_needed
       && current_function_is_leaf
-      && flag_omit_frame_pointer
+      && 0
       && current_function_sp_is_unchanging
       && !ix86_current_function_calls_tls_descriptor
       && !crtl->accesses_prior_frames
