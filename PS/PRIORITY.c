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
    int id;

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
    fin = fopen("PRI.txt","r");
    if (!fin)
    {
        printf("File not finded!");
        free(head);
        return NULL;
    }
    while(!feof(fin))
    {
        fgets(buf,100000,fin);
        cc = strtok(buf," \r\n\t");
        if (strcmp(cc,"-1")==0) break;
        l = (linknode)malloc(sizeof(pc));
        l->next = NULL;
        l->id = atoi(cc);

        cc = strtok(NULL," \t\r\n");
        l->priority = atoi(cc);

        cc = strtok(NULL," \t\r\n");
        strcpy(l->name,cc);

        cc = strtok(NULL," \t\r\n");
        l->arrive.hour = atoi(cc);

        cc = strtok(NULL," \t\r\n");
        l->arrive.min = atoi(cc);

        cc = strtok(NULL, "\t\r\n");
        l->execute.hour = atoi(cc);

        cc = strtok(NULL, " \t\r\n");
        l->execute.min = atoi(cc);

        timecheck(&l->arrive);
        timecheck(&l->arrive);

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
    p = head->next;
    while(p)
    {
        printf(" id  =  %d    %s   %d  %d    %d    %d      \n",
               p->id,p->name,p->arrive.hour,p->arrive.min,
               p->execute.hour,p->execute.min);
        p = p->next;
    }
    return head;
}

int main()
{
    pc head;
    genlist(&head);
}



