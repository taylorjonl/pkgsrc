# $NetBSD: Makefile,v 1.5 2015/10/26 19:04:01 adam Exp $

DISTNAME=	qtwebsockets-opensource-src-${QTVERSION}
PKGNAME=	qt5-websockets-${QTVERSION}
COMMENT=	Qt5 module for websockets

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Websockets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor


.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
