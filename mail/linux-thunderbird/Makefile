# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD: head/mail/linux-thunderbird/Makefile 363978 2014-08-04 09:11:25Z bapt $

PORTNAME=	thunderbird
DISTVERSION=	31.6.0
CATEGORIES=	mail news net-im ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

USES=		tar:bzip2

WANT_GTK218=	yes

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
