#include <stdio.h>
#include <time.h>
#include <windows.h>

int get_current_time()
{
    time_t t, val = 1;
    struct tm *current_time;

    t = time(NULL);
    current_time = localtime(&t);
    printf("%d:%d:%d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    return current_time;
}