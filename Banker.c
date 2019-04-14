//
// Created by dxl on 19-4-1.
//

// Including Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global definition
# define MAX 100


void arrayPrinter(int array[],int len){
    for (int i = 0; i < len; ++i) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void initBanker(int bankres[],int resnum){
    printf("Please input %d type resources number:",resnum);
    for (int i = 0; i < resnum; ++i) {
        scanf("%d",&bankres[i]);
    }
//    arrayPrinter(bankres,resnum);
}

void inputMax(int max[][5],int pronum,int resnum){
    printf("Please input %d number of process:",pronum);
    for (int i = 0; i < pronum; ++i) {
        printf("Process[%d]",i);
        for (int j = 0; j < resnum; ++j) {
            scanf("%d",&max[i][j]);
        }
    }
}


int main(){

//  Following is global in main
    int resNum,proNum;

//  Following array is used by banker
    int avalable[MAX];

//  Folling arrays is used by process
    int need[MAX][MAX];
    int max[MAX][MAX];
    int allocate[MAX][MAX];
    int finish[MAX];
    int request[MAX][MAX];
    int flag[MAX];
//  This array is used to save safe list
    printf("Please input the number of resources number:  ");
    scanf("%d",&resNum);
    printf("Please input the number of process number:");
    scanf("%d",&proNum);
    initBanker(avalable,resNum);

    return 0;
}