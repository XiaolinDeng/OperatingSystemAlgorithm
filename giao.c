
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void fileInput();
void isFinish();
int isSafe();
void tryChange(int);
void backChange(int);
void firstApply();
void display();
void apply();

#define MAX 100
int M,N,down=0;//进程数和资源种数,down是执行完成的进程数
int need[MAX][MAX];//还需要的资源数
int avalable[MAX];//某类资源的可用量
int max[MAX][MAX];//进程 i 对资源 j 的最大需求量
int allocate[MAX][MAX]={0};//进程 i 已占有的 j 类资源量
int finish[MAX]={0};
int request[MAX][MAX];
int Flag[MAX]={0};//进程是否满足全部所需资源
int Safe[MAX];

int main() {
    fileInput();
    firstApply();
    apply();
    return 0;
}

void fileInput(){
    int m=0,n=0;
    FILE *fp;
    fp=fopen("..\\max.txt","r");
    if(!fp)
    {
        printf("\n文件打开失败！");
        exit(1);
    }
    printf("请输入资源种类:");
    fscanf(fp,"%d",&N);
    printf("%d\n",N);
    printf("请输入进程个数:");
    fscanf(fp,"%d",&M);
    printf("%d\n",M);
    printf("请输入%d类资源的初始量:",N);
    for(int i=0;i<N;i++){
        fscanf(fp,"%d",&avalable[i]);
        printf("%d ",avalable[i]);
    }
    printf("\n");
    printf("\n请输入 %d 个进程的:\n",M);
    printf("进程名\t\t 最大需求量\n");
    printf("\t\t");
    for(int i=0;i<N;i++)
        printf("%c   ",65+i);
    for(m=1;m<=M;m++)
    {
        printf("\n进程p[%d]\t ",m);
        for(n=0;n<N;n++)
        {
            fscanf(fp,"%d",&max[m][n]);
            need[m][n]=max[m][n];
            printf("%d   ",max[m][n]);
        }
    }
    fclose(fp);
}

void isFinish(){
    int i,j,flag;
    for(i=1;i<=M;i++)
    {
        if(finish[i]==0)
        {
            flag=1;
            for(j=0;j<N;j++)
            {
                if(need[i][j]!=0)//有进程还有尚需资源即未完成
                    flag=0;
            }
            if(flag==1)
            {
                finish[i]=1;
                down++;
                for(j=0;j<N;j++)//结束后把占用的资源还给系统
                    avalable[j]=avalable[j]+allocate[i][j];
            }
        }
    }
}

int isSafe(){
    isFinish();
    int WORK[MAX],FINISH[MAX]={0};
    int i,j,n,k=0,count;
    for(j=0;j<N;j++)
        WORK[j]=avalable[j];//把可利用资源数赋给WORK[]
    for(i=1;i<=M;i++)
    {
        if(finish[i]==0){
            count=0;
            for(j=0;j<N;j++)
                if(FINISH[i]==0 && need[i][j]<=WORK[j])
                    count++;
            if(count==N)//当进程各类资源都满足need<=WORK时
            {
                for(n=0;n<N;n++)
                    WORK[n]=WORK[n]+allocate[i][n];
                FINISH[i]=1;
                Safe[k]=i;//记录下满足条件的进程
                k++;
                i=0;
            }}
    }
    for(i=1;i<=M;i++)
        if(finish[i]==0 && FINISH[i]==0)
        {
            printf("无安全序列，申请不成功！");
            return 1;
        }
    printf("申请成功!安全序列为:");
    for(i=0;i<M-down;i++)//打印安全系统的进程调用顺序
    {
        if (finish[Safe[i]] == 0)
        {
            printf("p[%d]",Safe[i]);
            if(i<M-down-1)
                printf("->");
        }
    }
    return 0;
}

void tryChange(int k)
{
    int j;
    for(j=0;j<N;j++)
    {
        avalable[j]=avalable[j]-request[k][j];
        allocate[k][j]=allocate[k][j]+request[k][j];
        need[k][j]=need[k][j]-request[k][j];
    }
}

