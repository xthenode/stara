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
#   Date: 3/31/2020
#
# generic Gcc Makefile for stara Executable xttpcatch
########################################################################


#
# target
#
xttpcatch_EXETARGET = xttpcatch

########################################################################

#
# user c++ flags
#
xttpcatch_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
xttpcatch_USRDEFINES += \
${stara_USRDEFINES} \

#
# user includes
#
xttpcatch_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
xttpcatch_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#xttpcatch_EXE_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Executable .cc sources
#
#xttpcatch_EXE_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Executable .cxx sources
#
#xttpcatch_EXE_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Executable .cpp sources
#
xttpcatch_EXE_CPP_SOURCES += \
${NADIR_SRC}/xos/base/array.cpp \
${NADIR_SRC}/xos/io/crt/file/attached.cpp \
${NADIR_SRC}/xos/io/crt/file/opened.cpp \
${NADIR_SRC}/xos/io/crt/file/writer.cpp \
${NADIR_SRC}/xos/io/crt/file/reader.cpp \
\
${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main_opt.cpp \
${STARA_SRC}/xos/app/console/network/protocol/xttp/catcher/main.cpp \
\
${NADIR_SRC}/xos/console/main_main.cpp \

#
# Executable .m sources
#
#xttpcatch_EXE_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Executable .mm sources
#
#xttpcatch_EXE_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################

#
# Executable libraries
#
xttpcatch_LIBS += \
${stara_LIBS}



