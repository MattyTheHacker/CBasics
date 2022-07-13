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
    
    // get hour from string
    char h1 = str[0];
    char h2 = str[1];
    char hhh[3] = {h1, h2, '\0'};
    int hhi = atoi(hhh);

    // get minute from string
    char m1 = str[3];
    char m2 = str[4];
    char mmm[3] = {m1, m2, '\0'};
    int mmi = atoi(mmm);

    // get second from string
    char s1 = str[6];
    char s2 = str[7];
    char sss[3] = {s1, s2, '\0'};
    int ssi = atoi(sss);


    // get AM/PM from string
    bool isPM;
    if (str[8] == 'A') {
        isPM = false;
    } else if (str[8] == 'P') {
        isPM = true;
    } else {
        printf("Invalid time format\n");
        return -1;
    }

    // check time format is correct (hh:mm:ssXX)
    if (hhi > 12){
        printf("Invalid time format\n");
        return -1;
    } else if (mmi > 59){
        printf("Invalid time format\n");
        return -1;
    } else if (ssi > 59){
        printf("Invalid time format\n");
        return -1;
    }


    // print initial input time
    if (isPM) {
        printf("12 Hour String Provided: %d:%d:%dPM\n", hhi, mmi, ssi);
    } else {
        printf("12 Hour String Provided: %d:%d:%dAM\n", hhi, mmi, ssi);
    }
    


    // convert to 24 hour format
    if (hhi < 12 && isPM){
        hhi += 12;
    } if (hhi == 12 && !isPM){
        hhi = 0;
    }
    

    // convert to string
    char str_24[9] = {'\0'};
    sprintf(str_24, "%02d:%02d:%02d", hhi, mmi, ssi);
    printf("24 hour time output: %s\n", str_24);
    return 0;
}

int main(){
    // printf("Current time is: " + get_current_time());
    char str[10] = "09:15:55PM";
    convert_12_to_24(str);
}