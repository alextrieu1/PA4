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
void createCat(Cat** list, int index);

void createCat(Cat** list, int index){
    
    //Allocate memory for Cat struct
    list[index] = malloc(sizeof(Cat));

    char name[MAXSIZE];
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

int compareTo(Cat* ptrC1, Cat* ptrC2, int key){
    
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