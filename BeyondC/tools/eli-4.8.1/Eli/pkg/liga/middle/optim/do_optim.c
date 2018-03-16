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
/* $Id: do_optim.c,v 4.9 2000/04/03 12:49:09 peter Exp $ */
/************************************************/
/* Module  : do_optim.c                         */
/************************************************/

/************************************************/
/* includes                   */
/************************************************/

#include <stdio.h>
#include "lookup_idl.h"
#include "OPTIM.h"
#include "OPTIMMacros.h"
#include <err.h>
#include "middle_mem.h"

/* Includes for option handling */
#include "option_enums.h"
#include "option_types.h"
#include "opt_input.h"

#include "optglobal.h"
#include "optfct.h"
#include "optidl.h"

#include "printerr.h"

#include "chkbu.h"
#include "optcycle.h"

#include "termtrafo.h"
#include "optbuildstr.h"
#include "optvar.h"
#include "optout.h"
#include "optgroup.h"
#include "optlifet.h"

/* for input/output */
#include "expand.h" 
    /* expand provides 
       FILE *InputFile;
       FILE *OutputFile;
       FILE *ProtocolFile;
       FILE *ExpOptFile;
       FILE *OrdOptFile;
       FILE *OptOutFile;
    */

extern FILE *optim_optionfile1;  /* defined in middle.c */
extern FILE *optim_optionfile2;  /* defined in middle.c */

/*****************************************/
/* global options              */
/*****************************************/

Boolean optimize_option = TRUE;	/* default */
Boolean protocol_option = FALSE;	/* default */
Boolean exp_incl_option = FALSE;	/* default *//* changed ! */
Boolean no_var_option = FALSE;	/* default */
Boolean no_stack_option = FALSE;	/* default */
Boolean var_group_option = FALSE;	/* default */
Boolean stack_group_option = FALSE;	/* default */
Boolean no_grouping_option = FALSE;	/* default, prevents all kinds 
                                           of grouping, overrides all
                                           other grouping options, especially
                                           those generated by expand */
Boolean group_all_option = FALSE;	/* default */
Boolean var_list_option = FALSE;	/* default */
Boolean stack_list_option = FALSE;	/* default */
Boolean tree_list_option = FALSE;	/* default */
Boolean var_group_list_option = FALSE;	/* default */
Boolean stack_group_list_option = FALSE;	/* default */
Boolean grammar_option = FALSE;	/* default */


/*****************************************/
/* global variables          */
/*****************************************/

AttrEval ligaroot;
Visit_Sequences optimroot;

extern OptCollect optim_opts;  /* defined in expand */

int max_definitions;

int neverusedcounter = 0;

int pushcounter = 0, popcounter = 0, topcounter = 0, swapcounter = 0, clobbercounter = 0;

int globvarcounter = 0, globstackcounter = 0, treeattrcounter = 0;
int vargroupcounter = 0, stackgroupcounter = 0;

int totalassigns = 0, identassigns = 0;

int inclattrcounter = 0;
int voidcounter = 0;
#ifdef __STDC__
void 
optim_deadly(char *msg)
#else
void 
optim_deadly(msg)
   char *msg;
#endif
/* print deadly error message and terminate program                      */
{
   curpos.line = 0;
   curpos.col = 0;
   message(DEADLY, msg, 0, &curpos);
}/* optim_deadly() */

#ifdef __STDC__
void 
do_optim(AttrEval idlstruct, FILE *ctlfile1, FILE *ctlfile2)
#else
void 
do_optim(idlstruct, ctlfile1, ctlfile2)
     AttrEval idlstruct;
     FILE *ctlfile1, *ctlfile2;
#endif
{
   fprintf(ProtocolFile, "============================\n");
   fprintf(ProtocolFile, "Protocol of liga phase optim\n");
   fprintf(ProtocolFile, "============================\n\n");

/* read files for option handling */

   ligaroot = idlstruct;

   optim_opts = (OptCollect) middle_tempMalloc(__FILE__,__LINE__,sizeof(struct _optcollect));
   optim_opts->opt_opts = (OptList) NULL;
   OptionInput(optim_opts, ctlfile1);
   fclose(optim_optionfile1);
   OptionInput(optim_opts, ctlfile2);
   fclose(optim_optionfile2);

   InitOptimOptions();

   max_definitions = init_did_table(ligaroot->defseq);
   if (optimize_option)
   {
      ExtendLifeOverCycles (ligaroot);

      DecideBottomUp (ligaroot);	/* set flag BottomUpVisits */

      (void) InitOptimStructure();
      (void) InitAttrArray();
      if (!exp_incl_option)
      {
	 (void) HandleExpInclOption(optimroot);
      }
      if (tree_list_option)
      {
	 (void) HandleTreeListOption(optimroot);
      }
      (void) AnalyzeAttributes(optimroot);
      if (var_list_option)
      {
	 HandleVarListOption(optimroot);
      }
      if (stack_list_option)
      {
	 HandleStackListOption(optimroot);
      }
      if (grammar_option)
      {
	 (void) GrammarLifetimeAnalysis(optimroot->tree_attrs);
      }
      (void) GroupAttributes(optimroot);
      (void) OptResultsOut(optimroot);
   } else
   {
      HandleOptimizeOption(ligaroot);
   }

   TransformTerms (ligaroot, max_definitions); 
}


