# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	freebsd
PORTVERSION=	0.9.3
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-freebsd-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900030
EXTRA_PATCHES+=	${FILESDIR}/freebsd9_patch-src-sysctl.c
.endif
.if ${OSVERSION} >= 1100002
EXTRA_PATCHES+=	${FILESDIR}/freebsd11_patch-src__.const.def \
		${FILESDIR}/freebsd11_patch-src__netstat.c
.endif

.include <bsd.port.post.mk>
