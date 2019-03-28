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
char buf[1000000];


linknode sasnm()
{
//  define all data should input from keyboard
    char nameIn[20];
    int idIn,arriveHour,arriveMin,exHour,exMin;
    linknode head,p,l;
    head = NULL;
    printf("input");
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
    printf("input");
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
        printf("input");
        scanf("%d %s %d %d %d %d",&idIn,&nameIn,&arriveHour,&arriveMin,&exHour,&exMin);
    }
    p->next = NULL;
    while(head != NULL)
    {
        printf("id=%d\n",head->id);
        head = head->next;
    }
    return head;
}
//int nmb()
//{
//    FILE *fin;
//    char *p;
//    fin = fopen("test.txt", "r");
//    while (!feof(fin))
//    {
//        fgets(buf, 1000000, fin); //读取文件中的一行到buf中
//// strtok函数用于分割buf中的字符串，分割符号都写在第二个参数中
//        for (p = strtok(buf, " \t"); p; p = strtok(NULL, " \t")) {
//            if(strcmp('-1',p)) break;
//            printf("%s\n", p);
//        }
//        if(p!='-1') printf("line finish!\n");
//    }
//    fclose(fin);
//    return 0;
//}

#include <stdio.h>
#include <string.h>
char buf[1000000];
//int main()
//{
//    FILE *fin;
//    char *p;
//    fin = fopen("test.txt", "r");
//    while (!feof(fin))
//    {
//        fgets(buf, 1000000, fin); //读取文件中的一行到buf中
//// strtok函数用于分割buf中的字符串，分割符号都写在第二个参数中
//        for (p = strtok(buf, "\t\r\n"); p; p = strtok(NULL, "\t\r\n")) {
//            if(strcmp("-1",p))  printf("%s\n", p);
//        }
//    }
//    fclose(fin);
//}

void blinksort(linknode unsortLink)
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
            if(next->arrive.hour<last->arrive.hour) continue;
            else if (next->arrive.hour>last->arrive.hour)
            {
                pre->next = last;
                next->next = last->next;
                last->next = next;
            }
            else
            {
                if(next->arrive.min<=last->arrive.min) continue;
                else
                {
                    pre->next = last;
                    next->next = last->next;
                    last->next = next;
                }
            }
        }
    }
}