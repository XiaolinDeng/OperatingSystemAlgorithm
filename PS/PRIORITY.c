//
// Created by dxl on 19-3-31.
//

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

