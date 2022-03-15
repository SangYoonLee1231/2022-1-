#include <stdio.h>

int main(void)
{
    int hour, min;
    int time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    time = hour * 60 + min;
    
    // 8:00 a.m. => 480 min
    // 9:43 a.m. => 583 min
    // 11:19 a.m. => 679 min
    // 12:47 p.m. => 767 min
    // 2:00 p.m. => 840 min
    // 3:45 p.m. => 945 min
    // 7:00 p.m. => 1140 min
    // 9:45 p.m. => 1305 min

    if(time < 532) {
        print("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.");
    }
    else if(time < 631) {
        print("Closet departure time is 9:43 a.m., arriving at 11:52 p.m.");
    }
    else if(time < 723) {
        print("Closet departure time is 11:19 a.m., arriving at 1:31 p.m.");
    }
    else if(time < 804) {
        print("Closet departure time is 12:47 p.m., arriving at 3:00 p.m.");
    }
    else if(time < 877) {
        print("Closet departure time is 2:00 p.m., arriving at 4:08 p.m.");
    }
    else if(time < 1043) {
        print("Closet departure time is 3:45 p.m., arriving at 5:55 p.m.");
    }
    else if(time < 1223) {
        print("Closet departure time is 7:00 p.m., arriving at 9:20 p.m.");
    }
    else {
        print("Closet departure time is 9:45 p.m., arriving at 11:58 p.m.");
    }

    return 0;
}