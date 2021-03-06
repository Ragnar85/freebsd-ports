# $FreeBSD$

PORTNAME=	rlvm
PORTVERSION=	0.14.0.20150223
PORTREVISION=	1
CATEGORIES=	devel games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	RealLive virtual machine clone

LICENSE=	GPLv2 GPLv3 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/utf8.h:${PORTSDIR}/devel/utf8cpp
LIB_DEPENDS=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libboost_serialization.so:${PORTSDIR}/devel/boost-libs \
		libguichan.so:${PORTSDIR}/devel/guichan \
		libGLEW.so:${PORTSDIR}/graphics/glew
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	eglaysher
GH_TAGNAME=	${GH_COMMIT} # release-${PORTVERSION}
GH_COMMIT=	589e3d2

USES=		compiler:c++11-lib pkgconfig scons
USE_GL=		yes
USE_GNOME=	gtk20
USE_SDL=	image mixer ttf
EXCLUDE=	GLEW SDL_image SDL_mixer SDL_ttf gmock gtest guichan \
		luabind utf8cpp # leaving only pygame, xclannad, *.cpp
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude vendor/,}
MAKE_ARGS=	VERBOSE=1
INSTALLS_ICONS=	yes
PORTDOCS=	AUTHORS.TXT NEWS.TXT README.md STATUS.TXT notes

CFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (gtk deps)

OPTIONS_DEFINE=	DEBUG DOCS NLS TEST
OPTIONS_GROUP=	JAPANESE_FONT
OPTIONS_GROUP_JAPANESE_FONT=KOCHI MONA SAZANAMI
OPTIONS_SUB=	yes

JAPANESE_FONT_DESC=msgothic.ttc alternatives with verified metrics (unless --font)
KOCHI_DESC=	kochi-gothic-subst.ttf from japanese/font-kochi
KOCHI_RUN_DEPENDS=${LOCALBASE}/share/fonts/TTF/kochi-gothic-subst.ttf:${PORTSDIR}/japanese/font-kochi
MONA_DESC=	mona.ttf from japanese/monafonts-ttf
MONA_RUN_DEPENDS=${LOCALBASE}/share/fonts/TrueType/mona.ttf:${PORTSDIR}/japanese/monafonts-ttf
SAZANAMI_DESC=	sazanami-gothic.ttf from japanese/font-sazanami
SAZANAMI_RUN_DEPENDS=${LOCALBASE}/share/fonts/TTF/sazanami-gothic.ttf:${PORTSDIR}/japanese/font-sazanami

DEBUG_MAKE_ARGS_OFF=--release
NLS_USES=	gettext
NLS_EXTRA_PATCHES_OFF=${FILESDIR}/extra-patch-disable-nls
TEST_USES=	lua:51
TEST_BUILD_DEPENDS=googletest>=1.7.0:${PORTSDIR}/devel/googletest \
		googlemock>=1.7.0:${PORTSDIR}/devel/googlemock \
		luabind>0:${PORTSDIR}/devel/luabind
TEST_EXTRA_PATCHES_OFF=${FILESDIR}/extra-patch-disable-test

.include <bsd.port.options.mk>

post-patch:
	@${GREP} -Flr 'utf8cpp/' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-i .bak.utf8cpp -e 's,utf8cpp/,,'
# Default to TTF/ subdir where japanese/ fonts are often installed
	@${GREP} -Flr '/usr/share' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-i .bak.paths \
		-e 's,/usr/share,${PREFIX}/share,' \
		-e 's,truetype/ttf-dejavu,dejavu,' \
		-e 's,truetype/mona,TrueType,' \
		-e 's,truetype/[^/"]*,TTF,'

pre-install:
.if ${PORT_OPTIONS:MTEST}
	(cd ${WRKSRC} && build/${PORTNAME}_unittests)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/src/platforms/gtk/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@(cd ${WRKSRC}/resources && for f in */${PORTNAME}.png; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%/*}x$${f%/*}/apps; \
		${INSTALL_DATA} -v $$f \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/$${f%/*}x$${f%/*}/apps; \
	done)
.if ${PORT_OPTIONS:MNLS}
	(cd ${WRKSRC}/build/locale && ${COPYTREE_SHARE} \
		. ${STAGEDIR}${PREFIX}/share/locale)
.endif
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS:Nnotes}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \
		notes ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
