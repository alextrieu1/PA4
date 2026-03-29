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
int is_sorted(Cat** list, int size, int key);
void swap(Cat** a, Cat** b);
int partition(Cat** list, int low, int high, int key);
void quickSort(Cat** list, int n, int key);
void quickSortRec(Cat** list, int low, int high, int key);
void insertionSort(Cat** list, int n, int key);
void createCat(Cat** list, int index);
void printData(Cat** list, int size, int key);

int compareTo(Cat* ptrC1, Cat* ptrC2, int key){
    
    //C1 is before C2 return 1
    if(ptrC1->scores[key] > ptrC2->scores[key])
        return 1;

    //C1 is after C2 return -1
    if(ptrC1->scores[key] < ptrC2->scores[key])
        return -1; 
    
    //If the values are equal, return -1 if C1 is before C2, 1 if C2 is before, return 0 if equal
    return strcmp(ptrC1->name, ptrC2->name);
}

// Returns 1 if array is sorted and returns 0 if the array is not sorted
int is_sorted(Cat** list, int size, int key){
    int i;
    for(i = 0; i < size-1; i++)
        if(compareTo(list[i], list[i+1],key) > 0)
            return 0;

    return 1;
}

//Swapping values
void swap(Cat** a, Cat** b){
    Cat* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Cat** list, int low, int high, int key){
    //Pick a random partition element and swap it into index low
    int i = low + rand()%(high-low+1);
    swap(&list[low],  &list[i]);

    int lowIndex = low;
    low++;

    while(low <= high){

        //Move low pointer until find value too large
        while(low <= high && compareTo(list[low], list[lowIndex], key) < 0)
            low++;
        
        //Move high pointer until find a value too small
        while(high >= low && compareTo(list[high], list[lowIndex], key) > 0)
            high--;
        
        //Swap
        if(low < high)
            swap(&list[low], &list[high]);
    }

    //swap pivot element
    swap(&list[lowIndex], &list[high]);

    //return the partition point
    return high; 
}
void quickSort(Cat** list, int n, int key){
    quickSortRec(list, 0, n-1, key);
}

void quickSortRec(Cat** list, int low, int high, int key){

    //If size is equal to or less than 30
    int size = high - low + 1;
    if (size <= BASECASESIZE){
        insertionSort(list + low, size, key);
        return;
    }
    //Only have to sort if there is more than one number
    if(low < high){
        int split = partition(list, low, high, key);
        quickSortRec(list, low, split-1, key);
        quickSortRec(list, split+1, high, key);
    }
}

void insertionSort(Cat** list, int n, int key){
    int i, j;
    for(i = 0; i < n; i++){
        Cat* item = list[i];

        //Move elements that are greater than item to one position 
        // ahead of their current position
        for(j = i - 1; j >= 0; j--){
            if(compareTo(list[j],item, key) < 0)
                list[j+1] = list[j];
            else 
                break;
        }
        list[j+1] = item;
    }
}

//Creates Cat
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

    for(int i = 0; i < NUMTRAITS-1; i++){
        int trait;
        scanf("%d", &trait);
        list[index]->scores[i] = trait;
        list[index]->scores[TOTAL] += trait;
    }
}

//Printing data
void printData(Cat** list, int size, int key){
    printf("%s Ranklist\n", TRAITS[key]);
    for(int i = 0; i < size; i++){
        printf("%d. %-15s %d\n", i + 1, list[i]->name, list[i]->scores[key]);
    }
    return;
}

int main(void){
    int size = 0;
    scanf("%d", &size);
    Cat** list = malloc(size * sizeof(Cat*));
    for(int i = 0; i < size; i++){
        createCat(list, i);
    }

    int key;
    scanf("%d", &key);
    quickSort(list, size, key);
    printData(list, size, key);

    //Freeing data
    for(int i = 0; i < size; i++){
        free(list[i]->name);
        free(list[i]);
    }
    free(list);
    return 0;
}