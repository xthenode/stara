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
#   File: xttpcatch.pro
#
# Author: $author$
#   Date: 3/27/2020
#
# QtCreator .pro file for stara executable xttpcatch
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/xttpcatch/xttpcatch.pri)

TARGET = $${xttpcatch_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xttpcatch_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xttpcatch_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xttpcatch_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xttpcatch_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xttpcatch_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xttpcatch_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xttpcatch_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xttpcatch_LIBS} \
$${FRAMEWORKS} \


