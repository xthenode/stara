########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: sonyd.pri
#
# Author: $author$
#   Date: 4/28/2021
#
# QtCreator .pri file for stara executable sonyd
########################################################################

########################################################################
# sonyd

# sonyd TARGET
#
sonyd_TARGET = sonyd

# sonyd INCLUDEPATH
#
sonyd_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# sonyd DEFINES
#
sonyd_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_SONY_SERVER_MAIN_INSTANCE \

########################################################################
# sonyd OBJECTIVE_HEADERS
#
#sonyd_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/xos/app/console/sonyd/main.hh \

# sonyd OBJECTIVE_SOURCES
#
#sonyd_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/xos/app/console/sonyd/main.mm \

########################################################################
# sonyd HEADERS
#
sonyd_HEADERS += \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/base/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/sony/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/server/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# sonyd SOURCES
#
sonyd_SOURCES += \
$${STARA_SRC}/xos/app/console/sony/server/main_opt.cpp \
$${STARA_SRC}/xos/app/console/sony/server/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# sonyd FRAMEWORKS
#
sonyd_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# sonyd LIBS
#
sonyd_LIBS += \
$${stara_LIBS} \


