# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	texmath
PORTVERSION=	0.8.0.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between formats used to represent mathematics

LICENSE=	GPLv2

USE_CABAL=	mtl network pandoc-types>=1.12.3.3 parsec>=3 syb xml

FLAGS_DISABLE=	executable network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
