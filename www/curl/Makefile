# $NetBSD: Makefile,v 1.156 2015/12/06 11:31:13 wiz Exp $

DISTNAME=	curl-7.46.0
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

# list it into IPv6-ready packages
BUILD_DEFS+=	IPV6_READY

USE_TOOLS+=		nroff
# https://github.com/bagder/curl/issues/555
USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
PKGCONFIG_OVERRIDE=	libcurl.pc.in

INSTALLATION_DIRS=	share/doc/curl

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=		check
USE_TOOLS+=		perl
.endif

.if ${_USE_DESTDIR} == "no"
PRIVILEGED_STAGES+=	clean
.endif

.include "options.mk"

post-install:
.for f in MANUAL TheArtOfHttpScripting FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${PREFIX}/share/doc/curl/
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
