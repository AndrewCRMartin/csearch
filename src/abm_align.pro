#ifndef __abm_align_PRO__
#define __abm_align_PRO__
 
/*
   Prototypes for directory : ABM_ALIGN
   Generated by williams on Tue Nov  9 15:30:47 "GMT 1993
*/
 
void ABMAliAliArea(AlignData *AlignPtr, int UserChain);
 
void ABMAliAppend(AlignData *AlignPtr, int UserChain);
 
void ABMAliCanReport(AlignData *AlignPtr, int UserChain);
 
void ABMAliChkAli(AlignData *AlignPtr, int UserChain);
 
int ABMAliChkCode(int *AminoAcid);
 
int ABMAliChkLim(AlignData *AlignPtr, int UserChn);
 
void ABMAliChkMut(AlignData *AlignPtr);
 
void ABMAliDelete(AlignData *AlignPtr, int UserChain);
 
int ABMAliDoAlign(AlignData *AlignPtr, int UserChain);
 
int ABMAliDoMain(AlignData *AlignPtr, int UserChain);
 
void ABMAliDrawScrn(AlignData *AlignPtr, int UserChain);
 
void ABMAliGoto(AlignData *AlignPtr, int UserChain);
 
void ABMAliHiCurs(AlignData *AlignPtr, int QHighLite);
 
void ABMAliHiLimit(AlignData *AlignPtr, int QHighLite);
 
void ABMAliInsert(AlignData *AlignPtr, int UserChain);
 
void ABMAliLimitBar(AlignData *AlignPtr, int UserChain);
 
void ABMAliLimits(AlignData *AlignPtr, int UserChain);
 
int ABMAliMain(void);
 
void ABMAliMsgArea(AlignData *AlignPtr);
 
void ABMAliMutate(AlignData *AlignPtr, int UserChain);
 
void ABMAliScaleBar(AlignData *AlignPtr, int UserChain);
 
int ABMAliScreen(AlignData *AlignPtr, int UserChain);
 
void ABMAliScroll(AlignData *AlignPtr, int UserChain, int OneTouch);
 
void ABMAliSeqLine(AlignData *AlignPtr, int UserChain);
 
void ABMAliSetCurs(AlignData *AlignPtr);
 
void ABMAliSetUndo(AlignData *AlignPtr, int UserChain);
 
AlignData *ABMAliSetUp(int UserChain);
 
void ABMAliSetUser(AlignData *AlignPtr);
 
void ABMAliTitle(AlignData *AlignPtr, int UserChain);
 
void ABMAliUndo(AlignData *AlignPtr, int UserChain);
 
void ABMAliUpdate(AlignData *AlignPtr, int UserChain);
 
void ABMAlign(char *ChainID);
 
 
#endif
