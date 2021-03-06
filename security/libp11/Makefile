# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libp11
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	SF/opensc/${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Small layer on top of PKCS\#11 API

LICENSE=	LGPL21

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA install-dist_docDATA|install-data-am: install-dist_docDATA|' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
