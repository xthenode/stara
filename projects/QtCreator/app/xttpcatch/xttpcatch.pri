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
#   File: xttpcatch.pri
#
# Author: $author$
#   Date: 3/27/2020
#
# QtCreator .pri file for stara executable xttpcatch
########################################################################

########################################################################
# xttpcatch

# xttpcatch TARGET
#
xttpcatch_TARGET = xttpcatch

# xttpcatch INCLUDEPATH
#
xttpcatch_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# xttpcatch DEFINES
#
xttpcatch_DEFINES += \
$${stara_DEFINES} \

########################################################################
# xttpcatch OBJECTIVE_HEADERS
#
#xttpcatch_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/stara/base/Base.hh \

# xttpcatch OBJECTIVE_SOURCES
#
#xttpcatch_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/stara/base/Base.mm \

########################################################################
# xttpcatch HEADERS
#
xttpcatch_HEADERS += \
$${NADIR_SRC}/xos/base/array.hpp \
$${NADIR_SRC}/xos/io/crt/file/attached.hpp \
$${NADIR_SRC}/xos/io/crt/file/opened.hpp \
$${NADIR_SRC}/xos/io/crt/file/writer.hpp \
$${NADIR_SRC}/xos/io/crt/file/reader.hpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# xttpcatch SOURCES
#
xttpcatch_SOURCES += \
$${NADIR_SRC}/xos/base/array.cpp \
$${NADIR_SRC}/xos/io/crt/file/attached.cpp \
$${NADIR_SRC}/xos/io/crt/file/opened.cpp \
$${NADIR_SRC}/xos/io/crt/file/writer.cpp \
$${NADIR_SRC}/xos/io/crt/file/reader.cpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main_opt.cpp \
$${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# xttpcatch FRAMEWORKS
#
xttpcatch_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# xttpcatch LIBS
#
xttpcatch_LIBS += \
$${stara_LIBS} \


