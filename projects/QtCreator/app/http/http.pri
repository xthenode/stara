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
#   Date: 6/12/2020
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
$${RETE_SRC}/xos/network/sockets/posix/interface.hpp \
\
$${RETE_SRC}/xos/app/console/network/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/main.hpp \
\
$${STARA_SRC}/xos/protocol/http/message/header/field.hpp \
$${STARA_SRC}/xos/protocol/http/message/header/fields.hpp \
$${STARA_SRC}/xos/protocol/http/message/header/content/type.hpp \
$${STARA_SRC}/xos/protocol/http/message/header/content/length.hpp \
$${STARA_SRC}/xos/protocol/http/message/body/content.hpp \
$${STARA_SRC}/xos/protocol/http/message/parts.hpp \
\
$${STARA_SRC}/xos/protocol/http/protocol/name.hpp \
$${STARA_SRC}/xos/protocol/http/protocol/version.hpp \
$${STARA_SRC}/xos/protocol/http/protocol/identifier.hpp \
\
$${STARA_SRC}/xos/protocol/http/request/resource/which.hpp \
$${STARA_SRC}/xos/protocol/http/request/resource/identifier.hpp \
$${STARA_SRC}/xos/protocol/http/request/method/which.hpp \
$${STARA_SRC}/xos/protocol/http/request/method/name.hpp \
$${STARA_SRC}/xos/protocol/http/request/method/nameof.hpp \
$${STARA_SRC}/xos/protocol/http/request/line.hpp \
$${STARA_SRC}/xos/protocol/http/request/message.hpp \
\
$${STARA_SRC}/xos/protocol/http/response/status/which.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/code.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/codeof.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/reason.hpp \
$${STARA_SRC}/xos/protocol/http/response/line.hpp \
$${STARA_SRC}/xos/protocol/http/response/message.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main.hpp \
$${STARA_SRC}/xos/app/console/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/main.hpp \

# http SOURCES
#
http_SOURCES += \
$${STARA_SRC}/xos/protocol/http/message/header/field.cpp \
$${STARA_SRC}/xos/protocol/http/message/header/fields.cpp \
$${STARA_SRC}/xos/protocol/http/message/header/content/type.cpp \
$${STARA_SRC}/xos/protocol/http/message/header/content/length.cpp \
$${STARA_SRC}/xos/protocol/http/message/body/content.cpp \
$${STARA_SRC}/xos/protocol/http/message/parts.cpp \
\
$${STARA_SRC}/xos/protocol/http/protocol/name.cpp \
$${STARA_SRC}/xos/protocol/http/protocol/version.cpp \
$${STARA_SRC}/xos/protocol/http/protocol/identifier.cpp \
\
$${STARA_SRC}/xos/protocol/http/response/status/which.cpp \
$${STARA_SRC}/xos/protocol/http/response/status/code.cpp \
$${STARA_SRC}/xos/protocol/http/response/status/codeof.cpp \
$${STARA_SRC}/xos/protocol/http/response/status/reason.cpp \
$${STARA_SRC}/xos/protocol/http/response/line.cpp \
$${STARA_SRC}/xos/protocol/http/response/message.cpp \
\
$${STARA_SRC}/xos/app/console/http/main_opt.cpp \
$${STARA_SRC}/xos/app/console/http/main.cpp \
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


