/* -*- mode:c; c-file-style:"k&r"; c-basic-offset: 4; tab-width:4; indent-tabs-mode:nil; mode:auto-fill; fill-column:78; -*- */
/* vim: set ts=4 sw=4 et tw=78 fo=cqt wm=0: */

#include "pal.h"
#include "pal_debug.h"
#include "api.h"

int main (int argc, const char ** argv, const char ** envp)
{
    unsigned long time1 = DkSystemTimeQuery();
    unsigned long time2 = DkSystemTimeQuery();

    pal_printf("Time Query 1: %lld\n", time1);
    pal_printf("Time Query 2: %lld\n", time2);

    if (time1 <= time2)
        pal_printf("Query System Time OK\n");

    unsigned long time3 = DkSystemTimeQuery();
    DkThreadDelayExecution(10000);
    unsigned long time4 = DkSystemTimeQuery();

    pal_printf("Sleeped %lld Microseconds\n", time4 - time3);

    if (time3 < time4 && time4 - time3 > 10000)
        pal_printf("Delay Execution for 10000 Microseconds OK\n");

    unsigned long time5 = DkSystemTimeQuery();
    DkThreadDelayExecution(3000000);
    unsigned long time6 = DkSystemTimeQuery();

    pal_printf("Sleeped %lld Microseconds\n", time6 - time5);

    if (time5 < time6 && time6 - time5 > 3000000)
        pal_printf("Delay Execution for 3 Seconds OK\n");

    unsigned long data[100];
    memset(data, 0, sizeof(data));

    for (int i = 0 ; i < 100 ; i++)
        DkRandomBitsRead(&data[i], sizeof(unsigned long));

    bool same = false;
    for (int i = 1 ; i < 100 ; i++)
        for (int j = 0 ; j < i ; j++)
            if (data[i] == data[j]) same = true;

    if (!same)
        pal_printf("Generate Random Bits OK\n");

    return 0;
}

