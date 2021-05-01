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
#   File: sony.pri
#
# Author: $author$
#   Date: 6/27/2020
#
# QtCreator .pri file for stara executable sony
########################################################################

########################################################################
# sony

# sony TARGET
#
sony_TARGET = sony

# sony INCLUDEPATH
#
sony_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# sony DEFINES
#
sony_DEFINES += \
$${stara_DEFINES} \
LOGGING_LEVELS_DEFAULT=LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_SONY_MAIN_INSTANCE \

########################################################################
# sony OBJECTIVE_HEADERS
#
#sony_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# sony OBJECTIVE_SOURCES
#
#sony_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# sony HEADERS
#
sony_HEADERS += \
$${NADIR_SRC}/xos/base/string.hpp \
\
$${RETE_SRC}/xos/app/console/network/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/server/main.hpp \
$${RETE_SRC}/xos/app/console/network/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/main.hpp \
\
$${STARA_SRC}/xos/protocol/xttp/message/part.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/header/fields.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/parts.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/line.hpp \
$${STARA_SRC}/xos/protocol/xttp/request/message.hpp \
\
$${STARA_SRC}/xos/protocol/xttp/content/json/node_type.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/boolean.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/number.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/string.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/node.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/array.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/object.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/xttp/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/main.hpp \
\
$${STARA_SRC}/xos/protocol/http/message/parts.hpp \
\
$${STARA_SRC}/xos/protocol/http/request/line.hpp \
$${STARA_SRC}/xos/protocol/http/request/message.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/main.hpp \
\
$${STARA_SRC}/xos/app/console/sony/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/main.hpp \
$${STARA_SRC}/xos/app/console/sony/main_main.hpp \

# sony SOURCES
#
sony_SOURCES += \
$${NADIR_SRC}/xos/base/string.cpp \
\
$${STARA_SRC}/xos/protocol/xttp/content/json/node_type.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/boolean.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/number.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/string.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/node.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/array.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/object.cpp \
\
$${STARA_SRC}/xos/app/console/sony/main_opt.cpp \
$${STARA_SRC}/xos/app/console/sony/main.cpp \
$${STARA_SRC}/xos/app/console/sony/main_main.cpp \

########################################################################
# sony FRAMEWORKS
#
sony_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# sony LIBS
#
sony_LIBS += \
$${stara_LIBS} \


