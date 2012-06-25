# $NetBSD: Makefile,v 1.18 2013/04/08 11:17:10 rodent Exp $

MODNAME=		pdo_mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (MySQL)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-pdo_mysql
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
.else
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}
.include "../../mk/mysql.buildlink3.mk"
.endif

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
