#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");
  //Create different variables types to be added to linked list 
  int element1 = 1;
  float element2 = 2.02;
  double element3 = 3.03;
  char element4[] = "Element4";
  char element5 = '5';

  listElement* l = createEl(&element1, sizeof(int), &printInt);
  listElement* l2 = insertAfter(l, &element2, sizeof(float), &printFloat);
  insertAfter(l2, &element3, sizeof(double), &printDouble);
  
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
  push(&l,&element4,sizeof(element4),&printString);
  traverse(l);
  printf("\n");

  //Test pop
  printf("Popping from head of list\n");
  pop(&l);
  traverse(l);
  printf("\n");

  //Test Enqueue
  printf("Enqueing Element to head of list\n");
  enqueue(&l,&element5,sizeof(char),&printChar);
  traverse(l);
  printf("\n");

  //Test DeQueue
  printf("DeQueueing Element from tail of list\n");
  dequeue(l);
  traverse(l);
  printf("\n");

  printf("\nTests complete.\n");

}
