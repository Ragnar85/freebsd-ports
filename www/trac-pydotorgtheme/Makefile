# $FreeBSD$

PORTNAME=	pydotorgtheme
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme that emulates the look of python.org

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		trac-themeengine>=2.0:${PORTSDIR}/www/trac-themeengine

USES=		python:2
USE_PYTHON=	distutils autoplist
WRKSRC=		${WRKDIR}/${PORTNAME}

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
