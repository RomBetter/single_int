#include "single_list.h"
#include <stdio.h>

#include <stdlib.h>

struct sListNode *_get_new_struct (int value){
  
  struct sListNode *res;
  res = (struct sListNode *)malloc (sizeof(struct sListNode));
  res->sData = value;
  res->pNext = NULL;
  return res;

}
void sInitilize (sList *sPointerList){

  sPointerList->pHead = NULL;
  sPointerList->size = 0;
}

void sFree (sList *sPointerList){

  struct sListNode *current = sPointerList->pHead;

  while (sPointerList->pHead != NULL){
    free(sPointerList->pHead);
    sPointerList->pHead = current->pNext;
  }
  sPointerList->pHead = NULL;
  sPointerList->size = 0;
}

int sEmpty (sList *sPointerList){
    return (sPointerList->pHead == NULL);
}

struct sListNode *append (sList *sPointerList, int value){

  struct sListNode *next = sPointerList->pHead;

  if (next == NULL){
    sPointerList->pHead = _get_new_struct(value);
    sPointerList->size++;
    return sPointerList->pHead;
  }

  while (next->pNext != NULL)
    next = next->pNext;

    next->pNext = _get_new_struct(value);
    sPointerList->size++;
  return next->pNext;
}


struct sListNode *Insert_At_Begin(sList *sPointerList, int value){

  if (sPointerList->pHead == NULL)
    return append(sPointerList, value);
  
  struct sListNode* new_element;
  struct sListNode* temp;

    temp = sPointerList->pHead;

    new_element = _get_new_struct(value);
    sPointerList->pHead = new_element;
    sPointerList->pHead->pNext = temp;
    sPointerList->size++;
  return new_element;
}


struct sListNode *Insert_By_Index(sList *sPointerList, unsigned index, int value){

  if (index >= sPointerList->size)
    return NULL;
  
  unsigned int i = 0;
  struct sListNode *next = sPointerList->pHead;
  struct sListNode *new_element;
  struct sListNode *temp;

    while(i++ < index)
      next = next->pNext;

    new_element = _get_new_struct(value);
    temp = next->pNext;
    next->pNext = new_element;
    new_element->pNext = temp;
    sPointerList->size++;

return new_element;
}


struct sListNode *Insert_By_Pointer(sList *sPointerList, struct sListNode *sPointerNode, int value){

    unsigned i = 0;
    struct sListNode *current;
    struct sListNode *next;
    struct sListNode *new_element;

  new_element = _get_new_struct(value);
  current     = sPointerNode;
  next        = sPointerNode->pNext;
  new_element->pNext = next;
  current->pNext = new_element;
  sPointerList->size++;
 return new_element++;

}

struct sListNode *remove_first (sList *sPointerList){

  if (sPointerList->pHead == NULL)
    return NULL;

  struct sListNode *temp;
  temp = sPointerList->pHead;
  free(sPointerList->pHead);
  sPointerList->pHead = temp->pNext;
  sPointerList->size--;

  return sPointerList->pHead;
}

struct sListNode *remove_last (sList *sPointerList){
  
  if (sPointerList->pHead == NULL)
      return NULL;

  struct sListNode *Last_struct = sPointerList->pHead;
  struct sListNode *Prev_struct;

  Prev_struct = Last_struct;

  while (Last_struct->pNext != NULL){
    Prev_struct = Last_struct;
    Last_struct = Last_struct->pNext;
  }
  free(Last_struct);

  Prev_struct->pNext = NULL;
  sPointerList->size--;

  if(sPointerList->size == 0)
      sPointerList->pHead = NULL;

  return sPointerList->pHead;
}

struct sListNode *remove_by_index (sList *sPointerList, unsigned index){

    if(sPointerList->size <= index)
      return NULL;
    unsigned i  = 0;
    struct sListNode *temp;
    struct sListNode *next = sPointerList->pHead;
    
    while (++i < index){
      temp = next;
      next = next->pNext;
  }
  temp->pNext = next->pNext;
  free(temp);
  sPointerList->size--;

  return sPointerList->pHead;
}

struct sListNode *remove_by_pointer (sList *sPointerList, struct sListNode *sPointerNode){

  if (sPointerNode == NULL || sPointerList->pHead == NULL)
    return NULL;

  unsigned i = 0;

  struct sListNode *next = sPointerList->pHead;

  while (next != NULL){
    next = next->pNext;
    i++;
  }
  return remove_by_index(sPointerList, i);
}

struct sListNode *sFind (sList *sPointerList, int value){

  struct sListNode *current = sPointerList->pHead;

  unsigned i = 0;

  while (current){

    if (current->sData == value)
      return current;
    current = current->pNext;
    ++i;
  }
  return NULL;
}

struct sListNode *sFirst_Struct (sList *sPointerList){
  
  return (sPointerList->pHead);

}

struct sListNode *sLast_Struct (sList *sPointerList){

  struct sListNode *next = sPointerList->pHead;
    
  while (next != NULL)
    next = next->pNext;
  return next;
}

struct sListNode *Struct_Next (struct sListNode * sPointerNode){

    if (sPointerNode == NULL)
      return NULL;
    if (sPointerNode->pNext != NULL)
        return sPointerNode->pNext;

    return NULL;
}

void sort (sList *sPointerList){

  struct sListNode *i;
  struct sListNode *j;

  i = sPointerList->pHead;

  while (i){

    for (j = i->pNext; j && i->sData <= j->sData; j = j->pNext)
        continue;
    if (j != NULL){
      int temp;
      temp = j->sData;
      j->sData = i->sData;
      i->sData = temp;
    } else 
      i = i->pNext;
  }
}

void sPrintfSurf(sList *sPointerList){

  struct sListNode *next = sPointerList->pHead;

  if (next != NULL){
    printf ("%d, ", next->sData);
    next = next->pNext;
  }
}
