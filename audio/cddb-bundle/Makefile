# $FreeBSD$

PORTNAME=	cddb
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	audio gnustep
MASTER_SITES=	SF/gsburn/cdplayer/${DISTNAME}
PKGNAMESUFFIX=	-bundle${PKGNAMESUFFIX2}
DISTNAME=	cdplayer-${CDPLAYER_VERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CDDB client bundle GNUstep

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build

CDPLAYER_VERSION=	0.5.1
WRKSRC=		${WRKDIR}/CDPlayer-${CDPLAYER_VERSION}/Cddb
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Bundles/Cddb.bundle/Cddb

.include <bsd.port.mk>
