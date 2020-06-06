########################################################################
# Copyright (c) 1988-2020 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 3/27/2020
#
# generic Gcc Makefile for stara
########################################################################

OTHER_VERSION_PKG = ${PKG}
OTHER_DEPENDS_PKG = ${PKG}/..
OTHER_THIRDPARTY_NAME = thirdparty
OTHER_THIRDPARTY_VERSION_PKG = ${OTHER_VERSION_PKG}/${OTHER_THIRDPARTY_NAME}

STARA_PKG = ${PKG}
STARA_SRC = ${STARA_PKG}/source
STARA_BLD = ${STARA_PKG}/${BLD}/${BUILD_TYPE}
STARA_LIB = ${STARA_BLD}/lib
STARA_BIN = ${STARA_BLD}/bin

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = ${NADIR_VERSION_MAJOR}.${NADIR_VERSION_MINOR}.${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = ${NADIR_NAME}
NADIR_VERSION_DIR = ${NADIR_GROUP}/${NADIR_NAME}-${NADIR_VERSION}
NADIR_DEPENDS_DIR = ${NADIR_NAME}

#NADIR_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${NADIR_VERSION_DIR}
#NADIR_PKG = ${OTHER_VERSION_PKG}/${NADIR_VERSION_DIR}
NADIR_PKG = ${OTHER_DEPENDS_PKG}/${NADIR_DEPENDS_DIR}
#NADIR_SRC = ${NADIR_PKG}/source/${BN_GROUP}/${BN_NAME}
NADIR_SRC = ${NADIR_PKG}/source
NADIR_BLD = ${NADIR_PKG}/${BLD}/${BUILD_TYPE}
NADIR_LIB = ${NADIR_BLD}/lib
NADIR_BIN = ${NADIR_BLD}/bin

# nadir USRDEFINES
#
nadir_USRDEFINES += \

# nadir USRINCLUDES
#
nadir_USRINCLUDES += \
-I${NADIR_SRC} \

# nadir USRCXXFLAGS
#
nadir_USRCXXFLAGS += \

# nadir USRLIBDIRS
#
nadir_USRLIBDIRS += \
-L${NADIR_LIB} \

# nadir LIBS
#
nadir_LIBS += \
-lnadir \

# nadir FRAMEWORKS
#
nadir_FRAMEWORKS += \

########################################################################
# cifra
CIFRA_VERSION_MAJOR = 0
CIFRA_VERSION_MINOR = 0
CIFRA_VERSION_RELEASE = 0
CIFRA_VERSION = ${CIFRA_VERSION_MAJOR}.${CIFRA_VERSION_MINOR}.${CIFRA_VERSION_RELEASE}
CIFRA_NAME = cifra
CIFRA_GROUP = ${CIFRA_NAME}
CIFRA_VERSION_DIR = ${CIFRA_GROUP}/${CIFRA_NAME}-${CIFRA_VERSION}
CIFRA_DEPENDS_DIR = ${CIFRA_NAME}

#CIFRA_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${CIFRA_VERSION_DIR}
#CIFRA_PKG = ${OTHER_VERSION_PKG}/${CIFRA_VERSION_DIR}
CIFRA_PKG = ${OTHER_DEPENDS_PKG}/${CIFRA_DEPENDS_DIR}
#CIFRA_SRC = ${CIFRA_PKG}/source/${BN_GROUP}/${BN_NAME}
CIFRA_SRC = ${CIFRA_PKG}/source
CIFRA_BLD = ${CIFRA_PKG}/${BLD}/${BUILD_TYPE}
CIFRA_LIB = ${CIFRA_BLD}/lib
CIFRA_BIN = ${CIFRA_BLD}/bin

# cifra USRDEFINES
#
cifra_USRDEFINES += \

# cifra USRINCLUDES
#
cifra_USRINCLUDES += \
-I${CIFRA_SRC} \

# cifra USRCXXFLAGS
#
cifra_USRCXXFLAGS += \

# cifra USRLIBDIRS
#
cifra_USRLIBDIRS += \
-L${CIFRA_LIB} \

# cifra LIBS
#
cifra_LIBS += \
-lcifra \

# cifra FRAMEWORKS
#
cifra_FRAMEWORKS += \

########################################################################
# rete
RETE_VERSION_MAJOR = 0
RETE_VERSION_MINOR = 0
RETE_VERSION_RELEASE = 0
RETE_VERSION = ${RETE_VERSION_MAJOR}.${RETE_VERSION_MINOR}.${RETE_VERSION_RELEASE}
RETE_NAME = rete
RETE_GROUP = ${RETE_NAME}
RETE_VERSION_DIR = ${RETE_GROUP}/${RETE_NAME}-${RETE_VERSION}
RETE_DEPENDS_DIR = ${RETE_NAME}

#RETE_PKG = ${OTHER_THIRDPARTY_VERSION_PKG}/${RETE_VERSION_DIR}
#RETE_PKG = ${OTHER_VERSION_PKG}/${RETE_VERSION_DIR}
RETE_PKG = ${OTHER_DEPENDS_PKG}/${RETE_DEPENDS_DIR}
#RETE_SRC = ${RETE_PKG}/source/${BN_GROUP}/${BN_NAME}
RETE_SRC = ${RETE_PKG}/source
RETE_BLD = ${RETE_PKG}/${BLD}/${BUILD_TYPE}
RETE_LIB = ${RETE_BLD}/lib
RETE_BIN = ${RETE_BLD}/bin

# rete USRDEFINES
#
rete_USRDEFINES += \

# rete USRINCLUDES
#
rete_USRINCLUDES += \
-I${RETE_SRC} \

# rete USRCXXFLAGS
#
rete_USRCXXFLAGS += \

# rete USRLIBDIRS
#
rete_USRLIBDIRS += \
-L${RETE_LIB} \

# rete LIBS
#
rete_LIBS += \
-lrete \

# rete FRAMEWORKS
#
rete_FRAMEWORKS += \


########################################################################
# stara

# stara USRDEFINES
#
stara_USRDEFINES += \
${nadir_USRDEFINES} \
${cifra_USRDEFINES} \
${rete_USRDEFINES} \
${build_stara_USRDEFINES} \

# stara USRINCLUDES
#
stara_USRINCLUDES += \
-I${STARA_SRC} \
${rete_USRINCLUDES} \
${cifra_USRINCLUDES} \
${nadir_USRINCLUDES} \
${build_stara_USRINCLUDES} \

# stara USRCXXFLAGS
#
stara_USRCXXFLAGS += \
${nadir_USRCXXFLAGS} \
${cifra_USRCXXFLAGS} \
${rete_USRCXXFLAGS} \
${build_stara_USRCXXFLAGS} \

# stara USRLIBDIRS
#
stara_USRLIBDIRS += \
-L${STARA_LIB} \
${rete_USRLIBDIRS} \
${cifra_USRLIBDIRS} \
${nadir_USRLIBDIRS} \
${build_stara_USRLIBDIRS} \

# stara LIBS
#
stara_LIBS += \
-lstara \
${rete_LIBS} \
${cifra_LIBS} \
${nadir_LIBS} \
${build_stara_LIBS} \

########################################################################

