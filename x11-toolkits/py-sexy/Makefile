# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sexy
PORTVERSION=	0.1.9
PORTREVISION=	7
DISTVERSIONPREFIX=	python-
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://releases.chipx86.com/libsexy/sexy-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Libsexy bindings for Python

LICENSE=	LGPL21

LIB_DEPENDS=	libsexy.so:${PORTSDIR}/x11-toolkits/libsexy

USES=		libtool pkgconfig python
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
