extern tp_Str		RBS_Cmd;
extern boolean		ShortCacheNameFlag;
extern boolean		LocalIPCFlag;
extern tp_Loc		LastLoc;
extern boolean		History;
extern boolean		IsCmdLex;
extern int		ErrLevel;
extern int		WarnLevel;
extern int		VerifyLevel;
extern tp_Date		VerifyDate;
extern tp_LocPrm	PValLocPrm;
extern boolean		IsAny_ReadyServerAction;
extern boolean		IsTTY;
extern boolean		DebugLocElm;
extern boolean		DumpCore;
extern boolean		IsClient;
extern boolean		IsServer;
extern boolean		Signalled;
extern boolean		Handled;
extern boolean		SigChild;
extern int		MaxBuilds;
extern int		CurSize;
extern int		DataNum;
extern int		HelpLevel;
extern int		LogLevel;
extern tp_Client	LocalClient;
extern tp_Client	CurrentClient;
extern tp_Client	FirstClient;
extern tp_Date		PendingDate;
extern tp_Date		CurrentDate;
extern tp_FilDsc	StdErrFD;
extern tp_FilDsc	StdInFD;
extern tp_FilDsc	StdOutFD;
extern tp_FilElm	ModFilElm;
extern tp_FilHdr	EmptyFilHdr;
extern tp_FilHdr	PrmDataDirFilHdr;
extern tp_FilHdr	StrDirFilHdr;
extern tp_FilHdr	NilStrFilHdr;
extern tp_FilHdr	FlagPrmFilHdr;
extern tp_FilHdr	CacheDirFilHdr;
extern tp_FilHdr	ModFilHdr;
extern tp_FilHdr	OdinDirFilHdr;
extern tp_FilHdr	RootFilHdr;
extern tp_FilHdr	NetRootFilHdr;
extern tp_FilInp	ModFilInp;
extern tp_FilTyp	CopyFilTyp;
extern tp_FilTyp	PrmValuesFilTyp;
extern tp_FilTyp	ViewSpecFilTyp;
extern tp_FilTyp	FirstFilTyp;
extern tp_FilTyp	ApplyFilTyp;
extern tp_FilTyp	TargetsPtrFilTyp;
extern tp_FilTyp	TargetsFilTyp;
extern tp_FilTyp	ActTargetsFilTyp;
extern tp_FilTyp	VirTargetsFilTyp;
extern tp_FilTyp	VirDirFilTyp;
extern tp_FilTyp	GenericFilTyp;
extern tp_FilTyp	PipeFilTyp;
extern tp_FilTyp	ObjectFilTyp;
extern tp_FilTyp	FileFilTyp;
extern tp_FilTyp	ListFilTyp;
extern tp_FilTyp	NoInputFilTyp;
extern tp_FilTyp	ExpandHooksFilTyp;
extern tp_FilTyp	FatherFilTyp;
extern tp_PrmTyp	NullPrmTyp;
extern tp_PrmTyp	CopyDestPrmTyp;
extern tp_PrmTyp	HookValPrmTyp;
extern tp_PrmTyp	ApplyPrmTyp;
extern tp_FileName	JobsDirName;
extern tp_FileName	CacheDirName;
extern tp_FileName	CWDirName;
extern tp_FileName	OdinDirName;
extern tp_Host		FirstHost;
extern tp_Ident		DfltIdent;
extern tp_LocStr	LocNilStr;
extern tp_LocElm	FreeLocElm;
extern tp_LocHdr	RootLocHdr;
extern tp_LocPrm	RootLocPrm;
extern tp_FilPrm	RootFilPrm;
extern tp_Str		Banner;
extern tp_Tool		DrvDirElmTool;
extern tp_Tool		VirDirElmTool;
extern tp_Tool		SourceTool;
extern tp_Tool		StrTool;
extern tp_Tool		PntrHoTool;
extern tp_Tool		PntrElmTool;
extern tp_Tool		InternalPntrTool;
extern tp_Tool		TextDefTool;
extern void		(*IPC_Action)(GMC_P1(boolean*) GMC_PN(tp_Str));