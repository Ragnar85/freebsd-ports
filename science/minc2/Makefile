# Created by: jbacon
# $FreeBSD$

PORTNAME=	minc
PORTVERSION=	2.2.00
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	science biology
MASTER_SITES=	GHL
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical Imaging NetCDF

LICENSE=	MIT

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5 \
		libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	BIC-MNI
GH_TAGNAME=	release-${PORTVERSION}
GH_COMMIT=	6f2f5b9

USES=		autoreconf bison gmake libtool perl5 shebangfix
SHEBANG_FILES=	progs/mincview/mincview
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes --enable-static=yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-error=return-type
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	minc-1* zh-tk-[0-9]*

pre-patch:
	@${RM} -f ${WRKSRC}/ac_config_aux/*
	@${RM} -f ${WRKSRC}/progs/minccalc/gram.[ch]
	@${RM} -f ${WRKSRC}/progs/mincgen/ncgentab.[ch]

.include <bsd.port.mk>
