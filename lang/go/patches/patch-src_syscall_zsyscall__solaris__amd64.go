$NetBSD$

Add support for the dup2 syscall.

--- src/syscall/zsyscall_solaris_amd64.go.orig	2015-02-18 04:38:34.000000000 +0000
+++ src/syscall/zsyscall_solaris_amd64.go
@@ -22,6 +22,7 @@ var (
 	procChroot       = modlibc.NewProc("chroot")
 	procClose        = modlibc.NewProc("close")
 	procDup          = modlibc.NewProc("dup")
+	procDup2         = modlibc.NewProc("dup2")
 	procExit         = modlibc.NewProc("exit")
 	procFchdir       = modlibc.NewProc("fchdir")
 	procFchmod       = modlibc.NewProc("fchmod")
@@ -230,6 +231,14 @@ func Dup(fd int) (nfd int, err error) {
 	return
 }
 
+func Dup2(from int, to int) (err error) {
+        _, _, e1 := sysvicall6(procDup2.Addr(), 2, uintptr(from), uintptr(to), 0, 0, 0, 0)
+        if e1 != 0 {
+                err = e1
+        }
+        return
+}
+
 func Exit(code int) {
 	sysvicall6(procExit.Addr(), 1, uintptr(code), 0, 0, 0, 0, 0)
 	return
