//
// Created by E on 2019/4/28.
//
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int processesNumber = 3;
    int resourcesNumber = 4;
    int **array;
        array = (int **) malloc(sizeof(int *) * processesNumber);
    for (int i = 0; i < processesNumber; ++i) {
        array[i] = (int *) malloc(sizeof(int) * resourcesNumber);
        for (int j = 0; j < resourcesNumber; ++j) {
            array[i][j] = i * resourcesNumber + j;
        }
    }
    for (int k = 0; k <processesNumber; ++k) {
        for (int i = 0; i < resourcesNumber; ++i) {
            printf("%d",array[k][i]);
        }
    }
    return 0;
}