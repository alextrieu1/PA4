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
void merge(Cat** list, int low, int mid, int high, int key);
void insertionSort(Cat** list, int n, int key);
void createCat(Cat** list, int index);
void printData(Cat** list, int size, int key);

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

void mergeSort(Cat** list, int n, int key){
    mergeSortRec(list, 0, n-1, key);
}

void mergeSortRec(Cat** list, int low, int high, int key){
    //Find the size
    int size = high - low + 1;
    
    if(size <= BASECASESIZE){
        //insertion sort
        return;
    }
    if(low < high){
        //get the mid point
        int mid = (low + high)/2;

        //Sort first and second halves
        mergeSortRec(list, low, mid, key);
        mergeSortRec(list, mid+1, high, key);
        merge(list, low, mid, high, key);
    }
}

void merge(Cat** list, int low, int mid, int high, int key){
    int i,j,k;
    int n1 = mid-low + 1;
    int n2 = high - mid;

    //Create temp arrays
    Cat** L = (int*) malloc(n1*sizeof(Cat*));
    Cat** R = (int*) malloc(n2*sizeof(Cat*));

    //Copy data to temp arrays
    for(i = 0; i < n1; i++)
        L[i] = list[low + i];
    for(j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

    //Merge the temp arrays back into arr
    i = 0; 
    j = 0; 
    k = low;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy elements of remaining elements
    while(i < n1){
        list[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        list[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void insertionSort(Cat** list, int n, int key){
    int i, j;
    for(i = 0; i < n; i++){
        Cat* item = list[i];

        //Move elements that are greater than item to one position 
        // ahead of their current position
        for(j = i - 1; j >= 0; j--){
            if(compareto(list[j],item) < 0)
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

    for(int i = 0; i < NUMTRAITS; i++){
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
        printf("%d. %-15s %d\n", &i + 1, list[i]->name, list[i]->scores[key]);
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
    mergeSort(list, size, key);
    printData(list, size, key);

    //Freeing data
    for(int i = 0; i < size; i++){
        free(list[i]->name);
        free(i);
    }

    free(list);
    return 0;
}