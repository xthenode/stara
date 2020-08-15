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
#   File: sonycgi.pri
#
# Author: $author$
#   Date: 8/13/2020
#
# QtCreator .pri file for stara executable sonycgi
########################################################################

########################################################################
# sonycgi

# sonycgi TARGET
#
sonycgi_TARGET = sonycgi

# sonycgi INCLUDEPATH
#
sonycgi_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# sonycgi DEFINES
#
sonycgi_DEFINES += \
XOS_APP_CONSOLE_SONY_CGI_MAIN_INSTANCE \
$${stara_DEFINES} \

########################################################################
# sonycgi OBJECTIVE_HEADERS
#
#sonycgi_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# sonycgi OBJECTIVE_SOURCES
#
#sonycgi_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# sonycgi HEADERS
#
sonycgi_HEADERS += \
$${RETE_SRC}/xos/app/console/network/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/sony/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/client/main.hpp \
$${STARA_SRC}/xos/app/console/sony/cgi/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/cgi/main.hpp \

# sonycgi SOURCES
#
sonycgi_SOURCES += \
$${STARA_SRC}/xos/app/console/network/protocol/xttp/client/main.cpp \

########################################################################
# sonycgi FRAMEWORKS
#
sonycgi_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# sonycgi LIBS
#
sonycgi_LIBS += \
$${stara_LIBS} \


