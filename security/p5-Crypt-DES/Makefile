# $NetBSD: Makefile,v 1.26 2015/06/12 10:51:04 wiz Exp $
#

DISTNAME=		Crypt-DES-2.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES/
COMMENT=		XS-based DES implementation for Perl

BUILD_DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
