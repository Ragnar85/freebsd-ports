# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	decurs
PORTVERSION=	0.55.1
PORTREVISION=	12
CATEGORIES=	x11
EXTRACT_SUFX=	_.tar.gz	# prevent clobbering of the original distfile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X11 mouse cursor editor

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkmm-2.0.so:${PORTSDIR}/x11-toolkits/gtkmm20

USE_GITHUB=	yes
GH_ACCOUNT=	danfe
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	10c5691

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	gtk20

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:' \
		${FILESDIR}/decurs.exec > ${WRKSRC}/decurs.exec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/decurs \
		${STAGEDIR}${PREFIX}/bin/decurs.bin
	${INSTALL_SCRIPT} ${WRKSRC}/decurs.exec ${STAGEDIR}${PREFIX}/bin/decurs
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.bdf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
