# $NetBSD: Makefile,v 1.9 2015/11/23 15:46:59 taca Exp $
#

DISTNAME=	ruby-progressbar-0.9
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://0xcc.net/ruby-progressbar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-progressbar/
COMMENT=	Text Progress Bar Library for Ruby
LICENSE=	ruby-license

RUBY_VERSION_SUPPORTED= 200 18 21 22

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	${RUBY_DOC}/progressbar ${RUBY_VENDORLIB}

do-test:
	${RUN} cd ${WRKSRC}; ${RUBY} test.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/progressbar.rb \
		${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
.for d in progressbar.en.rd progressbar.ja.rd
	${INSTALL_DATA} ${WRKSRC}/${d} \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/progressbar
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
