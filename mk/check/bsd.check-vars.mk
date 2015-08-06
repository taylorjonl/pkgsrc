# $NetBSD: bsd.check-vars.mk,v 1.7 2009/07/26 05:32:43 agc Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_FILES_SUPPORTED?=		yes
CHECK_SHLIBS_SUPPORTED?=	yes

.if ${_OPSYS_CAN_CHECK_SHLIBS:tl} == "yes"
_USE_CHECK_SHLIBS_NATIVE=	yes
.else
_USE_CHECK_SHLIBS_NATIVE=	no
.endif

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
