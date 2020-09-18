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
#   File: httpc.pri
#
# Author: $author$
#   Date: 9/10/2020
#
# QtCreator .pri file for stara executable httpc
########################################################################

########################################################################
# httpc

# httpc TARGET
#
httpc_TARGET = httpc

# httpc INCLUDEPATH
#
httpc_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# httpc DEFINES
#
httpc_DEFINES += \
$${stara_DEFINES} \
XOS_APP_CONSOLE_XTTP_SERVER_MAIN_INSTANCE \

########################################################################
# httpc OBJECTIVE_HEADERS
#
#httpc_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# httpc OBJECTIVE_SOURCES
#
#httpc_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# httpc HEADERS
#
httpc_HEADERS += \
$${STARA_SRC}/xos/protocol/xttp/response/reason.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/which.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/code.hpp \
$${STARA_SRC}/xos/protocol/http/response/status/reason.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# httpc SOURCES
#
httpc_SOURCES += \
$${STARA_SRC}/xos/protocol/http/response/status/reason.cpp \
\
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.cpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# httpc FRAMEWORKS
#
httpc_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# httpc LIBS
#
httpc_LIBS += \
$${stara_LIBS} \


