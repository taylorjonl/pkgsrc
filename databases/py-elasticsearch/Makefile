# $NetBSD: Makefile,v 1.7 2015/10/18 16:46:53 fhajny Exp $

DISTNAME=	elasticsearch-py-2.0.0
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=elastic/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://github.com/elastic/elasticsearch-py/
COMMENT=	Official low-level python client for Elasticsearch
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME:S/-py//}
GITHUB_PROJECT=	elasticsearch-py

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.8.2:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
