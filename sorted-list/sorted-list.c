#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"


SortedListPtr SLCreate(CompareFuncT cf)
{

	SortedListPtr list; 
	if(cf != NULL)
	{
		list = (SortedListPtr)malloc(sizeof(struct SortedList));
		list->head = NULL;
		list->cf = cf;
		return list;
	}
	return NULL;
}

void SLDestroy(SortedListPtr list)
{
	
}

int SLInsert(SortedListPtr list, void* newObj)
{	
	nodePtr newNode = (nodePtr)malloc(sizeof(node));
        newNode->data = newObj;
        nodePtr ptr = list->head;
        int compareValue = list->cf(newObj, ptr->data);

        if (ptr == NULL){
                list->head = newNode;
                newNode->numPtrs++;
                return 1;
        }   

        if (compareValue > 0){ 
                newNode->next = ptr;
                list->head = newNode;
                newNode->numPtrs++;
                return 1;
        }    

        if (ptr->next == NULL){
                if (compareValue == 0){ 
                        return 0;
                } else {
                        ptr->next = newNode;
                        newNode->numPtrs++:
                        return 1;
                }   
        }   

        compareValue = list->cf(newObj, ptr->next->data);

        while (compareValue <= 0){ 

                ptr = ptr->next;
                if (compareValue == 0){
                        return 0;
                }

                if (ptr->next == NULL){
                        break;
                }

                compareValue = list->cf(newObj, ptr->next->data);
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->numPtrs++;
        return 1;
}

int SLRemove(SortedListPtr list, void* newObj)
{
	nodePtr prev = NULL;
	int compare = (*list->cf)(newObj,list->head->data);
	SortedListIteratorPtr p = SLCreateIterator(list);/*p points to head of list*/
	void* currObj;

	if(p == NULL)/*list is empty*/	
	{
		printf("list is empty\n");
		return 0;
	}

	if(compare == 0)/*newObj is equal to head, so removes the head of the list*/
	{
		list->head = list->head->next;
		list->head->numPtrs++;
		free(p->curr);
		SLDestroyIterator(p);
		return 1;
	}

	prev = p->curr;
	currObj = p->curr->next->data;
	while(p->curr != NULL)/*traverses Linked List to find object to delete*/
	{
		compare = (*list->cf)(newObj, cuttObj);
		if(compare == 0){
			prev->next = curr->next;
			free(p->curr);
			SLDestoryIterator(p);
			return 1;
		}
		
		
	}
	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
	SortedListIteratorPtr itPtr = (SortedListIteratorPtr)malloc(sizeof(struct SortedListIterator));

	if(list->head != NULL)
	{
		itPtr->curr = list->head;
		list->head->counter++;
		return itPtr; 
			
	}		
	return NULL;
}

void SLDestoryIterator(SortedListIteratorPtr iter)
{

}

void* SLNextItem(SortedListIteratorPtr iter)
{
	return NULL;
}