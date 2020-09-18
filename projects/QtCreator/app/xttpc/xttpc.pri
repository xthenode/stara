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
#   File: xttpc.pri
#
# Author: $author$
#   Date: 9/16/2020
#
# QtCreator .pri file for stara executable xttpc
########################################################################

########################################################################
# xttpc

# xttpc TARGET
#
xttpc_TARGET = xttpc

# xttpc INCLUDEPATH
#
xttpc_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# xttpc DEFINES
#
xttpc_DEFINES += \
$${stara_DEFINES} \
XOS_APP_CONSOLE_XTTP_CLIENT_MAIN_INSTANCE \

########################################################################
# xttpc OBJECTIVE_HEADERS
#
#xttpc_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# xttpc OBJECTIVE_SOURCES
#
#xttpc_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# xttpc HEADERS
#
xttpc_HEADERS += \
$${STARA_SRC}/xos/protocol/xttp/request/line.hpp \
$${STARA_SRC}/xos/protocol/xttp/response/line.hpp \
\
$${STARA_SRC}/xos/protocol/http/request/line.hpp \
$${STARA_SRC}/xos/protocol/http/response/line.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/client/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# xttpc SOURCES
#
xttpc_SOURCES += \
$${STARA_SRC}/xos/app/console/xttp/client/main_opt.cpp \
$${STARA_SRC}/xos/app/console/xttp/client/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# xttpc FRAMEWORKS
#
xttpc_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# xttpc LIBS
#
xttpc_LIBS += \
$${stara_LIBS} \


