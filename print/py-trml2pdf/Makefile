# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	trml2pdf
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	print python
MASTER_SITES=	SF/kraft/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Tiny RML2PDF easily creates PDF documents

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}reportlab1>=0:${PORTSDIR}/print/py-reportlab1

NO_BUILD=	yes

USES=		python tar:bzip2

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/trml2pdf
	@${INSTALL_SCRIPT} ${WRKSRC}/trml2pdf/* ${STAGEDIR}${PYTHON_SITELIBDIR}/trml2pdf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/rmls/ ${STAGEDIR}${EXAMPLESDIR}/rmls

.include <bsd.port.mk>
