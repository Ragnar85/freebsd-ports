# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnu-efi
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnu-efi

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	SDK for EFI applications

LICENSE=	GPLv2

BUILD_DEPENDS+=	${LOCALBASE}/bin/ar:${PORTSDIR}/devel/binutils

USES=		gmake tar:bz2
USE_GCC=	yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	"-fPIC"
CPPFLAGS+=	"-fPIC"
MAKE_ARGS+=	CC=${CC} HOSTCC=${CC} AR=${AR}
ONLY_FOR_ARCHS=	amd64

.include <bsd.port.mk>
