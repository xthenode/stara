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
#   File: Makefile
#
# Author: $author$
#   Date: 5/8/2020
#
# generic Gcc Makefile for stara Executable xttp
########################################################################


#
# target
#
xttp_EXETARGET = xttp

########################################################################

#
# user c++ flags
#
xttp_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
xttp_USRDEFINES += \
${stara_USRDEFINES} \

#
# user includes
#
xttp_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
xttp_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#xttp_EXE_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Executable .cc sources
#
#xttp_EXE_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Executable .cxx sources
#
#xttp_EXE_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Executable .cpp sources
#
xttp_EXE_CPP_SOURCES += \
${STARA_SRC}/xos/app/console/network/protocol/xttp/main_opt.cpp \
${STARA_SRC}/xos/app/console/network/protocol/xttp/main.cpp \
${NADIR_SRC}/xos/console/main_main.cpp \

#
# Executable .m sources
#
#xttp_EXE_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Executable .mm sources
#
#xttp_EXE_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################

#
# Executable libraries
#
xttp_LIBS += \
${stara_LIBS}



