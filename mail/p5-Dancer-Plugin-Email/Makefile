# $FreeBSD$

PORTNAME=	Dancer-Plugin-Email
PORTVERSION=	1.0300
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IRONCAMEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple email handling for Dancer applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Dancer>=1.2:${PORTSDIR}/www/p5-Dancer \
		p5-Exporter-Tiny>=0:${PORTSDIR}/devel/p5-Exporter-Tiny \
		p5-Email-Sender>=0:${PORTSDIR}/mail/p5-Email-Sender \
		p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
