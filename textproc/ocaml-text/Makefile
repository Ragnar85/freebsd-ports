# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	text
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/937/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml library for dealing with text

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} \
		--destdir ${STAGEDIR}

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=		PCRE
OPTIONS_DEFAULT=	PCRE

PCRE_CONFIGURE_ENABLE=	pcre
PCRE_BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
PCRE_RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

post-patch:
	@${REINPLACE_CMD} -e 's,"install" :: findlib_name,"install" :: "-destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,' \
		${WRKSRC}/setup.ml

do-configure:
	(cd ${WRKSRC}; ocaml setup.ml -configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKSRC}; ocaml setup.ml -build)

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}
	(cd ${WRKSRC}; ocaml setup.ml -install)

.include <bsd.port.mk>
