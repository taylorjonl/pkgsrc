# $NetBSD: Makefile,v 1.14 2015/11/15 08:10:21 wen Exp $

DISTNAME=	Starlet-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Starlet/
COMMENT=	Perl 5 Plack based standalone HTTP/1.0 server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Starlet/.packlist

BUILD_DEPENDS+=	p5-Test-TCP>=2.10:../../net/p5-Test-TCP
DEPENDS+=	p5-Parallel-Prefork>=0.17:../../devel/p5-Parallel-Prefork
DEPENDS+=	p5-Plack>=0.992:../../www/p5-Plack
DEPENDS+=	p5-Server-Starter>=0.06:../../sysutils/p5-Server-Starter

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
