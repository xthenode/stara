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
#   File: libstara.pri
#
# Author: $author$
#   Date: 3/10/2020
#
# QtCreator .pri file for stara library libstara
########################################################################

########################################################################
# libstara

# libstara TARGET
#
libstara_TARGET = stara
libstara_TEMPLATE = lib
libstara_CONFIG += staticlib

# libstara INCLUDEPATH
#
libstara_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# libstara DEFINES
#
libstara_DEFINES += \
$${stara_DEFINES} \

########################################################################
# libstara OBJECTIVE_HEADERS
#
#libstara_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# libstara OBJECTIVE_SOURCES
#
#libstara_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# libstara HEADERS
#
libstara_HEADERS += \
$${STARA_SRC}/xos/lib/stara/version.hpp \

# libstara SOURCES
#
libstara_SOURCES += \
$${STARA_SRC}/xos/lib/stara/version.cpp \

########################################################################
