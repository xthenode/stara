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
#   File: httpb.pro
#
# Author: $author$
#   Date: 9/20/2020
#
# QtCreator .pro file for stara executable httpb
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/httpb/httpb.pri)

TARGET = $${httpb_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${httpb_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${httpb_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${httpb_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${httpb_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${httpb_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${httpb_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${httpb_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${httpb_LIBS} \
$${FRAMEWORKS} \


