# $NetBSD: Makefile,v 1.12 2015/06/12 10:49:16 wiz Exp $
#

DISTNAME=	FileHandle-Fmode-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FileHandle-Fmode/
COMMENT=	Perl 5 module to determine how a filehandle is opened
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/FileHandle/Fmode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
