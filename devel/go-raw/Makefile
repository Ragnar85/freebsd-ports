# $FreeBSD$

PORTNAME=	raw
PORTVERSION=	0.0.0.20130328
CATEGORIES=	devel
MASTER_SITES=	GHL
PKGNAMEPREFIX=	go-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Go library for high-level interface to unsafe and reflection packages

#LICENSE=	MIT based, but with no-evil clause

USE_GITHUB=	yes
GH_ACCOUNT=	feyeleanor
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	724aedf

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
