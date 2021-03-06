# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	gtk
PORTVERSION=	2.24.27
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	2
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (previous stable version)

LICENSE=	LGPL20

USES=		tar:xz

PORTSCOUT=	limitw:0,even

.if !defined(REFERENCE_PORT)

RUN_DEPENDS+=	update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		python:${PORTSDIR}/lang/python

USES+=		gettext gmake libtool pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	atk pango gdkpixbuf2 introspection:build \
		gtk-update-icon-cache
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	xext xrender x11 xinerama xi xrandr xcursor xfixes xdamage \
		xcomposite
CONFIGURE_ARGS=	--with-xinput=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CUPS DEBUG
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
CUPS_CONFIGURE_ON=	--enable-cups=auto
CUPS_CONFIGURE_OFF=	--disable-cups
DEBUG_CONFIGURE_ON=	--enable-debug=yes

.include <bsd.port.options.mk>

PLIST_SUB+=	LIBGAILVER=18.0.1 LIBGVER=0.2400.27

post-patch:
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|file,cups|file,cups,lpr|' \
		${WRKSRC}/gtk/Makefile.in

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-xlib.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with X11 support enabled."
	@${FALSE}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/loaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-2.0/${GTK2_VERSION}/modules

.include <bsd.port.mk>

.endif
