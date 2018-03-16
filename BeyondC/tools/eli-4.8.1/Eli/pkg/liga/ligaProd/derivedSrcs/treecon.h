
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR MkSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkShieldSyms ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkShieldSym ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkShieldClause ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkShield ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSubtree ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRemoteClause ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRemoteAttr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRemoteAttrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkParams ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkParam ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkInheritSym ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkInheritSyms ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG1 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkParamsOpt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkExpression ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkExpandOpt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDependence ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDepClause ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDepAttrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRhsAttrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRemoteExpression ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDepAttr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkPlainComp ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCompute ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkComputation ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkComputations ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkChainSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkChainNames ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkChainName ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymOcc ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrNames ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrName ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrDefs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrDefId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClass ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrDefIds ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkLoop ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkExpressionDep ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDefAttr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrComp ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrUseId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAsgnTok ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAlt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSpecs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAlts ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSyntUnits ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRuleSpecId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRuleSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSyntUnit ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSyntLit ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkProduction ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCompPart ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkInheritOpt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAttrDefsOpt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolDefIds ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymClass ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkTermSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymCompSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymAttrSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIndex ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolRef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAG ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkRuleId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkTypeId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSyntId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolDefId ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3, NODEPTR _desc4));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_138 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_137 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_136 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_135 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_134 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_133 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_132 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_131 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_130 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_129 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_128 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_127 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_126 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_125 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_124 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_123 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_122 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_121 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_120 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_119 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_118 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_117 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_116 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_115 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_114 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_113 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_112 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_111 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_110 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_109 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_108 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_107 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_106 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_105 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_104 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_103 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_102 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_101 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3, NODEPTR _desc4));
extern NODEPTR Mkrule_100 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_99 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_98 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_97 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_96 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_95 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_94 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_93 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_92 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_91 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_90 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_89 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_88 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_87 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_86 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_85 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_84 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_83 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_82 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_81 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_80 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_79 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_78 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_77 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_76 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_75 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_74 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_73 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_72 ELI_ARG((POSITION *_coordref, int _TERM1, NODEPTR _desc1));
extern NODEPTR Mkrule_71 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_70 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_69 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_68 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_67 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_66 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_65 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, int _TERM2, int _TERM3));
extern NODEPTR Mkrule_64 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_63 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_62 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_61 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_60 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_59 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_58 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_57 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_56 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_55 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_54 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_53 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_52 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_51 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_50 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_49 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_48 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_47 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_46 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_45 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_44 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_43 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_42 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_41 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_40 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_39 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_38 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_37 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_36 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_35 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_34 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_33 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_32 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_31 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_30 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_29 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_28 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_27 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_26 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_25 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_24 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_23 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_22 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_21 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_20 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
#define MkC_Float(pos,val) (val)
#define MkC_String(pos,val) (val)
#define MkC_Integer(pos,val) (val)
#define MkIdentifier(pos,val) (val)
#define MkP_String(pos,val) (val)
#endif