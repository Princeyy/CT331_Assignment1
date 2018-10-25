#include <stdio.h>

int main(int arg, char* argc[]){

    int var1;
    int* var2;
    long var3;
    double* var4;
    char** var5;
    
    printf("Hello assignment1.\n");
    printf("Size of int = %ld\nSize of int* = %ld\nSize of long = %ld\nSize of double* = %ld\nSize of char** = %ld\n",
        sizeof(var1),sizeof(var2),sizeof(var3),sizeof(var4),sizeof(var5));
    return 0;
}
