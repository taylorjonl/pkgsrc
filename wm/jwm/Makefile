# $NetBSD: Makefile,v 1.27 2015/12/13 15:02:36 tsutsui Exp $
#

DISTNAME=		jwm-2.3.4
CATEGORIES=		wm x11
MASTER_SITES=		http://www.joewing.net/programs/jwm/releases/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://www.joewing.net/programs/jwm/
COMMENT=		Lightweight window manager with virtual desktops
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native" || exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
# XXX maybe set some build variable about that
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e 's,@@EGDIR@@,${EGDIR},g'

SUBST_CLASSES+=		icondir
SUBST_STAGE.icondir=	post-patch
SUBST_FILES.icondir=	example.jwmrc
SUBST_SED.icondir=	-e 's|/usr/share/icons|${PREFIX}/share/icons|g'

PKG_SYSCONFSUBDIR=	jwm
EGDIR=			${PREFIX}/share/examples/jwm
CONF_FILES=	${EGDIR}/system.jwmrc ${PKG_SYSCONFDIR}/system.jwmrc

INSTALLATION_DIRS=	bin

.include "options.mk"

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
