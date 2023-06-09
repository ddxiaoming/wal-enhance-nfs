# SPDX-License-Identifier: BSD-3-Clause
#-------------------------------------------------------------------------------
#
# Copyright Panasas, 2012
# Contributor: Jim Lieb <jlieb@panasas.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#
#-------------------------------------------------------------------------------
# Check to see if a FSAL is on or off, and required
#
# This is to work around the broken option() system, which doesn't indicate
# whether or not an option was given on the command line, but only whether it's
# on or off (but not defaulted on or off).
#
# This consists of several macros:
#
# goption(<OPTION_NAME> <description> [ON | OFF])
#     This sets up an option, and it's default value
#
# gopt_test(<OPTION_NAME>)
#     This tests the value of <OPTION_NAME> and sets it to ON or OFF, and sets
#     <OPTION_NAME>_REQUIRED to "" or "REQUIRED"
#
# This should be used as follows:
# goption(USE_FSAL_TEST ON)
# gopt_test(USE_FSAL_TEST)
# if(USE_FSAL_TEST)
#   find_package(test ${USE_FSAL_TEST_REQUIRED})
#   if(NOT TEST_FOUND)
#     message(WARNING "libtest not found; disabling FSAL_TEST")
#     set(USE_FSAL_TEST OFF)
#   endif(NOT TEST_FOUND)
# endif(USE_FSAL_TEST)
#
# Alternatively, if your option doesn't use find_package(), the test can look like this:
# if(USE_FSAL_TEST)
#   <Whatever tests you run>
#   if(NOT TEST_FOUND)
#     if (USE_FSAL_TEST_REQUIRED)
#       message(FATAL_ERROR "libtest not found but requested on command line")
#     elseif (USE_FSAL_TEST_REQUIRED)
#       message(WARNING "libtest not found; disabling FSAL_TEST")
#       set(USE_FSAL_TEST OFF)
#     endif (USE_FSAL_TEST_REQUIRED)
#   endif(NOT TEST_FOUND)
# endif(USE_FSAL_TEST)

macro (goption OPTNAME DESC DEFVAL)
  set(${OPTNAME} DEFAULT_${DEFVAL} CACHE STRING "${DESC}")
  set_property(CACHE ${OPTNAME} PROPERTY STRINGS ON OFF)
endmacro()


macro (gopt_test OPTNAME)
  #message(WARNING "${OPTNAME}: ${${OPTNAME}}")
  if (${${OPTNAME}} MATCHES "DEFAULT_ON")
    #message(WARNING "Trying to set ${OPTNAME}: to ON")
    set(${OPTNAME} ON)
    set(${OPTNAME}_REQUIRED "")
  elseif (${${OPTNAME}} MATCHES "DEFAULT_OFF")
    #message(WARNING "Trying to set ${OPTNAME}: to OFF")
    set(${OPTNAME} OFF)
    set(${OPTNAME}_REQUIRED "")
  elseif (${OPTNAME})
    #message(WARNING "Trying to set ${OPTNAME}: to ON REQ")
    set(${OPTNAME} ON CACHE STRING "Option for ${OPTNAME}" FORCE)
    set(${OPTNAME}_REQUIRED "REQUIRED")
  else(${OPTNAME} MATCHES "OFF")
    #message(WARNING "Trying to set ${OPTNAME}: to OFF REQ")
    set(${OPTNAME} OFF CACHE STRING "Option for ${OPTNAME}" FORCE)
    set(${OPTNAME}_REQUIRED "REQUIRED")
  endif()
endmacro()
