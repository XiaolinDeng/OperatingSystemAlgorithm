//
// Created by xiaolin on 2019/4/17.
//

#ifndef OS_MYTIME_H
#define OS_MYTIME_H

typedef struct data
{
    int hour;
    int min;
    int value;
}time;

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

#endif //OS_MYTIME_H
