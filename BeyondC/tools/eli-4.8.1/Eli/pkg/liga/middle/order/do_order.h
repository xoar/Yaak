/* This file is part of the Eli translator construction system.

Eli is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

Eli is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with Eli; see the file COPYING.  If not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
/* $Id: do_order.h,v 4.6 1997/08/29 09:16:01 peter Exp $*/
/***************/
/* do_order.h */
/***************/

#include <stdio.h>

#ifndef DO_ORDER_H
#define DO_ORDER_H

#include "Types.h"

#ifdef __STDC__
extern void do_order(AttrEval idlstruct, FILE *ctlfile);
#else
extern void do_order();
#endif

#ifdef __STDC__
extern void do_ord_commandline(int argc, char *argv[]);
#else
extern void do_ord_commandline();
#endif

extern FILE *ProtocolFile; /* imported from expand.h */
extern FILE *InputFile;
extern FILE *OrdOptFile;
extern FILE *OutputFile;

extern FILE *BuProdFile;
extern AttrEval ISexp;

#endif

