# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-shell-extension-coverflow
PORTVERSION=	0.0.0.20141126
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Let's you Alt-Tab windows in a cover-flow manner

BUILD_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:${PORTSDIR}/x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:${PORTSDIR}/devel/gsettings-desktop-schemas

WRKSRC=		${WRKDIR}/dmo60-CoverflowAltTab-${GH_COMMIT}

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.shell.extensions.coverflowalttab.gschema.xml

GH_ACCOUNT=	dmo60
GH_TAGNAME=	c22c771
GH_COMMIT=	c22c771
GH_PROJECT=	CoverflowAltTab

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/
		@(cd ${WRKSRC} && ${CP} CoverflowAltTab\@dmo60.de/schemas/org.gnome.shell.extensions.coverflowalttab.gschema.xml \
			${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/)
		@${RM} -fr ${WRKSRC}/CoverflowAltTab\@dmo60.de/schemas
		@(cd ${WRKSRC} && ${CP} -pPR CoverflowAltTab\@dmo60.de ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/)

.include <bsd.port.mk>
