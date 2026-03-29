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
void mergeSortRec(Cat** list, int low, int high, int key);
void createCat(Cat** list, int index);

int compareTo(Cat* ptrC1, Cat* ptrC2, int key){
    
    //C1 is before C2 return -1
    if(ptrC1->scores[key] > ptrC2->scores[key])
        return -1;

    //C2 is before C1 return 1
    if (ptrC2->scores[key] > ptrC1->scores[key])
        return 1; 
    
    //If the values are equal, return -1 if C1 is before C2, 1 if C2 is before, return 0 if equal
    return strcmp(ptrC1->name, ptrC2->name);
}


void createCat(Cat** list, int index){
    
    //Allocate memory for Cat struct
    list[index] = malloc(sizeof(Cat));

    char name[MAXSIZE+1];
    scanf("%s", name);

    //Dynamically allocate memory for name
    list[index]->name = malloc(strlen(name) + 1);
    strcpy(list[index]->name, name);

    //Setting the total to 0 to avoid garbage data
    list[index]->scores[TOTAL] = 0;
    for(int i = 0; i < NUMTRAITS; i++){
        int trait;
        scanf("%d", &trait);
        list[index]->scores[i] = trait;
        list[index]->scores[TOTAL] += trait;
    }

}




int main(void){
    int size = 0;
    scanf("%d", &size);
    Cat** list = malloc(size * sizeof(Cat*));
    for(int i = 0; i < size; i++){
        createCat(list, i);
    }
    return 0;
}