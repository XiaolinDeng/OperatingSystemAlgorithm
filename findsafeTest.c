//
// Created by E on 2019/5/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findSafe(int **processesAllocate, int **processNeed, int *bankResources, int *safeSequence, int resourcesNumber,
              int processesNumber) {
    bool flag1, flag2;
    flag1 = true;
    flag2 = false;
    int satisfiedProcess;
    int processWhisle = 0;
    int simulateBankResources[resourcesNumber];
    for (int i = 0; i < resourcesNumber; ++i) {
        simulateBankResources[i] = bankResources[i];
    }
    while (processWhisle < processesNumber) {
        for (int j = 0; j < processesNumber; ++j) {
            for (int i = 0; i < resourcesNumber; ++i) {
//            Only all resources satisfied can make one process finish.
                if (processNeed[j][i] > bankResources[i]) {
                    flag1 = false;
                    continue;
                }
            }
//        One can finish, means have resources return
            if (flag1) {
                flag2 = true;
                satisfiedProcess = j;
            }
        }
//    Case: No processes can satisfied resources, handle failed.
        if (flag2) return false;

        for (int k = 0; k < resourcesNumber; ++k) {
            simulateBankResources[k] += processesAllocate[satisfiedProcess][k];
        }
        processesNumber--;
        safeSequence[processWhisle] = satisfiedProcess;
        processWhisle++;
    }
}

int main() {


    return 0;
}
