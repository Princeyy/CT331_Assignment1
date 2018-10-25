#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef struct listElementStruct listElement;
typedef void (*pf)(void* data);

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void* printFunction);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns number of items in list
int length(listElement* list);

//Push a new element onto the head of a list
void push(listElement** list, void* data, size_t size, void* printFunction);

//Pop an element from the head of a list.
listElement* pop(listElement** list); 

//Enqueue a new element onto the head of the list.
void enqueue(listElement** list, void* data, size_t size, void* printFunction); 

//Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list);

void printChar(void* data);
void printString(void* data);
void printInt(void* data);
void printDouble(void* data);
void printFloat(void* data);
void printLong(void* data);

#endif
