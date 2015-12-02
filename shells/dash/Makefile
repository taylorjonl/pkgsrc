# $NetBSD: Makefile,v 1.10 2015/06/14 11:04:24 ryoon Exp $
#

DISTNAME=	dash-0.5.8
CATEGORIES=	shells
MASTER_SITES=	http://gondor.apana.org.au/~herbert/dash/files/
MASTER_SITES=	# maintained locally
DISTFILES=	# empty

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://gondor.apana.org.au/~herbert/dash/
COMMENT=	Debian Almquist shell, POSIX-compliant shell faster than bash
LICENSE=	modified-bsd AND gnu-gpl-v2

BOOTSTRAP_PKG=	yes

GNU_CONFIGURE=		yes

PKG_SHELL=		bin/dash

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dash ${DESTDIR}${PREFIX}/bin/dash
	${INSTALL_MAN} ${WRKSRC}/src/dash.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dash.1
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/src/dash.cat1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/dash.1
.  else
	${INSTALL_MAN} ${WRKSRC}/src/dash.cat1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/dash.0
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
