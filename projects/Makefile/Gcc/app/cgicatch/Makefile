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
# generic Gcc Makefile for stara Executable cgicatch
########################################################################


#
# target
#
cgicatch_EXETARGET = cgicatch

########################################################################

#
# user c++ flags
#
cgicatch_USRCXXFLAGS += \
${stara_USRCXXFLAGS} \

#
# user defines
#
cgicatch_USRDEFINES += \
${stara_USRDEFINES} \

#
# user includes
#
cgicatch_USRINCLUDES += \
${stara_USRINCLUDES} \

#
# user libdirs
#
cgicatch_USRLIBDIRS += \
${stara_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#cgicatch_EXE_C_SOURCES += \
#${STARA_SRC}/stara/base/Base.c \

#
# Executable .cc sources
#
#cgicatch_EXE_CC_SOURCES += \
#${STARA_SRC}/stara/base/Base.cc \

#
# Executable .cxx sources
#
#cgicatch_EXE_CXX_SOURCES += \
#${STARA_SRC}/stara/base/Base.cxx \

#
# Executable .cpp sources
#
cgicatch_EXE_CPP_SOURCES += \
${NADIR_SRC}/xos/io/string/reader.cpp \
${NADIR_SRC}/xos/io/crt/file/attached.cpp \
\
${STARA_SRC}/xos/protocol/http/form/content.cpp \
${STARA_SRC}/xos/protocol/http/form/field.cpp \
${STARA_SRC}/xos/protocol/http/form/fields.cpp \
${STARA_SRC}/xos/protocol/http/url/encoded/form/content/type.cpp \
\
${STARA_SRC}/xos/protocol/http/cgi/version.cpp \
${STARA_SRC}/xos/protocol/http/cgi/identifier.cpp \
${STARA_SRC}/xos/protocol/http/cgi/configure/which.cpp \
${STARA_SRC}/xos/protocol/http/cgi/configure/name.cpp \
${STARA_SRC}/xos/protocol/http/cgi/configure/value.cpp \
${STARA_SRC}/xos/protocol/http/cgi/configure/setting.cpp \
${STARA_SRC}/xos/protocol/http/cgi/configure/values.cpp \
\
${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main_opt.cpp \
${STARA_SRC}/xos/app/console/network/protocol/http/cgi/catcher/main.cpp \
${NADIR_SRC}/xos/console/main_main.cpp \

#
# Executable .m sources
#
#cgicatch_EXE_M_SOURCES += \
#${STARA_SRC}/stara/base/Base.m \

#
# Executable .mm sources
#
#cgicatch_EXE_MM_SOURCES += \
#${STARA_SRC}/stara/base/Base.mm \


########################################################################

#
# Executable libraries
#
cgicatch_LIBS += \
${stara_LIBS}



