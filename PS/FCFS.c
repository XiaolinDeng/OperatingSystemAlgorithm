//
// Created by dxl on 19-3-28.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "MyTime.h"
typedef struct node
{
    int id;
    char name[20];
    time arrive;
    time execute;
    time start;
    time finish;
    int cycling;
    float ratio;
    struct  node* next;
}linklist;

typedef linklist* linknode;

void listprint(linknode head){
    linknode p;
    p = head->next;
    while(p) {
        printf(" id  =  %d    %s   %d  %d    %d    %d      \n",
               p->id, p->name, p->arrive.hour, p->arrive.min,
               p->execute.hour, p->execute.min);
        p = p->next;
    }
}

linknode genlist(linknode head)
{
    char buf[100000];
    FILE *fin;
    char *cc;
    linknode p,q,l;
    head = (linknode)malloc(sizeof(linklist));
    p = head;
    p->next = NULL;
    fin = fopen("FCFS.txt","r");
    if(!fin)
    {
        printf("Can't find file");
        free(head);
        return NULL;
    }
    while(!feof(fin))
    {
        fgets(buf,100000,fin);

        cc = strtok(buf, " \r\t\n");

        if (strcmp(cc,"-1")==0) break;
        l = (linknode)malloc(sizeof(linklist));
        l->next = NULL;
        l->id = atoi(cc);

        cc = strtok(NULL, " \r\t\n");
        strcpy(l->name,cc);

        cc = strtok(NULL, " \r\n\t");
        l->arrive.hour = atoi(cc);

        cc = strtok(NULL, " \r\n\t");
        l->arrive.min = atoi(cc);
        timecheck(&l->arrive);

        cc = strtok(NULL," \t\r\n");
        l->execute.hour = atoi(cc);

        cc = strtok(NULL," \r\t\n");
        l->execute.min = atoi(cc);

        timecheck(&l->arrive);
        timecheck(&l->execute);

        p = head;
        while(p->next)
        {

             if (l->arrive.value > p->next->arrive.value)
            {
                p=p->next;
                continue;
            }
            if(l->arrive.value <= p->next->arrive.value)
            {
                q = p->next;
                p->next = l;
                l->next = q;
                break;
            }
        }
        if(!p->next)
        {
            p->next = l;
            l->next = NULL;
        }
    }
    listprint(head);
    return head;
};

void FCFS(linknode head)
{
    //// Need check where time is wrong!!!!
    head = head->next;
    time system;
    system = head->arrive;
    linknode p = head;
    float avgCycle = 0;
    float avgRatio = 0;
    float counter = 0;
    while(p) {
        if (system.value <= p->arrive.value) {
            system = p->arrive;
        } else if (system.value > p->arrive.value) {
        }
        p->start = system;
        p->finish.hour = p->start.hour + p->execute.hour;
        p->finish.min = p->start.min + p->execute.min;
        timecheck(&p->finish);

        p->cycling = p->finish.value - p->arrive.value;
        p->ratio = (float) p->cycling / p->execute.value;
        system = p->finish;
        printf("id=%d\tname=%s\tStart = %d:%d\tFinish = %d:%d\t Cycle = %.2d\tRatio=%.2f\n",
               p->id,
               p->name,
               p->start.hour,
               p->start.min,
               p->finish.hour,
               p->finish.min,
               p->cycling,
               p->ratio);
        p=p->next;
    }
    p = head;
    while(p)
    {
        avgCycle += (float) p->cycling;
        avgRatio += (float) p->ratio;
        counter++;
        p = p->next;
    }
    avgCycle /= counter;
    avgRatio /= counter;
    printf("Average cycling time is %.2f ,Average Ratio is %.2f",avgCycle,avgRatio);
}



int main ()
{
    linklist p ;
    linknode q;
    q=genlist(&p);
    FCFS(q);
    return 0;
}




