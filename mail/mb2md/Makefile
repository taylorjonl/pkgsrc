# $NetBSD: Makefile,v 1.10 2015/06/12 10:50:20 wiz Exp $
#

DISTNAME=		mb2md-3.20.pl
PKGNAME=		${DISTNAME:S/.pl$//}
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://batleth.sapienti-sat.org/projects/mb2md/
COMMENT=		Converts one or more mboxes to maildirs

DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate

WRKSRC=			${WRKDIR}

USE_TOOLS+=		perl:run
REPLACE_PERL=		${DISTNAME}

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
