# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.5.0
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libicuuc.so:${PORTSDIR}/devel/icu \
		libyajl.so:${PORTSDIR}/devel/yajl \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libraptor2.so:${PORTSDIR}/textproc/raptor2

GNU_CONFIGURE=	yes
USES=		autoreconf iconv libtool pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

post-patch:
	@${FIND} ${WRKSRC}/m4 -type l -delete

.include <bsd.port.mk>
