//
// Created by E on 2019/3/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    int hour;
    int min;
}time;
typedef struct node
{
    int id;
    char name[20];
    time arrive;
    time zx;
    time start;
    time finish;
    int zz;
    float zzxs;
    struct node* next;

}linklist;
typedef linklist* linknode;
//This main is testing input function
void timePrint(time t)
{
    printf("%d:%d",t.hour,t.min);
}

linknode nm()
{
//  define all data should input from keyboard
    char nameIn[20];
    int idIn,arriveHour,arriveMin,exHour,exMin;
    linknode head,p,l;
    head = NULL;
    printf("input\nid\tname\tah\tam\teh\tem\n");
    scanf("%d %s %d %d %d %d",&idIn,&nameIn,&arriveHour,&arriveMin,&exHour,&exMin);
//  if first input is not legal input,just aboard.
    if(idIn == (-1)) return  0;
//  if first is available init the node struct.
    head = (linklist *) malloc(sizeof(linklist));
    p = (linklist *) malloc(sizeof(linklist));
    head->next = p;
    p->id = idIn;
    strcpy(head->name, nameIn);
    p->arrive.hour = arriveHour;
    p->arrive.min = arriveMin;
    p->zx.hour = exHour;
    p->zx.min = exMin;
// p is previous node, l is last node,create l ,and init l then let p->next equal to l.
// while upper is done ,let p=l( or p->next);
    printf("input\nid\tname\tah\tam\teh\tem\n");
    scanf("%d %s %d %d %d %d",&idIn,&nameIn,&arriveHour,&arriveMin,&exHour,&exMin);
    while(idIn != (-1))
    {
        l = (linklist *) malloc(sizeof(linklist));
        l->id = idIn;
        strcpy(head->name, nameIn);
        l->arrive.hour = arriveHour;
        l->arrive.min = arriveMin;
        l->zx.hour = exHour;
        l->zx.min = exMin;
        p->next = l;
        p = l;
        printf("input\nid\tname\tah\tam\teh\tem\n");
        scanf("%d %s %d %d %d %d",&idIn,&nameIn,&arriveHour,&arriveMin,&exHour,&exMin);
    }
    p->next = NULL;
    head=head->next;
    while(head != NULL)
    {
        printf("id=%d\n",head->id);
        head = head->next;
    }
    return head;
}
void nr(linknode unsort)
{
    linknode w,p,n,l;       //   out :w ;  in p->n->l;
    if (unsort->next->next == NULL) return ;
    w = unsort;
    while (w->next->next)
    {
        p = w;
        n = p->next;
        l = n->next;
        while(l)
        {
            if(n->arrive.hour<l->arrive.hour) continue;
            else if (n->arrive.hour<l->arrive.hour)
            {
                p->next = l;
                n->next = l->next;
                l->next = n;
            }
            else     //hour equal,judge min
            {
                if(n->arrive.min<l->arrive.min) continue;
                else if (n->arrive.min<l->arrive.min)
                {
                    p->next = l;
                    n->next = l->next;
                    l->next = n;
                }
            }
        }
    }
}
//void print
//int main()
//{
//    linknode pp;
//    pp = nm();
//    nr(pp);
//    return 0;
//}
