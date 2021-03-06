# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	mupdf
PORTVERSION=	1.6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE \
		http://www.mupdf.com/download/
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Lightweight PDF viewer and toolkit

LICENSE=	AGPLv3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig2dec.so:${PORTSDIR}/graphics/jbig2dec \
		libopenjp2.so:${PORTSDIR}/graphics/openjpeg

LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	build=release prefix=${PREFIX} mandir=${PREFIX}/man verbose=yes
USES=		cpe compiler:c++11-lang pkgconfig gmake
USE_XORG=	x11 xext

CPE_VENDOR=	artifex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

OPTIONS_DEFINE=	SCROLL JS
OPTIONS_DEFAULT=SCROLL

SCROLL_DESC=	Build with scroll hacks
JS_DESC=	JavaScript support (V8 engine)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCROLL}
EXTRA_PATCHES+=	${FILESDIR}/scroll_hack-platform__x11__pdfapp.c
.endif

.if ${PORT_OPTIONS:MJS}
LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8
MAKE_ARGS+=	V8_PRESENT=1 V8LIBS=-lv8
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-pipe -O2 //' \
		-e 's|/usr/local|${LOCALBASE}|' \
		-e 's/Linux/FreeBSD/' \
		${WRKSRC}/Makerules
	@${REINPLACE_CMD} '/^CFLAGS/s|$$| -I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
	@${RM} -r ${WRKSRC}/thirdparty/*

post-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} OUT=build/pic XCFLAGS=-fpic libs)

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/pic/libmupdf.a \
		${STAGEDIR}${PREFIX}/lib/libmupdf_pic.a
	${MV} ${STAGEDIR}${PREFIX}/bin/mupdf-x11 ${STAGEDIR}${PREFIX}/bin/mupdf
.for binary in mudraw mutool mujstest mupdf mupdf-x11-curl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${binary}
.endfor

.include <bsd.port.mk>
