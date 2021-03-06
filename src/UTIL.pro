#ifndef __UTIL_PRO__
#define __UTIL_PRO__
 
/*
   Prototypes for directory : UTIL
   Generated by pimmsccs on Tue Nov  3 13:58:06 GMT 1992

   OMUPD KJW 16/12/92 Included Types.h & FileIO.h
*/

#include "Types.h"
#include "FileIO.h"
 
short CheckFileLen (char *,char *,char *,char *);
 
Logical CopyFile(char *sourceFile, char *destFile);
 
short DirAddElmnt(DirLinkPtr *Pointer, char *FileName);
 
void DirFreeList(DirLinkPtr Pointer);
 
short DirSortList(DirLinkPtr *Pointer, DirSortedPtr *SortedPointer,  int *count);
 
int DirSortNames(DirSortedPtr First, DirSortedPtr Second);
 
short GetFileName ( short,  char *, char *, char *, char *, char *, char *);
 
Logical InRange(float x, float minimum, float maximum);
 
void IntDescSort (short *list, short lsize) ;
 
Logical IsDirectory (char *FileName);
 
Logical IsRealNumber(char *text);
 
double RoundToBase(double x, double base, Logical direction);
 
double StepSize(double range, short *nstep);
 
int StrCollapse ( char * Input , char * Output );
 
int StrCount (char * Input ,char Character);
 
char *floattochar(char * numstring ,double number ,int maxsiz);
 
void geteps(float *epsilon) ;
 
char *inttochar(char * numstring ,int number ,int maxsiz);
 
char *strcpychk(char * output,char * input,int maxlen);
 
 
#endif
