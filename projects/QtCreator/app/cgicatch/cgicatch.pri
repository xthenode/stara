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
#   File: cgicatch.pri
#
# Author: $author$
#   Date: 4/1/2020
#
# QtCreator .pri file for stara executable cgicatch
########################################################################

########################################################################
# cgicatch

# cgicatch TARGET
#
cgicatch_TARGET = cgicatch

# cgicatch INCLUDEPATH
#
cgicatch_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# cgicatch DEFINES
#
cgicatch_DEFINES += \
$${stara_DEFINES} \

########################################################################
# cgicatch OBJECTIVE_HEADERS
#
#cgicatch_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# cgicatch OBJECTIVE_SOURCES
#
#cgicatch_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# cgicatch HEADERS
#
cgicatch_HEADERS += \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/io/crt/file/attached.hpp \
\
$${STARA_SRC}/xos/protocol/xttp/protocol/name.hpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/version.hpp \
$${STARA_SRC}/xos/protocol/xttp/protocol/identifier.hpp \
$${STARA_SRC}/xos/protocol/xttp/message/part.hpp \
\
$${STARA_SRC}/xos/protocol/http/cgi/name.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/version.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/identifier.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/which.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/name.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/value.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/values.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/setting.hpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.hpp \
$${NADIR_SRC}/xos/console/main_main.hpp \

# cgicatch SOURCES
#
cgicatch_SOURCES += \
$${NADIR_SRC}/xos/io/crt/file/attached.cpp \
\
$${STARA_SRC}/xos/protocol/http/cgi/version.cpp \
$${STARA_SRC}/xos/protocol/http/cgi/identifier.cpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/which.cpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/name.cpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/value.cpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/values.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/setting.cpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.cpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.cpp \
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# cgicatch FRAMEWORKS
#
cgicatch_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# cgicatch LIBS
#
cgicatch_LIBS += \
$${stara_LIBS} \


