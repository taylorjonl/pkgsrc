# $NetBSD$
#

BUILDLINK_TREE+=	xorg-cf-files

.if !defined(XORG_CF_FILES_BUILDLINK3_MK)
XORG_CF_FILES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xorg-cf-files+=	xorg-cf-files>=1.0.5
BUILDLINK_PKGSRCDIR.xorg-cf-files?=	../../x11/xorg-cf-files

BUILDLINK_CONTENTS_FILTER.xorg-cf-files=	${EGREP} '.*\.(cf|def|rules|tmpl)$$'

.endif # XORG_CF_FILES_BUILDLINK3_MK

BUILDLINK_TREE+=	-xorg-cf-files
