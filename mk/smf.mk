# $NetBSD$
#

.if !defined(SMF_MK)
SMF_MK=				# defined

# Directory to hold the SMF manifest/method files
PKG_SMF_DIR?=			lib/svc
PKG_SMF_MANIFEST_DIR?=		${PKG_SMF_DIR}/manifest
PKG_SMF_METHOD_DIR?=		${PKG_SMF_DIR}/method

# Prefix of SMF services FMRI
SMF_PREFIX?=			pkgsrc

# Variables that can be overriden by the user on a package by package basis
SMF_NAME?=			${PKGBASE:tl}
SMF_INSTANCES?=			default
SMF_MANIFEST?=			manifest.xml
SMF_METHODS?=			# empty
SMF_METHOD_SHELL?=		/sbin/sh
SMF_SRCDIR?=			${FILESDIR}/smf

# Dynamically remove rc.d entries, primarily for pkgsrc-{joyent,wip}
PLIST_AWK+=			-f ${PKGSRCDIR}/mk/plist/plist-smf.awk

# A manifest file is a pre-requisite for anything to happen.  We cannot test
# for existance if the manifest is under WRKDIR as the source has not yet been
# unpacked, so we assume it will exist later when required.
.  if exists(${SMF_SRCDIR}/${SMF_MANIFEST}) || !empty(SMF_SRCDIR:M${WRKDIR}*)

SMF_MANIFEST_SRC?=		${SMF_SRCDIR}/${SMF_MANIFEST}
SMF_MANIFEST_WRK?=		${WRKDIR}/.smf_${SMF_MANIFEST}
SMF_MANIFEST_FILE?=		${PKG_SMF_MANIFEST_DIR}/${SMF_NAME}.xml

FILES_SUBST+=			PKGMANDIR=${PKGMANDIR:Q}
FILES_SUBST+=			SMF_PREFIX=${SMF_PREFIX:Q}
FILES_SUBST+=			SMF_NAME=${SMF_NAME:Q}
FILES_SUBST+=			SMF_INSTANCES=${SMF_INSTANCES:Q}
FILES_SUBST+=			SMF_MANIFEST=${SMF_MANIFEST:Q}
FILES_SUBST+=			SMF_MANIFEST_FILE=${SMF_MANIFEST_FILE:Q}
FILES_SUBST+=			SMF_METHOD_SHELL=${SMF_METHOD_SHELL:Q}

INSTALLATION_DIRS+=		${PKG_SMF_MANIFEST_DIR}
MULTIARCH_SKIP_DIRS.lib+=	${PKG_SMF_DIR}

.PHONY: generate-smf-manifest
generate-smf-manifest: ${SMF_MANIFEST_WRK}
${SMF_MANIFEST_WRK}: ${SMF_MANIFEST_SRC}
	@${STEP_MSG} "Creating ${.TARGET}"
	${RUN}${CAT} ${.ALLSRC} | ${SED} ${FILES_SUBST_SED} > ${.TARGET}

.PHONY: install-smf-manifest
post-install: install-smf-manifest
install-smf-manifest: ${SMF_MANIFEST_WRK}
	${INSTALL_DATA} ${SMF_MANIFEST_WRK} ${DESTDIR}${PREFIX}/${SMF_MANIFEST_FILE}

GENERATE_PLIST+=		${ECHO} "${SMF_MANIFEST_FILE}";
PRINT_PLIST_AWK+=		/^${SMF_MANIFEST_FILE:S|/|\\/|g}/ { next; }

# Target to add the INSTALL script to auto-import SMF manifest using svccfg
${WRKDIR}/.smfinstall: ${PKGSRCDIR}/mk/install/install-smf
	@${CP} ${PKGSRCDIR}/mk/install/install-smf ${WRKDIR}/.smfinstall

INSTALL_TEMPLATES+=		${WRKDIR}/.smfinstall

# Install optional SMF methods
#
.PHONY: generate-smf-methods
generate-smf-methods:	# do nothing

.PHONY: install-smf-methods
post-install: install-smf-methods
install-smf-methods:	# do nothing

.    for _method_ in ${SMF_METHODS}
SMF_METHOD_SRC.${_method_}?=	${SMF_SRCDIR}/${_method_}.sh
SMF_METHOD_WRK.${_method_}?=	${WRKDIR}/.smf_${_method_}
SMF_METHOD_FILE.${_method_}?=	${PKG_SMF_METHOD_DIR}/${_method_}

FILES_SUBST+=	SMF_METHOD_FILE.${_method_}=${SMF_METHOD_FILE.${_method_}}

.      if !empty(SMF_METHOD_SRC.${_method_})
generate-smf-methods: ${SMF_METHOD_WRK.${_method_}}
${SMF_METHOD_WRK.${_method_}}: ${SMF_METHOD_SRC.${_method_}}
	@${STEP_MSG} "Creating ${.TARGET}"
	${RUN}${CAT} ${.ALLSRC} | ${SED} ${FILES_SUBST_SED} > ${.TARGET}
	${RUN}${CHMOD} +x ${.TARGET}

install-smf-methods: install-smf-${_method_}
install-smf-${_method_}: ${SMF_METHOD_WRK.${_method_}}
	${RUN} \
	if [ -f ${SMF_METHOD_WRK.${_method_}} ]; then \
		${MKDIR} ${DESTDIR}${PREFIX}/${PKG_SMF_METHOD_DIR}; \
		${INSTALL_SCRIPT} ${SMF_METHOD_WRK.${_method_}} \
			${DESTDIR}${PREFIX}/${SMF_METHOD_FILE.${_method_}}; \
	fi
.      endif
GENERATE_PLIST+=	${ECHO} ${SMF_METHOD_FILE.${_method_}};
PRINT_PLIST_AWK+=	/^${SMF_METHOD_FILE.${_method_}:S|/|\\/|g}/ { next; }
.    endfor
.  endif
.endif
