# SPDX-License-Identifier: LGPL-3.0-or-later
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
add_subdirectory(NFS)
add_subdirectory(XDR)
if(USE_NLM)
	add_subdirectory(NLM)
endif(USE_NLM)
if(USE_RQUOTA)
	add_subdirectory(RQUOTA)
endif(USE_RQUOTA)
if(USE_NFSACL3)
	add_subdirectory(NFSACL)
endif(USE_NFSACL3)

if(USE_9P)
  add_subdirectory(9P)
endif(USE_9P)

########### install files ###############
