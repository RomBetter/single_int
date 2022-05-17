#ifndef _SINGLE_LIST_H_
#define _SINGLE_LIST_H_

struct sListNode {

  struct sListNode *pNext;
  int               sData;
};

typedef struct {
  
    struct sListNode *pHead;
    unsigned           size;
}sList;

typedef int (*pf)(int, int);


void sInitilize (sList *);
void sFree(sList *);
int sEmpty(sList *);
struct sListNode *append(sList *, int);

struct sListNode *Insert_At_Begin(sList*, int);
struct sListNode *Insert_By_Index(sList*, unsigned, int);
struct sListNode *Insert_By_Pointer(sList*, struct sListNode*, int);

struct sListNode *remove_first(sList *);
struct sListNode *remove_lat (sList *);
struct sListNode *remove_by_index (sList *, unsigned);
struct sListNode *remove_by_pointer(sList *, struct sListNode*);


struct sListNode *sFind (sList *, int value);


struct sListNode *sFirst_Struct (sList*);
struct sListNode *sLast_Struct (sList*);

struct sListNode *Struct_Next (struct sListNode *);


void sort (sList *sPointerList);
void sPrintfSurf(sList *sPointerList);

#endif
