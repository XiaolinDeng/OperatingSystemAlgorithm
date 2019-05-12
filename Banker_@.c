//
// Created by E on 2019/4/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print1dArray(int array[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void print2dArray(int **array, int l1, int l2) {
    for (int i = 0; i < l1; ++i) {
        for (int j = 0; j < l2; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int **init2dArray(int processesNumber, int resourcesNumber) {
    int **array;
    array = (int **) malloc(sizeof(int *) * processesNumber);
    for (int i = 0; i < processesNumber; ++i) {
        array[i] = (int *) malloc(sizeof(int) * resourcesNumber);
    }
    return array;
}

bool checkMax(int check[], int standard[], int len) {
    bool legal = true;
    for (int i = 0; i < len; ++i) {
//        Not legal case
        if (check[i] > standard[i]) {
            legal = false;
            break;
        }
    }
    return legal;
}

int main() {

//    Input the necessary number
    int resourcesNumber, processesNumber;
    printf("Please input the number of resouces:\n");
    scanf("%d", &resourcesNumber);
    printf("Please input the number of Processes:\n");
    scanf("%d", &processesNumber);

//    Initialize array used in process.
    int bankAvailable[resourcesNumber];
    bool processesFinish[processesNumber];
    int **processesNeed;
    int **processesMax;
    int **processesAllocate;

    processesNeed = init2dArray(processesNumber, resourcesNumber);
    processesMax = init2dArray(processesNumber, resourcesNumber);
    processesAllocate = init2dArray(processesNumber, resourcesNumber);

//    Input bankAvailable
    printf("Please input %d bank resources: ", resourcesNumber);
    for (int k = 0; k < resourcesNumber; ++k) {
        scanf("%d", &bankAvailable[k]);
    }
    print1dArray(bankAvailable, resourcesNumber);

//    Input processesMax;
    printf("Please input %d information: \n");
    for (int i = 0; i < processesNumber; ++i) {
        printf("Process[%d]:", i);
        for (int j = 0; j < resourcesNumber; ++j) {
            scanf("%d", &processesMax[i][j]);
        }
//        check if processesmax is legal
        while (checkMax(processesMax[i], bankAvailable, resourcesNumber)) {
            printf("Max input not legal please input again\n");
            for (int j = 0; j < resourcesNumber; ++j) {
                scanf("%d", &processesMax[i][j]);
            }
        }
    }
    printf("Please input %d processes\Kn:",processesNumber);
    for (int l = 0; l < ; ++l) {
        
    }

    return 0;

}

