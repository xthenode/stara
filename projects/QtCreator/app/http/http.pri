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
#   File: http.pri
#
# Author: $author$
#   Date: 6/12/2020, 5/20/2021
#
# QtCreator .pri file for stara executable http
########################################################################

########################################################################
# http

# http TARGET
#
http_TARGET = http

# http INCLUDEPATH
#
http_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# http DEFINES
#
http_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_HTTP_MAIN_INSTANCE \

########################################################################
# http OBJECTIVE_HEADERS
#
#http_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# http OBJECTIVE_SOURCES
#
#http_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# http HEADERS
#
http_HEADERS += \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/main.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/http/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/client/main.hpp \
$${STARA_SRC}/xos/app/console/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/server/main.hpp \
$${STARA_SRC}/xos/app/console/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# http SOURCES
#
http_SOURCES += \
$${STARA_SRC}/xos/app/console/http/main_opt.cpp \
$${STARA_SRC}/xos/app/console/http/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# http FRAMEWORKS
#
http_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# http LIBS
#
http_LIBS += \
$${stara_LIBS} \


