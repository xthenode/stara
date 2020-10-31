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
#   File: xttpb.pri
#
# Author: $author$
#   Date: 9/19/2020
#
# QtCreator .pri file for stara executable xttpb
########################################################################

########################################################################
# xttpb

# xttpb TARGET
#
xttpb_TARGET = xttpb

# xttpb INCLUDEPATH
#
xttpb_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# xttpb DEFINES
#
xttpb_DEFINES += \
$${stara_DEFINES} \
LOGGING_LEVELS_DEFAULT=LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_XTTP_BASE_MAIN_INSTANCE \

########################################################################
# xttpb OBJECTIVE_HEADERS
#
#xttpb_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# xttpb OBJECTIVE_SOURCES
#
#xttpb_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# xttpb HEADERS
#
xttpb_HEADERS += \
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# xttpb SOURCES
#
xttpb_SOURCES += \
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.cpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# xttpb FRAMEWORKS
#
xttpb_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# xttpb LIBS
#
xttpb_LIBS += \
$${stara_LIBS} \


