# $NetBSD: Makefile,v 1.1 2015/07/02 03:37:49 rodent Exp $

DISTNAME=	xf86-video-voodoo-1.2.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Voodoo/Voodoo2 video driver
LICENSE=	mit # XXX AND one other

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.99.1
.include "../../x11/xextproto/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
