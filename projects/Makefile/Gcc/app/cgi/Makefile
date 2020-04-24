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
#   Date: 4/21/2020
#
# generic Gcc Makefile for stara Executable cgi
########################################################################


#
# target
#
cgi_EXETARGET = cgi

########################################################################

#
# user c++ flags
#
cgi_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
cgi_USRDEFINES += \
${stara_USRDEFINES} \

#
# user includes
#
cgi_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
cgi_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#cgi_EXE_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Executable .cc sources
#
#cgi_EXE_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Executable .cxx sources
#
#cgi_EXE_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Executable .cpp sources
#
cgi_EXE_CPP_SOURCES += \
${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.cpp \
${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.cpp \
${NADIR_SRC}/xos/console/main_main.cpp \

#
# Executable .m sources
#
#cgi_EXE_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Executable .mm sources
#
#cgi_EXE_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################

#
# Executable libraries
#
cgi_LIBS += \
${stara_LIBS}



