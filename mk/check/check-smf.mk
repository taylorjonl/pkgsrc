# $NetBSD$
#
# This file checks that after installation, all SMF files of the package
# are correctly formed.
#
# This file is only loaded when INIT_SYSTEM is set to 'smf'.
#

.if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no"
CHECK_SMF?=		yes
.else
CHECK_SMF?=		no
.endif

_CHECK_SMF_FILELIST_CMD?=	${SED} -ne "/^${PKG_SMF_DIR:S/\//\\\//g}/p" ${PLIST}

.if !empty(CHECK_SMF:M[Yy][Ee][Ss])
privileged-install-hook: _check-smf
.endif

_check-smf: error-check .PHONY
	@${STEP_MSG} "Checking for incorrect SMF files in ${PKGNAME}"
	${RUN} cd ${DESTDIR}${PREFIX};					\
	${_CHECK_SMF_FILELIST_CMD} | ${SORT} | ${SED} 's,\\,\\\\,g' |	\
	while read file; do						\
		if [ ! -f "$$file" ]; then				\
			continue;					\
		fi;							\
		if [ ! -r "$$file" ]; then				\
			${DELAYED_WARNING_MSG} "[check-smf.mk] File \"${DESTDIR}${PREFIX}/$$file\" cannot be read."; \
			continue;					\
		fi;							\
		${SHCOMMENT} "[$$file]";				\
		${EGREP} '@.*@' "$$file" >/dev/null &&			\
			${DELAYED_ERROR_MSG} "[check-smf.mk] The SMF file \"${DESTDIR}${PREFIX}/$$file\" contains unexpanded @.*@ substitutions."; \
	done
