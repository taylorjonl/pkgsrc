# $NetBSD: Makefile,v 1.10 2015/06/12 10:49:14 wiz Exp $

DISTNAME=	File-Save-Home-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Save-Home/
COMMENT=	Place file safely under user home directory
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-String-PerlIdentifier-[0-9]*:../../devel/p5-String-PerlIdentifier

PERL5_PACKLIST=		auto/File/Save/Home/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
