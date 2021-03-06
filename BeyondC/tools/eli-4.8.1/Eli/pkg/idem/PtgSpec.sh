#!/bin/sh
# $Id: PtgSpec.sh,v 2.1 2002/07/31 23:45:42 waite Exp $
# Copyright 2002, The Regents of the University of Colorado

# This file is part of the Eli translator construction system.

# Eli is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2, or (at your option) any later
# version.

# Eli is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.

# You should have received a copy of the GNU General Public License along
# with Eli; see the file COPYING.  If not, write to the Free Software
# Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

# EXEC (PtgSpec.sh) (:FILE) (+patterns)
#   => (:PtgSpec);

ODIN_base=$1;shift; ODIN_patterns=$1;shift;
touch PtgSpec

if test "$ODIN_patterns" != ''
then cat $ODIN_patterns > PtgSpec
else :
fi
