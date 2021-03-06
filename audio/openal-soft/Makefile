# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.16.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/openal-releases/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Software implementation of the OpenAL specification

LICENSE=	LGPL20

CONFLICTS=	openal-200[0-9]*

USES=		tar:bzip2 cmake compiler:c11
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DALSOFT_REQUIRE_OSS:BOOL=ON \
		-DALSOFT_REQUIRE_SOLARIS:BOOL=OFF \
		-DALSOFT_REQUIRE_SNDIO:BOOL=OFF \
		-DALSOFT_REQUIRE_QSA:BOOL=OFF \
		-DALSOFT_BACKEND_ALSA:BOOL=OFF \
		-DALSOFT_BACKEND_WAVE:BOOL=ON \
		-DALSOFT_UTILS:BOOL=ON \
		-DALSOFT_EXAMPLES:BOOL=OFF

OPTIONS_DEFINE=		FLUIDSYNTH CONFIG PORTAUDIO PULSEAUDIO
OPTIONS_SUB=		yes
CONFIG_DESC=		Install the configuration utility (needs QT)
FLUIDSYNTH_DESC=	Enable FluidSynth MIDI support

#ALSA_CMAKE_ON=		-DALSOFT_REQUIRE_ALSA:BOOL=ON
#ALSA_CMAKE_OFF=		-DALSOFT_BACKEND_ALSA:BOOL=OFF
#ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
CONFIG_CMAKE_ON=	-DALSOFT_NO_CONFIG_UTIL:BOOL=OFF
CONFIG_CMAKE_OFF=	-DALSOFT_NO_CONFIG_UTIL:BOOL=ON
CONFIG_USE=		QT4=gui
FLUIDSYNTH_CMAKE_ON=	-DALSOFT_REQUIRE_FLUIDSYNTH:BOOL=ON
FLUIDSYNTH_CMAKE_OFF=	-DALSOFT_MIDI_FLUIDSYNTH:BOOL=OFF
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
PORTAUDIO_CMAKE_ON=	-DALSOFT_REQUIRE_PORTAUDIO:BOOL=ON \
			-DPORTAUDIO_LIBRARY=${LOCALBASE}/lib/portaudio2/libportaudio.so
PORTAUDIO_LDFLAGS=	-L${LOCALBASE}/lib/portaudio2
PORTAUDIO_CMAKE_OFF=	-DALSOFT_BACKEND_PORTAUDIO:BOOL=OFF
PORTAUDIO_LIB_DEPENDS=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2
PULSEAUDIO_CMAKE_ON=	-DALSOFT_REQUIRE_PULSEAUDIO:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DALSOFT_BACKEND_PULSEAUDIO:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio

post-patch:
	@${REINPLACE_CMD} 's|/etc/openal|${ETCDIR}|' \
		${WRKSRC}/Alc/alcConfig.c \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|share/openal|${ETCDIR}|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} 's|portaudio.h|portaudio2/portaudio.h|' \
		${WRKSRC}/Alc/backends/portaudio.c

.include <bsd.port.mk>
