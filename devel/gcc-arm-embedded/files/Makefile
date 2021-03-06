# $FreeBSD$

.include "Makefile.inc"

MULTILIB_LIST=	armv6-m,armv7-m,armv7e-m,armv7-r
PKGVERSION=	GNU Tools for ARM Embedded Processors

BUILD_PREFIX=	${WRKDIR}/build
DOC_PREFIX=	${INTERIM_PREFIX}/${DOCS_SUFFIX}

.if ${PORT_OPTIONS:MPURE}
WORLD_LIB=${INTERIM_WORLD}
.else
WORLD_LIB=${LOCALBASE}
.endif

LDFLAGS+=	-L${WORLD_LIB}/lib

.if ${CHOSEN_COMPILER_TYPE} == clang
MAKE_ARGS+=     CFLAGS="-Wno-error -fbracket-depth=512" CXXFLAGS="-Wno-error -fbracket-depth=512"
.endif

MISC_DOCS=	license.txt readme.txt release.txt

.if ${PORT_OPTIONS:MPURE}
PREREQUISITES=		expat \
			zlib \
			libelf \
			gmp \
			mpfr \
			mpc \
			isl \
			cloog
ISL_CHECK_VERSION=
.else
PREREQUISITES=
ISL_CHECK_VERSION=	--disable-isl-version-check
.endif

.if ${PORT_OPTIONS:MPYGDB}
_pygdb=		build-pygdb
.else
_pygdb=
.endif

COMMON_GDB_CONFIGURE_ARGS= \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-nls \
	 --disable-sim \
	 --disable-gas \
	 --disable-binutils \
	 --disable-ld \
	 --disable-gprof \
	 --with-libexpat \
	 --with-libexpat-prefix=${WORLD_LIB} \
	 --with-lzma=no \
	 --with-system-gdbinit=${INTERIM_PREFIX}/xxxx/${TARGET}/lib/gdbinit \
	 --with-lzma=no \
	 --with-gdb-datadir='$${prefix}/${TARGET}/share/gdb' \
	 --with-pkgversion="${PKGVERSION}"

ALL_BUILD=	build-binutils \
		build-gcc-first \
		build-newlib \
		build-newlib-nano \
		build-gcc-final \
		build-libstdcxx \
		build-gdb  \
		${_pygdb} \
		install-samples \
		install-misc \
		strip-binaries \
		strip-target-libraries

.PHONY: ${PREREQUISITES} ${ALL_BUILD}

all: ${PREREQUISITES} ${ALL_BUILD}

expat:
	@${ECHO_MSG} "====>  Build expat (log file: ${WRKDIR}/expat.log)"
	@${RM} -rf ${BUILD_PREFIX}/expat > ${WRKDIR}/expat.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/expat >> ${WRKDIR}/expat.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/expat && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/expat-${BUNDLED_VERSION_EXPAT}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/expat.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/expat all ${MAKE_ARGS} >> ${WRKDIR}/expat.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/expat install ${MAKE_ARGS} >> ${WRKDIR}/expat.log 2>&1

zlib:
	@${ECHO_MSG} "====>  Build zlib (log file: ${WRKDIR}/zlib.log)"
	@${RM} -rf ${BUILD_PREFIX}/zlib > ${WRKDIR}/zlib.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/zlib >> ${WRKDIR}/zlib.log 2>&1
	@${ECHO_MSG} "=====>  Copy to build dir"
	@${TAR} -cf - -C ${SRC_DIR}/zlib-${BUNDLED_VERSION_ZLIB} . | ${TAR} -xf - -C ${BUILD_PREFIX}/zlib >> ${WRKDIR}/zlib.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/zlib && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ./configure \
	 --static \
	 --prefix=${INTERIM_WORLD} >> ${WRKDIR}/zlib.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/zlib ${MAKE_ARGS} >> ${WRKDIR}/zlib.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/zlib install ${MAKE_ARGS} >> ${WRKDIR}/zlib.log 2>&1

libelf:
	@${ECHO_MSG} "====>  Build libelf (log file: ${WRKDIR}/libelf.log)"
	@${RM} -rf ${BUILD_PREFIX}/libelf > ${WRKDIR}/libelf.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/libelf >> ${WRKDIR}/libelf.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/libelf && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/libelf-${BUNDLED_VERSION_LIBELF}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/libelf.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/libelf all ${MAKE_ARGS} >> ${WRKDIR}/libelf.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/libelf install ${MAKE_ARGS} >> ${WRKDIR}/libelf.log 2>&1

