# $NetBSD: Makefile,v 1.4 2015/08/20 12:13:30 jperkin Exp $

DISTNAME=	libhdhomerun_20140121
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://download.silicondust.com/hdhomerun/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.silicondust.com/
COMMENT=	Client and library for Silicon Dust HD Homerun
LICENSE=	gnu-lgpl-v2.1

USE_GCC_RUNTIME=	yes

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/libhdhomerun
INSTALLATION_DIRS=	bin lib include/hdhomerun

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SHLIBEXT=	dylib
.else
SHLIBEXT=	so
.endif
PLIST_SUBST+=	SHLIBEXT=${SHLIBEXT}

INSTALL_HEADERS=hdhomerun.h \
		hdhomerun_channelscan.h \
		hdhomerun_channels.h \
		hdhomerun_control.h \
		hdhomerun_debug.h \
		hdhomerun_device.h \
		hdhomerun_device_selector.h \
		hdhomerun_discover.h \
		hdhomerun_os.h \
		hdhomerun_os_posix.h \
		hdhomerun_os_windows.h \
		hdhomerun_pkt.h \
		hdhomerun_sock.h \
		hdhomerun_types.h \
		hdhomerun_video.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hdhomerun_config ${DESTDIR}${PREFIX}/bin/hdhomerun_config
	${INSTALL_LIB} ${WRKSRC}/libhdhomerun.${SHLIBEXT} ${DESTDIR}${PREFIX}/lib/libhdhomerun.${SHLIBEXT}
.for h in ${INSTALL_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${h} ${DESTDIR}${PREFIX}/include/hdhomerun/${h}
.endfor

.include "../../mk/bsd.pkg.mk"
