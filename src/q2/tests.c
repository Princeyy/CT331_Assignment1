#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");

  listElement* l = createEl("Element1", 30);
  listElement* l2 = insertAfter(l, "Element2", 30);
  insertAfter(l2, "Element3", 30);
  
  //Test traverse()
  printf("\nTravese list\n");
  traverse(l);
  printf("\n");

  //Test deleteAfter()
  printf("Delete Middle element...Then traverse\n");
  deleteAfter(l);
  traverse(l);
  printf("\n");

  //Test length()
  printf("Return length of list\n");
  printf("Length of list: %d\n",length(l));
  printf("\n");

  //Test push
  printf("Pushing to head of list\n");
  push(&l,"Element4",30);
  traverse(l);
  printf("\n");

  //Test pop
  printf("Popping from head of list\n");
  pop(&l);
  traverse(l);
  printf("\n");

  //Test Enqueue
  printf("Enqueing Element to head of list\n");
  enqueue(&l,"Element5",30);
  traverse(l);
  printf("\n");

  //Test DeQueue
  printf("DeQueueing Element from tail of list\n");
  dequeue(l);
  traverse(l);
  printf("\n");

  printf("\nTests complete.\n");
}
