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
#   File: sonycgi.pro
#
# Author: $author$
#   Date: 8/13/2020
#
# QtCreator .pro file for stara executable sonycgi
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/sonycgi/sonycgi.pri)

TARGET = $${sonycgi_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${sonycgi_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${sonycgi_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${sonycgi_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${sonycgi_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${sonycgi_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${sonycgi_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${sonycgi_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${sonycgi_LIBS} \
$${FRAMEWORKS} \


