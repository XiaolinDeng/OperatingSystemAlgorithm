//
// Created by E on 2019/3/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct data
{
    int hour;
    int min;
    int value;
}time;
typedef struct node
{
    int id;
    char name[20];
    time arrive;
    time executeTime;
    time start;
    time finish;
    int cyclingTime;
    float ;
    struct node* next;

}linklist;
typedef linklist* linknode;
char buf[1000000];

linknode genlink()
{
    FILE *fin;
    char *cc;
    char a[]="-1";
    linknode head,p,l;
    head = (linknode)malloc(sizeof(linklist));
    p = head;
    printf("Inputing data.....\n");
    fin = fopen("test.txt","r");
    while(!feof(fin))
    {
        //once read a line
        fgets(buf,100000,fin);

        cc = strtok(buf," \t\r\n");
        if(strcmp(cc,"-1")==0) break; //judge if end
        l = (linknode)malloc(sizeof(linklist));
        l->next=l;
        //add data in node
        l->id = atoi(cc);
        cc = strtok(NULL," \t\r\n");

        strcpy(l->name,cc);
        cc = strtok(NULL," \t\r\n");

        l->arrive.hour = atoi(cc);
        cc = strtok(NULL," \t\r\n");

        l->arrive.min = atoi(cc);
        cc = strtok(NULL," \t\r\n");

        l->executeTime.hour = atoi(cc);
        cc = strtok(NULL," \t\r\n");

        l->executeTime.min = atoi(cc);
        cc = strtok(NULL," \t\r\n");

        p->next = l;

        p = l;

    }
    p->next=NULL;
        ////exam if the input work right
//    while(head->next)
//    {
//        printf("\nid=%d\tname=%s\tah=%d\tam=%d\tzh=%d\tzm=%d\t\n",
//                head->id,head->name,head->arrive.hour,head->arrive.min,head->executeTime.hour,head->executeTime.min);
//        head = head->next;
//    }
    return head;
}////

void linksort(linknode unsortLink)
{
    linknode whistle,pre,next,last;
    if(!unsortLink->next->next) return;
    whistle = unsortLink;
    while (whistle->next->next)
    {
        pre = whistle;
        next = pre->next;
        last = next->next;
        while(last)
        {
            if(next->arrive.hour<last->arrive.hour)
            {
                pre = pre->next;
                next = pre->next;
                last = next->next;
                continue;
            }
            else if (next->arrive.hour>last->arrive.hour)
            {
                pre->next = last;
                next->next = last->next;
                last->next = next;
                pre = pre->next;
                next = pre->next;
                last = next->next;
            }
            else
            {
                if(next->arrive.min<=last->arrive.min)
                {
                    pre = pre->next;
                    next = pre->next;
                    last = next->next;
                    continue;
                }
                else
                {
                    pre->next = last;
                    next->next = last->next;
                    last->next = next;
                    pre = pre->next;
                    next = pre->next;
                    last = next->next;
                }
            }
        }
        whistle = whistle->next;
    }
}

void linkprint(linknode show)
{
    show = show->next;
    while(show)
    {

        printf("id = %d\t\tname = %s\tat = %d:%d\t\tzt = %d:%d\t\n",
               show->id,show->name,show->arrive.hour,show->arrive.min,show->executeTime.hour,show->executeTime.min);
     show = show->next;
    }
}
void tck(time *ct)
{
    while (ct->min>=60||ct->min<0)
    {
        if (ct->min>=60)
        {
            ct->min -=60;
            ct->hour++;
            continue;
        }
        else
        {
            ct->min += 60;
            ct->hour--;
        }
        ct->value = ct->hour * 60 + ct->min;
    }
}
void fcfo(linknode process)
{
    process = process->next;
    time now = process->arrive;
    time cycle;
    float ratio,up,down;
    printf("This is processing list:\n");
    while(process)
    {

        process->executeTime.hour=0;
        /// Todo: id name arriveTime executeTime startTime finishTime cyclingTime ratio
        process->start = now;
        if(process->start.hour<process->arrive.hour) process->start.hour=process->arrive.hour;
        if(process->start.min<process->arrive.min) process->start.min=process->arrive.min;
        process->finish.min = process->executeTime.min + now.min;
        process->finish.hour = process->executeTime.hour + now.hour;
        tck(&process->finish);
        now = process->finish;
        if(now.hour<process->next->arrive.hour) now.min=process->next->arrive.hour;
        if(now.min<process->next->arrive.min) now.min=process->next->arrive.min;

        cycle.min = process->finish.min - process->arrive.min;
        cycle.hour = process->finish.hour - process->arrive.hour;
        tck(&cycle);
        up = (float)(cycle.hour * 60 + cycle.min);
        down = (float)(process->executeTime.min + process->executeTime.hour * 60);
        ratio = up/down;
        printf("id=%d\tname=%s\tarriveTime=%d:%d\texecuteTime=%d:%d\tstartTime=%d:%d\t"
       "finishTime=%d:%d\ncyclingTime:=%d:%d\traito=%f\n",
       process->id,process->name,
       process->arrive.hour,process->arrive.min,
       process->executeTime.hour,process->executeTime.min,
       process->start.hour,process->start.min,
       process->finish.hour,process->finish.min,
       cycle.hour,cycle.min,
       ratio
       );
    process=process->next;
    }
}





int main()
{
    time b;
    b.hour = 2;
    b.min = 2222;
    tck(&b);
    printf("%d:%d",b.hour,b.min);
    return 0;

}
