# $FreeBSD$

PORTNAME=	activemq
PORTVERSION=	5.10.1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Messaging and Integration Patterns provider

LICENSE=	APACHE20

USES+=		cpe
CPE_VENDOR=	apache
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
MQDATA=		${PREFIX}/lib/${PORTNAME}
MQDB?=		/var/db/activemq
DATADIR=	${MQDATA}
MQUSER?=	activemq
MQGROUP?=	${MQUSER}
USERS=		${MQUSER}
GROUPS=		${MQGROUP}
CAMELVERSION=	2.13.1
SPRINGVERSION=	3.2.8
JETTYVERSION=	7.6.9.v20130131
LVDBVERSION=	0.6
LVDBJNIVERSION=	1.8

ALL_TARGET=	${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

DOC_FILES=	LICENSE NOTICE README.txt
ETC_FILES=	activemq.xml \
		broker-localhost.cert \
		broker.ks \
		broker.ts \
		client.ks \
		client.ts \
		credentials-enc.properties \
		credentials.properties \
		groups.properties \
		jetty-realm.properties \
		jetty.xml \
		jmx.access \
		jmx.password \
		log4j.properties \
		logging.properties \
		login.config \
		users.properties
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}
SUB_LIST=	ETC_FILES="${ETC_FILES}" \
		MQUSER="${MQUSER}" \
		MQGROUP="${MQGROUP}" \
		MQDB="${MQDB}"
PLIST_SUB=	MQUSER="${MQUSER}" \
		MQGROUP="${MQGROUP}" \
		MQDB="${MQDB}" \
		PORTVERSION="${PORTVERSION}" \
		CAMELVERSION="${CAMELVERSION}" \
		SPRINGVERSION="${SPRINGVERSION}" \
		JETTYVERSION="${JETTYVERSION}" \
		LVDBVERSION="${LVDBVERSION}" \
		LVDBJNIVERSION="${LVDBJNIVERSION}"

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	 @${REINPLACE_CMD} -e 's|activemq.base}/data|activemq.logs}|g' ${WRKSRC}/conf/log4j.properties

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

	@${MKDIR} ${STAGEDIR}${MQDATA} ${STAGEDIR}${MQDATA}/bin ${STAGEDIR}${ETCDIR}

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.for f in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.for f in ${PORTNAME} ${PORTNAME}-admin diag
	@cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${f} ${STAGEDIR}${MQDATA}/bin
.endfor

	@cd ${WRKSRC}/bin && ${INSTALL_DATA} activemq.jar ${STAGEDIR}${MQDATA}/bin
	@cd ${WRKSRC}/bin && ${INSTALL_DATA} wrapper.jar ${STAGEDIR}${MQDATA}/bin

.for f in webapps webapps-demo lib
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${MQDATA}
.endfor

	@${LN} -sf ${MQDB} ${STAGEDIR}${MQDATA}/data
	@${LN} -sf ${ETCDIR} ${STAGEDIR}${MQDATA}/conf
	@${LN} -sf ${EXAMPLESDIR} ${STAGEDIR}${MQDATA}/examples
	@${LN} -sf ${DOCSDIR} ${STAGEDIR}${MQDATA}/docs

.include <bsd.port.mk>
