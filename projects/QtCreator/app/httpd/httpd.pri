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
#   File: httpd.pri
#
# Author: $author$
#   Date: 9/8/2020
#
# QtCreator .pri file for stara executable httpd
########################################################################

########################################################################
# httpd

# httpd TARGET
#
httpd_TARGET = httpd

# httpd INCLUDEPATH
#
httpd_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# httpd DEFINES
#
httpd_DEFINES += \
$${stara_DEFINES} \
LOGGING_LEVELS_DEFAULT=LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_HTTP_SERVER_MAIN_INSTANCE \

########################################################################
# httpd OBJECTIVE_HEADERS
#
#httpd_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# httpd OBJECTIVE_SOURCES
#
#httpd_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# httpd HEADERS
#
httpd_HEADERS += \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/server/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# httpd SOURCES
#
httpd_SOURCES += \
$${STARA_SRC}/xos/app/console/http/server/main_opt.cpp \
$${STARA_SRC}/xos/app/console/http/server/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# httpd FRAMEWORKS
#
httpd_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# httpd LIBS
#
httpd_LIBS += \
$${stara_LIBS} \