void backChange(int k)
{
    int j;
    for(j=0;j<N;j++)
    {
        avalable[j]=avalable[j]+request[k][j];
        allocate[k][j]=allocate[k][j]-request[k][j];
        need[k][j]=need[k][j]+request[k][j];
    }
}

void display(){
    int m,n;
    printf("\n进程名\t    最大需求量\t    尚需求量\t     已分配量\t    执行结束否");
    printf("\n\t   ");
    for(int i=0;i<N;i++)
        printf("%c   %c   %c\t",65,65+1,65+2);
    for(m=1;m<=M;m++) {
        n=0;
        printf("\n进程p[%d]   ", m);
        printf(" %d   %d   %d\t %d   %d   %d\t %d   %d   %d",
               max[m][n],max[m][n+1],max[m][n+2],need[m][n],need[m][n+1],
               need[m][n+2],allocate[m][n],allocate[m][n+1],allocate[m][n+2]);
        if(finish[m]==1)
            printf("\tfinished");
        else
            printf("\tworking");
    }
    printf("\n资源剩余数： %d  %d  %d",avalable[0],avalable[1],avalable[2]);
}

void firstApply(){
    int m,n;
    FILE *fp;
    fp=fopen("..\\firstapply.txt","r");
    printf("\n请输入 %d 个进程的:\n",M);
    printf("进程名\t\t 第一次的申请量\n");
    printf("\t\t");
    for(int i=0;i<N;i++)
        printf("%c   ",65+i);
    for(m=1;m<=M;m++)
    {
        printf("\n进程p[%d]\t ",m);
        for(n=0;n<N;n++)
        {
            fscanf(fp,"%d",&request[m][n]);
            if(request[m][n]>need[m][n])
            {
                printf("当前资源申请中%c类资源申请量大于该进程最大需求量！",65+n);
            }
            else
            {
                if(request[m][n]>avalable[n])
                {
                    printf("当前申请量超过系统可用资源,您%c类资源可用量为%d。\n",65+n,avalable[n]);
                }
            }
            printf("%d   ",request[m][n]);
        }
        printf("\n");
        tryChange(m);
        if(isSafe())
            backChange(m);
    }
    display();
}

void apply(){
    int m,n,flag;
    char ch;
    FILE *fp=fopen("..\\apply.txt","r");
    printf("\n是否需要再申请资源？（Y/N）");
    while ((fscanf(fp,"%c",&ch)!=EOF) && (ch=='Y' || ch=='y'))
    {
        printf("%c\n",ch);
        m=0;
        printf("请输入进程编号（1-%d）:",M);
        fflush(stdin);
        while(fscanf(fp,"%d",&m))
        {
            printf("%d",m);
            if(m<=0 || m>M)
                printf("\n输入的进程号不存在，请重新输入!\n");
            else//输入正常则退出进程号输入的循环
                break;
        }
        printf("\n请输入进程p[%d]对%d类资源的申请量:\n",m,N);
        while(1)
        {
            flag=0;
            for(n=0;n<N;n++)
            {
                fscanf(fp,"%d",&request[m][n]);
                printf("%d  ",request[m][n]);
            }
            printf("\n");
            for(n=0;n<N;n++)
            {
                if(request[m][n]>need[m][n])
                {
                    printf("当前资源申请中%c类资源申请量大于该进程最大需求量!\n",65+n);
                    flag=1;
                }
                else
                {
                    if(request[m][n]>avalable[n])
                    {
                        printf("资源申请超过系统可用,%c类资源仅%d可用.\n",65+n,avalable[n]);
                        flag=1;
                    }
                }
                if(flag)
                {
                    printf("请重新输入这个进程的申请信息！\n");
                    break;
                }
            }
            if(flag==0)
                break;
        }
        tryChange(m);
        if(isSafe())//不安全则取消本次分配
            backChange(m);
        display();
        printf("\n");
        printf("\n是否需要再申请资源？（Y/N）");
        fgetc(fp);//读取换行符
    }
    printf("%c",ch);
    fclose(fp);
}