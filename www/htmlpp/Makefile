# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmlpp
PORTVERSION=	4.2a
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://legacy.imatix.com/pub/tools/
DISTNAME=	htmlp42a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script to allow easy creation of HTML from template files

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	htmlpp

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKDIR}/htmlpp ${STAGEDIR}${PREFIX}/bin/htmlpp
	${INSTALL_DATA} ${WRKDIR}/htmlpp.d ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/htmlpp.d
	(cd ${WRKDIR}; for FILE in *.pl; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.def; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${PREFIX}/bin/$${FILE}; done)
	${INSTALL_DATA} ${WRKDIR}/guru_opt.fmt ${STAGEDIR}${PREFIX}/bin/guru.fmt
	(cd ${WRKDIR}; ${MKDIR} ${STAGEDIR}${DOCSDIR}; for FILE in *.htm; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.gif; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)
	(cd ${WRKDIR}; for FILE in *.txt; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)

.include <bsd.port.mk>
