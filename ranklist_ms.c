#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 12
#define NUMTRAITS 7
#define TOTAL 6
#define BASECASESIZE 30

const char TRAITS[NUMTRAITS][MAXSIZE+1] = {"Cuteness", "Fluffiness", "Agility", "Friendliness", "Intelligence", "Laziness", "Total"};

typedef struct Cat{
    char* name;
    int scores[NUMTRAITS];
} Cat;

int compareTo(Cat* ptrC1, Cat* ptrC2, int key);
void mergeSort(Cat** list, int n, int key);
void mergeSortRec(Cat** list, int low, int hight, int key);

int compareTo(Cat* ptrC1, Cat* ptrC2, int key){
    
}
