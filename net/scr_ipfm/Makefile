# Created by: HSIN-HSIUNG CHANG
# $FreeBSD$

PORTNAME=	scr_ipfm
PORTVERSION=	0.64
CATEGORIES=	net
MASTER_SITES=	SF/scripfm/scripfm/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use logs generated by ipfm to show data graphically

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
USE_PHP=	yes
MYADMDIR?=	www/data/scr_ipfm
PLIST_SUB=	MYADMDIR=${MYADMDIR}
SUB_FILES=	pkg-message
PORTDOCS=	BUGS COPYING ChangeLog README README_pl THANKS TODO
OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MYADMDIR}
	${CP} -R ${WRKSRC}/[a-z]* ${STAGEDIR}${PREFIX}/${MYADMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
