# $NetBSD: Makefile,v 1.17 2015/11/06 21:42:14 wiz Exp $

DISTNAME=	requests-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

USE_LANGUAGES=	c
REPLACE_PYTHON=	requests/certs.py requests/packages/chardet/chardetect.py

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
