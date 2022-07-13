#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>


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
    // char hhc[2] = {h1, h2};
    char hhh[3] = {h1, h2, '\0'};
    // strcat(hhh, strcat(h1, h2));
    int hhi = atoi(hhh);

    char m1 = str[3];
    char m2 = str[4];
    char mmm[3] = {m1, m2, '\0'};
    int mmi = atoi(mmm);
    // char mmc[2] = {m1, m2};
    // int mmi = atoi(strcat(m1, m2));

    char s1 = str[6];
    char s2 = str[7];
    char sss[3] = {s1, s2, '\0'};
    int ssi = atoi(sss);
    // char ssc[2] = {s1, s2};
    // int ssi = atoi(strcat(s1, s2));

    bool isPM;

    if (str[8] == 'A') {
        isPM = false;
    } else if (str[8] == 'P') {
        isPM = true;
    } else {
        printf("Invalid time format\n");
        return -1;
    }

    printf("h1h2 m1m2 s1s2: %c%c %c%c %c%c\n", h1, h2, m1, m2, s1, s2);
    // printf("hhc mmc ssc: %c %c %c\n", hhh, mmm, sss);
    printf("hhi mmi ssi: %d %d %d\n", hhi, mmi, ssi);

    printf("hours: %d\n", hhi);
    printf("minutes: %d\n", mmi);
    printf("seconds: %d\n", ssi);
    printf("isPM: %d\n", isPM);


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