gmp:
	@${ECHO_MSG} "====>  Build gmp (log file: ${WRKDIR}/gmp.log)"
	@${RM} -rf ${BUILD_PREFIX}/gmp > ${WRKDIR}/gmp.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gmp >> ${WRKDIR}/gmp.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gmp && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gmp-${BUNDLED_VERSION_GMP}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --enable-cxx \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/gmp.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gmp all ${MAKE_ARGS} >> ${WRKDIR}/gmp.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gmp install ${MAKE_ARGS} >> ${WRKDIR}/gmp.log 2>&1

mpfr:
	@${ECHO_MSG} "====>  Build mpfr (log file: ${WRKDIR}/mpfr.log)"
	@${RM} -rf ${BUILD_PREFIX}/mpfr > ${WRKDIR}/mpfr.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/mpfr >> ${WRKDIR}/mpfr.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/mpfr && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/mpfr-${BUNDLED_VERSION_MPFR}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --with-gmp=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/mpfr.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/mpfr all ${MAKE_ARGS} >> ${WRKDIR}/mpfr.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/mpfr install ${MAKE_ARGS} >> ${WRKDIR}/mpfr.log 2>&1

mpc:
	@${ECHO_MSG} "====>  Build mpc (log file: ${WRKDIR}/mpc.log)"
	@${RM} -rf ${BUILD_PREFIX}/mpc > ${WRKDIR}/mpc.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/mpc >> ${WRKDIR}/mpc.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/mpc && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/mpc-${BUNDLED_VERSION_MPC}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --with-gmp=${INTERIM_WORLD} \
	 --with-mpfr=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/mpc.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/mpc all ${MAKE_ARGS} >> ${WRKDIR}/mpc.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/mpc install ${MAKE_ARGS} >> ${WRKDIR}/mpc.log 2>&1

isl:
	@${ECHO_MSG} "====>  Build isl (log file: ${WRKDIR}/isl.log)"
	@${RM} -rf ${BUILD_PREFIX}/isl > ${WRKDIR}/isl.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/isl >> ${WRKDIR}/isl.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/isl && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/isl-${BUNDLED_VERSION_ISL}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --with-gmp-prefix=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/isl.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/isl all ${MAKE_ARGS} >> ${WRKDIR}/isl.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/isl install ${MAKE_ARGS} >> ${WRKDIR}/isl.log 2>&1

cloog:
	@${ECHO_MSG} "====>  Build cloog (log file: ${WRKDIR}/cloog.log)"
	@${RM} -rf ${BUILD_PREFIX}/cloog > ${WRKDIR}/cloog.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/cloog >> ${WRKDIR}/cloog.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/cloog && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/cloog-${BUNDLED_VERSION_CLOOG}/configure \
	 --prefix=${INTERIM_WORLD} \
	 --with-bits=gmp \
	 --with-gmp-prefix=${INTERIM_WORLD} \
	 --with-isl-prefix=${INTERIM_WORLD} \
	 --disable-shared \
	 --disable-nls >> ${WRKDIR}/cloog.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/cloog all ${MAKE_ARGS} >> ${WRKDIR}/cloog.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/cloog install ${MAKE_ARGS} >> ${WRKDIR}/cloog.log 2>&1

build-binutils:
	@${ECHO_MSG} "====>  Build binutils (log file: ${WRKDIR}/binutils.log)"
	@${RM} -rf ${BUILD_PREFIX}/binutils > ${WRKDIR}/binutils.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/binutils >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/binutils && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/binutils/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-nls \
	 --enable-interwork \
	 --enable-plugins \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/binutils all ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/binutils install ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Prepare working area for library builds"
	@${MKDIR} ${BUILD_PREFIX}/target-libs >> ${WRKDIR}/binutils.log 2>&1
	@${TAR} -cf - -C ${INTERIM_PREFIX} . | ${TAR} -xf - -C ${BUILD_PREFIX}/target-libs >> ${WRKDIR}/binutils.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/binutils html ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/binutils install-html ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/binutils pdf ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/binutils install-pdf ${MAKE_ARGS} >> ${WRKDIR}/binutils.log 2>&1
.endif
	@${ECHO_MSG} "=====>  Cleanup installation"
	@${RM} -rf ${INTERIM_PREFIX}/lib >> ${WRKDIR}/binutils.log 2>&1

