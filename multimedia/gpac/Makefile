# $NetBSD: Makefile,v 1.44 2015/11/18 14:19:52 ryoon Exp $

DISTNAME=	gpac-0.5.2
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=gpac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpac.wp.mines-telecom.fr/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake grep gsed pkg-config
USE_LANGUAGES=	c c++
# not really GNU configure, but close enough
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-wx
CONFIGURE_ARGS+=	--X11-path=${X11BASE}
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--extra-cflags="${CFLAGS}"
CONFIGURE_ARGS+=	--extra-ldflags="${LDFLAGS}"
CFLAGS+=		-I${BUILDLINK_PREFIX.faad2}/${BUILDLINK_INCDIRS.faad2}

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# doesn't work yet
#.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
