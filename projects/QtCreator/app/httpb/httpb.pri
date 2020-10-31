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
#   File: httpb.pri
#
# Author: $author$
#   Date: 9/20/2020
#
# QtCreator .pri file for stara executable httpb
########################################################################

########################################################################
# httpb

# httpb TARGET
#
httpb_TARGET = httpb

# httpb INCLUDEPATH
#
httpb_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# httpb DEFINES
#
httpb_DEFINES += \
$${stara_DEFINES} \
LOGGING_LEVELS_DEFAULT=LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_HTTP_BASE_MAIN_INSTANCE \

########################################################################
# httpb OBJECTIVE_HEADERS
#
#httpb_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# httpb OBJECTIVE_SOURCES
#
#httpb_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# httpb HEADERS
#
httpb_HEADERS += \
$${STARA_SRC}/xos/app/console/protocol/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/base/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# httpb SOURCES
#
httpb_SOURCES += \
$${STARA_SRC}/xos/app/console/http/base/main_opt.cpp \
$${STARA_SRC}/xos/app/console/http/base/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# httpb FRAMEWORKS
#
httpb_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# httpb LIBS
#
httpb_LIBS += \
$${stara_LIBS} \


