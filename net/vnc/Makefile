# Created by: msmith
# $FreeBSD$

PORTNAME=	vnc
PORTVERSION=	4.1.3
PORTREVISION=	10
CATEGORIES=	net ipv6
MASTER_SITES=	http://home.bluelife.at/ports/distfiles/${DIST_SUBDIR}/:vnc
DISTNAME=	vnc-4_1_3-unixsrc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:vnc
DIST_SUBDIR=	xc

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display X and Win32 desktops on remote X/Win32/Java displays

RUN_DEPENDS=	xorg-fonts>=7.2:${PORTSDIR}/x11-fonts/xorg-fonts \
		showrgb:${PORTSDIR}/x11/rgb \
		xauth:${PORTSDIR}/x11/xauth

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		perl5
USE_XORG=	x11 xext xpm xext xtst sm ice inputproto

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST=		${WRKDIR}/pkg-plist
CONFLICTS=	tightvnc-[0-9]* tridiavnc-[0-9]*

OPTIONS_DEFINE=	SERVER
OPTIONS_DEFAULT=	SERVER
SERVER_DESC=	Install VNC server components

.ifdef(REALVNC_BASE)
PREFIX=${REALVNC_BASE}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not compile on arm
.endif

.if ${PORT_OPTIONS:MSERVER}
MASTER_SITES+=	${MASTER_SITE_XORG:S/$/:x/}
MASTER_SITE_SUBDIR+=	4.3.0/:x
DISTFILES+=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x

.if ${OSVERSION} > 1000054
USE_GCC=	yes
MAKE_ENV=	IMAKECPP="${CPP}"
MAKE_ARGS=	AR='ar rc'
.endif

RUN_DEPENDS+=	xauth:${PORTSDIR}/x11/xauth \
		xorg-fonts-miscbitmaps>0:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
		${LOCALBASE}/share/fonts/misc/fonts.alias:${PORTSDIR}/x11-fonts/font-alias

EXTRA_PATCHES+=	${WRKSRC}/xc.patch \
		${PATCHDIR}/vnc.def-patch \
		${PATCHDIR}/FreeBSD.cf-patch \
		${PATCHDIR}/extra-patch-xfree86 \
		${PATCHDIR}/extra-patch-fix_Xvnc_no_valid_address \
		${PATCHDIR}/extra-patch-xc-config-util-printver.c

PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MSERVER}
	@cd ${WRKSRC} && ${TAR} -cf - -C ${WRKDIR} xc | ${TAR} -xf - && \
	${RM} -rf ${WRKDIR}/xc
.endif

post-patch:
.if ${PORT_OPTIONS:MSERVER}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		${WRKSRC}/xc/config/cf/vnc.def
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' -e 's|%%CXX%%|${CXX}|g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		${WRKSRC}/xc/config/cf/FreeBSD.cf
.endif

post-build:
.if ! ${PORT_OPTIONS:MSERVER}
	@${ECHO_MSG} "Skipping build of VNC server."
.else
.if ${OSVERSION} > 1000054
	cd ${WRKSRC}/xc && ${MAKE_ENV} make CC=${CC} CXX=${CXX} ${MAKE_ARGS} World
.else
	cd ${WRKSRC}/xc && make CC=${CC} CXX=${CXX} World
.endif
.endif

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if ${PORT_OPTIONS:MSERVER}
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${ECHO_CMD} lib/modules/extensions/vnc.so ; \
	fi >> ${PLIST}
.endif

do-install:
.for f in vncviewer vncpasswd vncconfig x0vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/${f}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}/${f}.man ${STAGEDIR}${PREFIX}/man/man1/${f}.1
.endfor
.if ${PORT_OPTIONS:MSERVER}
	@${REINPLACE_CMD} -e \
		's|/usr/local/vnc/classes|${DATADIR}/classes|g' \
		${WRKSRC}/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/xc/programs/Xserver/Xvnc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${STAGEDIR}${PREFIX}/bin
	@if [ -f ${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so ]; then \
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/modules/extensions ; \
		${INSTALL_PROGRAM} \
			${WRKSRC}/xc/programs/Xserver/vnc/module/vnc.so \
			${STAGEDIR}${PREFIX}/lib/modules/extensions ; \
	fi
	${INSTALL_MAN} ${WRKSRC}/xc/programs/Xserver/Xvnc.man \
		${STAGEDIR}${PREFIX}/man/man1/Xvnc.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${STAGEDIR}${PREFIX}/man/man1/vncserver.1
	${MKDIR} ${STAGEDIR}${DATADIR}/classes
	${INSTALL_DATA} ${WRKSRC}/../common/javabin/* ${STAGEDIR}${DATADIR}/classes
.endif

.include <bsd.port.post.mk>
