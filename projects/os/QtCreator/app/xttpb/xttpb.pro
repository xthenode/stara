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
#   File: xttpb.pro
#
# Author: $author$
#   Date: 9/19/2020
#
# QtCreator .pro file for stara executable xttpb
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/xttpb/xttpb.pri)

TARGET = $${xttpb_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xttpb_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xttpb_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xttpb_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xttpb_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xttpb_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xttpb_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xttpb_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xttpb_LIBS} \
$${FRAMEWORKS} \


