#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
  void* data;
  size_t size;
  pf printFunction;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(sizeof(void)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  } 
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->printFunction = printFunction;
  e->next = NULL;
  return e;
}

void printChar(void* data){
  printf("%c\n", *(char*)data);
}
void printString(void* data){
  printf("%s\n", (char*)data);
}
void printInt(void* data){
  printf("%d\n", *(int*) data);
}
void printDouble(void* data){
  printf("%lf\n", *((double*)data));
}
void printFloat(void* data){
  printf("%f\n", *(float*) data);
}
void printLong(void* data){
  printf("%ld\n", *(long*)data);
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    //printf("%s\n", current->data);
    current->printFunction(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void* printFunction){
  listElement* newEl = createEl(data, size, printFunction);
  listElement* next = after->next;
  newEl->next = next;
  after->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

//Returns the number of elements in a linked list
int length(listElement* list) {
    listElement* current = list;
    int count =0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

//Push a new element onto head of list
void push(listElement** list, void* data, size_t size, void* printFunction){
  listElement* element = createEl(data,size,printFunction);
  element->next = *list;
  *list = element;
}

//Pop an element from the head of the list
listElement* pop(listElement** list){
  listElement* temp = *list;
  *list = temp->next;
  return temp;
}

//Enqueue element at bottom of list 
void enqueue(listElement** list, void* data, size_t size, void* printFunction){
  listElement* newHead = createEl(data, size, printFunction);
  listElement* oldHead = *list;
  newHead->next = oldHead;
  *list = newHead;
}

//Dequeue element from top of list
listElement* dequeue(listElement* list){
  listElement* current = list;
  while(current->next->next != NULL){
    current = current->next;
  }
  listElement* element = current->next;
  deleteAfter(current);
  return element;
}