build-gcc-first:
	@${ECHO_MSG} "====>  Build preliminary gcc (log file: ${WRKDIR}/gcc-first.log)"
	@${RM} -rf ${BUILD_PREFIX}/gcc-first > ${WRKDIR}/gcc-first.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-first >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-first && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --libexecdir=${INTERIM_PREFIX}/lib \
	 --with-gmp=${WORLD_LIB} \
	 --with-mpfr=${WORLD_LIB} \
	 --with-mpc=${WORLD_LIB} \
	 --with-isl=${WORLD_LIB} \
	 ${ISL_CHECK_VERSION} \
	 --with-cloog=${WORLD_LIB} \
	 --with-libelf=${WORLD_LIB} \
	 --enable-languages=c \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-newlib \
	 --without-headers \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-first all ${MAKE_ARGS} >> ${WRKDIR}/gcc-first.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-first install-gcc ${MAKE_ARGS} >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/bin/${TARGET}-gccbug >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/lib/libiberty.a >> ${WRKDIR}/gcc-first.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include >> ${WRKDIR}/gcc-first.log 2>&1

build-newlib:
	@${ECHO_MSG} "====>  Build newlib (log file: ${WRKDIR}/newlib.log)"
	@${RM} -rf ${BUILD_PREFIX}/newlib > ${WRKDIR}/newlib.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/newlib >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/newlib && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" CFLAGS_FOR_TARGET="-g -O2 -ffunction-sections -fdata-sections" \
	  ${SRC_DIR}/newlib/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --enable-newlib-io-long-long \
	 --enable-newlib-register-fini \
	 --disable-newlib-supplied-syscalls \
	 --disable-nls >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/newlib all >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${MAKE_CMD} -C ${BUILD_PREFIX}/newlib install >> ${WRKDIR}/newlib.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/newlib html ${MAKE_ARGS} >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MKDIR} ${DOC_PREFIX}/html/libc >> ${WRKDIR}/newlib.log 2>&1
	@${TAR} -cf - -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc/libc.html . | ${TAR} -xf - -C ${DOC_PREFIX}/html/libc >> ${WRKDIR}/newlib.log 2>&1
	@${MKDIR} ${DOC_PREFIX}/html/libm >> ${WRKDIR}/newlib.log 2>&1
	@${TAR} -cf - -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm/libm.html . | ${TAR} -xf - -C ${DOC_PREFIX}/html/libm >> ${WRKDIR}/newlib.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation (ignore errors)"
	@-${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc pdf ${MAKE_ARGS} >> ${WRKDIR}/newlib.log 2>&1
	@-${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm pdf ${MAKE_ARGS} >> ${WRKDIR}/newlib.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${CP} -f ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libc/libc.pdf ${DOC_PREFIX}/pdf/libc.pdf >> ${WRKDIR}/newlib.log 2>&1
	@${CP} -f ${BUILD_PREFIX}/newlib/${TARGET}/newlib/libm/libm.pdf ${DOC_PREFIX}/pdf/libm.pdf >> ${WRKDIR}/newlib.log 2>&1
.endif

build-newlib-nano:
	@${ECHO_MSG} "====>  Build newlib-nano (log file: ${WRKDIR}/newlib-nano.log)"
	@${RM} -rf ${BUILD_PREFIX}/newlib-nano > ${WRKDIR}/newlib-nano.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/newlib-nano >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/newlib-nano && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" CFLAGS_FOR_TARGET="-g -Os -ffunction-sections -fdata-sections" \
	  ${SRC_DIR}/newlib/configure \
	 --target=${TARGET} \
	 --prefix=${BUILD_PREFIX}/target-libs \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --disable-newlib-supplied-syscalls    \
	 --enable-newlib-reent-small           \
	 --disable-newlib-fvwrite-in-streamio  \
	 --disable-newlib-fseek-optimization   \
	 --disable-newlib-wide-orient          \
	 --enable-newlib-nano-malloc           \
	 --disable-newlib-unbuf-stream-opt     \
	 --enable-lite-exit                    \
	 --enable-newlib-global-atexit         \
	 --enable-newlib-nano-formatted-io     \
	 --disable-nls >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/newlib-nano all >> ${WRKDIR}/newlib-nano.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} PATH="${INTERIM_PREFIX}/bin:${PATH}" ${MAKE_CMD} -C ${BUILD_PREFIX}/newlib-nano install >> ${WRKDIR}/newlib-nano.log 2>&1

build-gcc-final:
	@${ECHO_MSG} "====>  Build final gcc and g++ (log file: ${WRKDIR}/gcc-final.log)"
	@${RM} -f ${INTERIM_PREFIX}/${TARGET}/usr > ${WRKDIR}/gcc-final.log 2>&1
	@${LN} -s . ${INTERIM_PREFIX}/${TARGET}/usr >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -rf ${BUILD_PREFIX}/gcc-final >> ${WRKDIR}/gcc-final.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-final >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-final && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${INTERIM_PREFIX} \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --libexecdir=${INTERIM_PREFIX}/lib \
	 --with-gmp=${WORLD_LIB} \
	 --with-mpfr=${WORLD_LIB} \
	 --with-mpc=${WORLD_LIB} \
	 --with-isl=${WORLD_LIB} \
	 ${ISL_CHECK_VERSION} \
	 --with-cloog=${WORLD_LIB} \
	 --with-libelf=${WORLD_LIB} \
	 --enable-languages=c,c++ \
	 --enable-plugins \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-newlib \
	 --with-headers=yes \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${INTERIM_PREFIX}/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-final INHIBIT_LIBC_CFLAGS="-DUSE_TM_CLONE_REGISTRY=0" all ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-final install ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-final html ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-final install-html ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-final pdf ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-final install-pdf ${MAKE_ARGS} >> ${WRKDIR}/gcc-final.log 2>&1
.endif
	@${ECHO_MSG} "=====>  Cleanup installation"
	@${RM} -f ${INTERIM_PREFIX}/bin/${TARGET}-gccbug >> ${WRKDIR}/gcc-final.log 2>&1
	@${FIND} ${INTERIM_PREFIX}/${TARGET}/lib -name libiberty.a -delete >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/lib/libiberty.a >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include >> ${WRKDIR}/gcc-final.log 2>&1
	@${RM} -f ${INTERIM_PREFIX}/${TARGET}/usr >> ${WRKDIR}/gcc-final.log 2>&1

build-libstdcxx:
	@${ECHO_MSG} "====>  Build size-optimized C++ runtime (log file: ${WRKDIR}/gcc-size-libstdcxx.log)"
	@${RM} -f ${BUILD_PREFIX}/target-libs/${TARGET}/usr > ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${LN} -s . ${BUILD_PREFIX}/target-libs/${TARGET}/usr >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${RM} -rf ${BUILD_PREFIX}/gcc-size-libstdcxx >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gcc-size-libstdcxx >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gcc-size-libstdcxx && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gcc/configure \
	 --target=${TARGET} \
	 --prefix=${BUILD_PREFIX}/target-libs \
	 --infodir=${DOC_PREFIX}/info \
	 --mandir=${DOC_PREFIX}/man \
	 --htmldir=${DOC_PREFIX}/html \
	 --pdfdir=${DOC_PREFIX}/pdf \
	 --with-gmp=${WORLD_LIB} \
	 --with-mpfr=${WORLD_LIB} \
	 --with-mpc=${WORLD_LIB} \
	 --with-isl=${WORLD_LIB} \
	 ${ISL_CHECK_VERSION} \
	 --with-cloog=${WORLD_LIB} \
	 --with-libelf=${WORLD_LIB} \
	 --enable-languages=c++ \
	 --disable-decimal-float \
	 --disable-libffi \
	 --disable-libgomp \
	 --disable-libmudflap \
	 --disable-libquadmath \
	 --disable-libssp \
	 --disable-libstdcxx-pch \
	 --disable-nls \
	 --disable-shared \
	 --disable-threads \
	 --disable-tls \
	 --with-gnu-as \
	 --with-gnu-ld \
	 --with-newlib \
	 --with-headers=yes \
	 --with-python-dir=share/gcc-${TARGET} \
	 --with-sysroot=${BUILD_PREFIX}/target-libs/${TARGET} \
	 --with-multilib-list=${MULTILIB_LIST} \
	 --with-pkgversion="${PKGVERSION}" >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gcc-size-libstdcxx \
	 CXXFLAGS_FOR_TARGET="-g -Os -ffunction-sections -fdata-sections -fno-exceptions" all-target-libstdc++-v3 ${MAKE_ARGS} >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Install into intermediate directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gcc-size-libstdcxx install-target-libstdc++-v3 ${MAKE_ARGS} >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1
	@${ECHO_MSG} "=====>  Copy all target libraries into stage directory"
	@for multilib in $$(${INTERIM_PREFIX}/bin/${TARGET}-gcc -print-multi-lib) ; do \
	  multilib_dir=$${multilib%%;*} ; \
	  for srclib in libstdc++.a libsupc++.a libc.a libg.a librdimon.a nano.specs rdimon.specs nosys.specs ; do \
	    dstlib=$$(echo "$${srclib}" | ${SED} 's/\.a$$/_nano.a/') ; \
	    ${CP} -f ${BUILD_PREFIX}/target-libs/${TARGET}/lib/$${multilib_dir}/$${srclib} ${INTERIM_PREFIX}/${TARGET}/lib/$${multilib_dir}/$${dstlib} ; \
	  done ; \
	  ${CP} -f ${BUILD_PREFIX}/target-libs/${TARGET}/lib/$${multilib_dir}/*crt0.o  ${INTERIM_PREFIX}/${TARGET}/lib/$${multilib_dir}/ ; \
	 done >> ${WRKDIR}/gcc-size-libstdcxx.log 2>&1

build-gdb:
	@${ECHO_MSG} "====>  Build gdb (log file: ${WRKDIR}/gdb.log)"
	@${RM} -rf ${BUILD_PREFIX}/gdb > ${WRKDIR}/gdb.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/gdb >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/gdb && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gdb/configure \
	 ${COMMON_GDB_CONFIGURE_ARGS} \
	 --with-python=no >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/gdb all ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb install ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb html ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb install-html ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb pdf ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb install-pdf ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
.endif

build-pygdb:
	@${ECHO_MSG} "====>  Build py-gdb (log file: ${WRKDIR}/py-gdb.log)"
	@${RM} -rf ${BUILD_PREFIX}/py-gdb > ${WRKDIR}/py-gdb.log 2>&1
	@${MKDIR} ${BUILD_PREFIX}/py-gdb >> ${WRKDIR}/py-gdb.log 2>&1
	@${ECHO_MSG} "=====>  Configure"
	@cd ${BUILD_PREFIX}/py-gdb && \
	 ${MAKE_ENV} ${CONFIGURE_ENV} ${SRC_DIR}/gdb/configure \
	 ${COMMON_GDB_CONFIGURE_ARGS} \
	 --with-python=${PYTHON_CMD} \
	 --program-prefix=${TARGET}- --program-suffix=-py >> ${WRKDIR}/py-gdb.log 2>&1
	@${ECHO_MSG} "=====>  Build"
	@${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${BUILD_PREFIX}/py-gdb all ${MAKE_ARGS} >> ${WRKDIR}/py-gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/py-gdb install ${MAKE_ARGS} >> ${WRKDIR}/py-gdb.log 2>&1
	@${RM} -rf ${INTERIM_PREFIX}/include
.if ${PORT_OPTIONS:MHTML} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build HTML documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb html ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install HTML documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb install-html ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
.endif
.if ${PORT_OPTIONS:MPDF} && ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "=====>  Build PDF documentation"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb pdf ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
	@${ECHO_MSG} "=====>  Install PDF documentation into stage directory"
	@${MAKE_ENV} ${MAKE_CMD} -C ${BUILD_PREFIX}/gdb install-pdf ${MAKE_ARGS} >> ${WRKDIR}/gdb.log 2>&1
.endif

install-samples:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "====>  Install samples into stage directory"
	@${TAR} -xf ${SRC_DIR}/samples.tar.bz2 -C ${INTERIM_PREFIX}/share/gcc-${TARGET}
.else
	@${DO_NADA}
.endif

install-misc:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "====>  Install misc. files into stage directory"
	@for doc in ${MISC_DOCS} ; do \
	 ${CP} -f ${WRKDIR}/${ORIGINAL_PACKAGE_NAME}/$${doc} ${DOC_PREFIX}/ ; \
	 done
.else
	@${DO_NADA}
.endif

strip-binaries:
	@${ECHO_MSG} "====>  Strip host binaries"
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/bin -type f -name ${TARGET}-\*) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/${TARGET}/bin -type f -maxdepth 1 -mindepth 1) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done
	@for bin in $$(${FIND} ${INTERIM_PREFIX}/lib/gcc/${TARGET}/${GCC_VERSION} -perm +111 -and ! -type d) ; do \
	   if ! ${FILE} $$bin | ${GREP} -qs ': ELF' ; then continue ; fi ; \
	   ${STRIP_CMD} $${bin} ; \
	 done

strip-target-libraries:
	@${ECHO_MSG} "====>  Strip target libraries"
	@for target in $$(${FIND} ${INTERIM_PREFIX}/${TARGET}/lib ${INTERIM_PREFIX}/lib/gcc/${TARGET}/${GCC_VERSION} -type f -name \*.a -o -name \*.o) ; do \
	   ${INTERIM_PREFIX}/bin/${TARGET}-objcopy -R .comment -R .note -R .debug_info -R .debug_aranges -R .debug_pubnames -R .debug_pubtypes -R .debug_abbrev -R .debug_line -R .debug_str -R .debug_ranges -R .debug_loc $${target} ; \
	done
	@${ECHO_MSG} "====>  Remove *.la files and other leftovers"
	@${FIND} ${INTERIM_PREFIX} -name \*.la -delete
	@${RM} -f ${INTERIM_PREFIX}/lib/charset.alias ${INTERIM_PREFIX}/lib/libiberty.a
