# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rbbr
PORTVERSION=	0.6.0
PORTREVISION=	11
CATEGORIES=	devel ruby
MASTER_SITES=	SF/ruby-gnome2/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rev/}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GTK+2-based Ruby module browser

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext
RUN_DEPENDS=	rubygem-gtk2>0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext

USES=		gettext
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	AUTHORS COPYING ChangeLog README
DOCS_JA=	COPYING.ja README.ja

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.2
BROKEN=		Does not build
.endif

.include <bsd.port.post.mk>
