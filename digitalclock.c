#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>


char get_current_time()
{
    time_t t, val = 1;
    struct tm *current_time;

    t = time(NULL);
    current_time = localtime(&t);
    char str = ("%d:%d:%d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    printf("%s", str);

    return str;
}

int convert_12_to_24(char *str){

    printf("String inside method: %s\n", str);
    
    char h1 = str[0];
    char h2 = str[1];
    char hhc[2] = {h1, h2};
    int hhi = atoi(hhc);

    char m1 = str[3];
    char m2 = str[4];
    char mmc[2] = {m1, m2};
    int mmi = atoi(mmc);

    char s1 = str[6];
    char s2 = str[7];
    char ssc[2] = {s1, s2};
    int ssi = atoi(ssc);

    printf("h1h2 m1m2 s1s2: %c%c %c%c %c%c\n", h1, h2, m1, m2, s1, s2);
    printf("%d %d %d\n", hhi, mmi, ssi);

    char hours[3];
    char minutes[3];
    char seconds[3];
    bool isPM;


    for (int i = 0; i < 10; i++) {
        printf("character: %c, index: %d\n", str[i], i);
        if (i == 0 | i == 1){
            hours[i] = str[i];
        } else if (i == 3 | i == 4){
            minutes[i - 3] = str[i];
        } else if (i == 6 | i == 7){
            seconds[i - 6] = str[i];
        } else if (i == 8){
            if (str[i] == 'A'){
                isPM = false;
            } else if (str[i] == 'P'){
                isPM = true;
            }
        }
    }

    printf("Hours: %s\n", hours);
    printf("Minutes: %s\n", minutes);
    printf("Seconds: %s\n", seconds);

    // if (str[8] == 'A'){
    //     if (hh == 12){
    //         printf("00");
    //         for (int i = 2; i <= 7; i++){
    //             printf("%c", str[i]);
    //         }
    //     } else {
    //         for (int i = 0; i <= 7; i++){
    //             printf("%c", str[i]);
    //         }
    //     }
    // } else {
    //     if (hh == 12){
    //         printf("12");
    //         for (int i = 2; i <= 7; i++){
    //             printf("%c", str[i]);
    //         }
    //     } else {
    //         hh += 12;
    //         printf("%c", hh);
    //         for (int i = 2; i <= 7; i++){
    //             printf("%c", str[i]);
    //         }
    //     }
    // }
}

int main(){
    // printf("Current time is: " + get_current_time());
    char str[10] = "12:05:45PM";
    convert_12_to_24(str);
}