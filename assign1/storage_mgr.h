#ifndef STORAGE_MGR_H
#define STORAGE_MGR_H

#include "dberror.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************
 *                    handle data structures                *
 ************************************************************/
typedef struct SM_FileHandle {
	char *fileName;
	int totalNumPages;
	int curPagePos;
	void *mgmtInfo;
} SM_FileHandle;

typedef char* SM_PageHandle;

/************************************************************
 *                    interface                             *
 ************************************************************/
/* manipulating page files */
extern void initStorageManager (void);
extern RC createPageFile (char *fileName){
    int i;
    fopen(*fileName, "w");
    fwrite(1); //totalNumPages
    for (i = 0; i < PAGE_SIZE, i++) {
        fwrite('\0');
    };
    fclose();
}
extern RC openPageFile (char *fileName, SM_FileHandle *fHandle){
    fopen(*filename, "r");
    fhandle->*fileName = *fileName;
    fhandle->totalNumPages = ; //read totalNumPages from start of file
    fhandle->curPagePos = 0;
}

extern RC closePageFile (SM_FileHandle *fHandle){
    fclose(fhandle->*fileName);
}
    
extern RC destroyPageFile (char *fileName){
    remove(fhandle->*fileName);
}

/* reading blocks from disc */
extern RC readBlock (int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage);
extern int getBlockPos (SM_FileHandle *fHandle);
extern RC readFirstBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC readPreviousBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC readCurrentBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC readNextBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC readLastBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);

/* writing blocks to a page file */
extern RC writeBlock (int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC writeCurrentBlock (SM_FileHandle *fHandle, SM_PageHandle memPage);
extern RC appendEmptyBlock (SM_FileHandle *fHandle);
extern RC ensureCapacity (int numberOfPages, SM_FileHandle *fHandle);

#endif
