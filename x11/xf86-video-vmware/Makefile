# $NetBSD: Makefile,v 1.23 2015/09/25 01:43:43 tnn Exp $

DISTNAME=	xf86-video-vmware-13.1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg VMware virtual video driver

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-vmware
PKG_SUPPORTED_OPTIONS=	xatracker
PKG_SUGGESTED_OPTIONS=	

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxatracker)
CFLAGS+=	-fPIC
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/libLLVM/buildlink3.mk"
.else
pre-configure:
	find ${BUILDLINK_DIR} -name xatracker.pc -delete
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXext?=	build
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
