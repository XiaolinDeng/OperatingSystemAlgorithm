//
// Created by dxl on 19-3-31.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct t
{
    int hour;
    int min;
    int value;

}time;

typedef struct process
{
    char name[20];
    struct process* next;
    int priority;
    time arrive;
    time execute;
    time start;
    time finish;
    int cycling;
    float ratio;

} pc;
typedef pc* linknode;


void timecheck(time *t)
{
    while(t->min>=60||t->min<0)
    {
        if(t->min>=60)
        {
            t->min -= 60;
            t->hour ++;
        }
        else
        {
            t->min +=60;
            t->hour --;
        }
    }
    t->value = t->hour * 60 + t->min;
}

linknode genlist(linknode head)
{
    char buf[100000];
    FILE *fin;
    char *cc;
    linknode p,q,l;
    head = (linknode)malloc(sizeof(struct process));
    p = head;
    p->next = NULL;
    fin = fopen("PRIORITY.txt","r");
}

