# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maven3
DISTVERSION=	3.0.5
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	maven/binaries
DISTNAME=	apache-maven-${DISTVERSION}-bin

MAINTAINER=	wombat@marsupial.org
COMMENT=	Java project management tool, 3.x branch

LICENSE=	APACHE20

RUN_DEPENDS=	mvn:${PORTSDIR}/devel/maven-wrapper

USES=		cpe
CPE_PRODUCT=	maven
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/apache-maven-${DISTVERSION}
SUB_FILES=	mvn.sh
SUB_LIST=	CLASSWORLDS_JAR=plexus-classworlds-2.4.jar
INSTANCE_FILE=	030005-${PORTNAME}-${PORTVERSION}
INSTANCES_DIR=	etc/maven-wrapper/instances.d/

post-extract:
	${RM} -f ${WRKSRC}/bin/*.bat
	${ECHO_CMD} "${DATADIR}" > ${WRKSRC}/${INSTANCE_FILE}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} \
		${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -not -path "\./bin/" \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	${INSTALL_DATA} ${WRKSRC}/bin/m2.conf ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/mvn.sh ${STAGEDIR}${DATADIR}/bin/mvn
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTANCES_DIR}
	${INSTALL_DATA} ${WRKSRC}/${INSTANCE_FILE} \
		${STAGEDIR}${PREFIX}/${INSTANCES_DIR}

.include <bsd.port.mk>
