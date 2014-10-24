# $NetBSD: Makefile,v 1.31 2014/08/13 10:56:35 adam Exp $

BOOST_PACKAGE=		headers
BOOST_COMMENT=		(build-time headers)
BOOST_CONFIG=		generate

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-* # disable all libraries

NO_BUILD=		yes

.include "../../devel/boost-jam/bjam.mk"

post-configure:
	{ ${ECHO};                                                              \
	  ${ECHO} "#if defined(BOOST_HAS_INT128) && !defined(__x86_64__)";      \
	  ${ECHO} "#undef BOOST_HAS_INT128";                                    \
	  ${ECHO} "#endif"; } >> ${WRKSRC}/boost/config/user.hpp

do-install: bjam-install
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${PREFIX}/include/boost \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
