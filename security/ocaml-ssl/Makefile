# $NetBSD: Makefile,v 1.18 2015/08/07 11:20:33 jaapb Exp $
#

PKGNAME=	${DISTNAME} # to avoid prefixing with ocaml-
DISTNAME=	ocaml-ssl-0.4.7
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=savonet/}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://savonet.sourceforge.net/wiki/OCamlLibs
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

# ssl.cmo used before written
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
