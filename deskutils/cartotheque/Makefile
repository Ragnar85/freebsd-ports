# $FreeBSD$

PORTNAME=	cartotheque
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	deskutils gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex
DISTNAME=	Cartotheque-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Managing notes on small cards

LICENSE=	LGPL21

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
