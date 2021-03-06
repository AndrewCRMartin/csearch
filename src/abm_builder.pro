#ifndef __am_builder_PRO__
#define __am_builder_PRO__
 
/*
   Prototypes for directory : ABM_LOOPS
   Generated by williams on Fri Oct 15 17:19:53 BST" 1993
*/
 
void BLDAbM4H(PDBdata *PDBptr);
 
void BLDAddCleanUp(char *FileName);
 
int BLDAddCons(char *CBuffer, int *LineNo, Constraints **ConsPtr);
 
int BLDAddHyd(void);
 
int BLDAddResRng(ResRange **TopPtr, int first, int last, int ign_level);
 
int BLDAddStep(void);
 
int BLDAddTerms(PDBdata *PDBptr);
 
void BLDAnalyseBld(void);
 
int BLDChkBldCon(LoopData *LoopPtr);
 
int BLDChkCGEN(CongenData *CongenPtr);
 
int BLDChkDBase(DataBase *DBasePtr);
 
int BLDChkEUREKA(EurekaData *EurPtr);
 
int BLDChkFinish(void);
 
int BLDChkFrame(void);
 
int BLDChkLoop(char *FragID, LoopData *LoopPtr);
 
int BLDChkPDBRd(void);
 
int BLDChkPDBseq(char *FileName);
 
int BLDChkRdSeq(FILE *FilePtr, char ChainID, int *LineNo);
 
int BLDChkSChain(void);
 
void BLDCleanUp(FinalData *FinalPtr);
 
int BLDDoRdCntrl(FILE *FilePtr);
 
int BLDEurRename(void);
 
int BLDFormatPDB(char *FileName);
 
int BLDGetKeyWord(FILE *FilePtr, int *LineNo, char *CBuffer, char *KeyWord);
 
int BLDGetRealSeq(int Start, int Finish, char *RealSeq);
 
void BLDGetTime(char *TheDate);
 
int BLDInitData(void);
 
int BLDInitialise(char *LogFile);
 
void BLDListSteps(void);
 
void BLDMPskel(void);
 
void BLDMainProg(int argc, char *argv[]);
 
void BLDMergeTerms(PDBdata *PDBptr);
 
int BLDNoDelRes(int Norm1, int Norm2, int *Real1, int *Real2, int *TotRes, char *ChainID);
 
int BLDProcCGEN(STEP *CurStep);
 
int BLDProcDBase(STEP *CurStep);
 
int BLDProcEUREKA(STEP *CurStep);
 
int BLDProcFINAL(STEP *CurStep);
 
int BLDProcFrame(STEP *CurStep);
 
int BLDProcPDB(STEP *CurStep);
 
int BLDProcSChn(STEP *CurStep);
 
int BLDProcSELECT(STEP *CurStep);
 
int BLDProcess(void);
 
int BLDRdCONGEN(FILE *FilePtr, char *FragID, int *LineNo, LoopData *LoopPtr);
 
int BLDRdDataBase(FILE *FilePtr, char *FragID, int *LineNo, LoopData *LoopPtr);
 
int BLDRdEUREKA(FILE *FilePtr, char *FragID, int *LineNo, LoopData *LoopPtr);
 
int BLDRdFinish(FILE *FilePtr, int *LineNo);
 
int BLDRdFrame(FILE *FilePtr, int *LineNo);
 
int BLDRdLoopInf(FILE *FilePtr, int *LineNo, char *FragID);
 
int BLDRdLoops(FILE *FilePtr, char ChainID, int *LineNo);
 
int BLDRdPDBdata(FILE *FilePtr, int *LineNo);
 
int BLDRdResInfo(int *Nresidues, char ResNam3[MAX_AMINO][MAX_LINE_LEN],  char ResNam1[MAX_AMINO], int AtmCount[MAX_AMINO], char AtomOrder[MAX_AMINO][MAX_RES_ATM][5]);
 
int BLDRdSelect(FILE *FilePtr, char *FragID, int *LineNo, LoopData *LoopPtr);
 
int BLDRdSeqnce(FILE *FilePtr, int *LineNo);
 
int BLDRdSideChn(FILE *FilePtr, int *LineNo);
 
int BLDReadConfig(void);
 
int BLDReadControl(char *ControlFile);
 
void BLDRestart(void);
 
int BLDRunEureka(char *Command, char *ErrFile);
 
int BLDRunFilter(Select *SelPtr, int NModels);
 
int BLDRunProg(char *Command);
 
int BLDSelConf(char *ResFile, int NModels, int *LoopNum);
 
int BLDSetNoCan(char *LoopID, int LineNo);
 
void BLDSetResStat(int BuildLevel);
 
int BLDSetUDBname(char ChainID, char *UDBname, int LineNo);
 
void BLDShowSeq(void);
 
void BLDShutDown(void);
 
int BLDSortAtoms(PDBdata *PDBptr);
 
int BLDStdPDB(char *PDBfile);
 
void BLDTickBuild(void);
 
void BLDTickCGEN(CongenData *CGENptr);
 
void BLDTickDBase(DataBase *DbasePtr);
 
void BLDTickFrame(void);
 
int BLDTotAtoms(int UpToRes, int QAddTerms, int *TotAtoms, int *TotRes);
 
int BLDWrAtExcl(FILE *FilePtr, int Lstart, int Lfinish, int Bstart, int Bfinish, int Qbuild, char *RealSeq, int Nresidues, int AtmCount[MAX_AMINO], char ResNam1[MAX_AMINO],  char AtomOrder[MAX_AMINO][MAX_RES_ATM][5]);
 
int BLDWrCGENpir(char *PirFile);
 
int BLDWrCONGEN(CongenData *CGENptr, char *InFile, char *LoopFile);
 
int BLDWrChoth(void);
 
int BLDWrDBASE(DataBase *DBasePtr, char *CntrlFile, char *ExclFile,  char *LoopFile);
 
int BLDWrDBexcl(DataBase *DBasePtr, char *ExclFile);
 
int BLDWrEurCntrl(EurekaData *EurPtr, char *CntrlFile, char *ErrFile, char *EnerFile, char *LoopFile, char *CriFile, char *RestrFile, char *ConvFile);
 
int BLDWrEurIgnor(STEP *CurStep, char *IgnorFile);
 
int BLDWrEurRestr(STEP *CurStep, char *RestrFile);
 
int BLDWrFilter(Select *SelPtr, char *CntrlFile, char *ResFile,  float Resolution, int NModels);
 
int BLDWrFrame(void);
 
int BLDWrProgress(STEP *CurStep);
 
void MPMsgOut (char mname[], char mid[], char info1[], char info2[], char info3[], char info4[], char cretun[]);void MPToScreen(char mpmsg[]);void BLDWriteMsg(char *ModName, char *MsgID, char *Embed1, char *Embed2, char *Embed3, char *Embed4);
 
void BLDsuccess(void);
 
 
#endif
