# $FreeBSD$

PORTNAME=	seafile-gui
PORTVERSION=	4.1.0
CATEGORIES=	net-mgmt
DISTNAME=	seafile-client-${PORTVERSION}

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Seafile desktop client

LICENSE=	APACHE20

LIB_DEPENDS+=	libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libsearpc.so:${PORTSDIR}/devel/libsearpc \
		libseafile.so:${PORTSDIR}/net-mgmt/seafile \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libccnet.so:${PORTSDIR}/net-mgmt/ccnet \
		libjansson.so:${PORTSDIR}/devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile-client
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	74817c4	

USES=		cmake pkgconfig
USE_QT4=	corelib dbus gui network \
		qmake_build moc_build rcc_build uic_build \
		linguist_build
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes
LRELEASE=	${PREFIX}/bin/lrelease-qt4
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=include/glib-2.0

WITH_OPENSSL_PORT=	yes
CMAKE_BUILD_TYPE=	Release

# Note that per PR 197984, cairo must be built with X11 and XCB options
# otherwise configure fails with "cairo needs x11 enabled" message

.include <bsd.port.mk>
