$NetBSD$

Fix "call of overloaded 'abs(XYPOSITION)' is ambiguous".

--- src/stc/scintilla/src/Editor.cxx.orig	2014-06-14 21:48:48.000000000 +0000
+++ src/stc/scintilla/src/Editor.cxx
@@ -5841,9 +5841,9 @@ void Editor::GoToLine(int lineNo) {
 }
 
 static bool Close(Point pt1, Point pt2) {
-	if (abs(pt1.x - pt2.x) > 3)
+	if (abs((int)pt1.x - (int)pt2.x) > 3)
 		return false;
-	if (abs(pt1.y - pt2.y) > 3)
+	if (abs((int)pt1.y - (int)pt2.y) > 3)
 		return false;
 	return true;
 }
