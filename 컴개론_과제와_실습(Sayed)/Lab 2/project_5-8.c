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

    // When the closet departure time is 8.00 a.m.
    // (480 + 583) / 2 = 531.5
    // 0 <= time < 531.5
    if(time < 531.5) {
        printf("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.");
    }
    // When the closet departure time is 9.43 a.m.
    // (583 + 679) / 2 = 631
    // 531.5 <= time < 631
    else if(time < 631) {
        printf("Closet departure time is 9:43 a.m., arriving at 11:52 p.m.");
    }
    // When the closet departure time is 11:19 a.m.
    // (679 + 767) / 2 = 723
    // 631 <= time < 723
    else if(time < 723) {
        printf("Closet departure time is 11:19 a.m., arriving at 1:31 p.m.");
    }
    // When the closet departure time is 12:47 p.m.
    // (767 + 840) / 2 = 803.5
    // 723 <= time < 803.5
    else if(time < 803.5) {
        printf("Closet departure time is 12:47 p.m., arriving at 3:00 p.m.");
    }
    // When the closet departure time is 2:00 p.m.
    // (840 + 945) / 2 = 892.5
    // 803.5 <= time < 892.5
    else if(time < 892.5) {
        printf("Closet departure time is 2:00 p.m., arriving at 4:08 p.m.");
    }
    // When the closet departure time is 3:45 p.m.
    // (945 + 1140) / 2 = 1042.5
    // 892.5 <= time < 1042.5
    else if(time < 1042.5) {
        printf("Closet departure time is 3:45 p.m., arriving at 5:55 p.m.");
    }
    // When the closet departure time is 7:00 p.m.
    // (1140 + 1305) / 2 = 631
    // 1042.5 <= time < 1223
    else if(time < 1223) {
        printf("Closet departure time is 7:00 p.m., arriving at 9:20 p.m.");
    }
    // When the closet departure time is 9:45 p.m.
    // 1223 <= time
    else {
        printf("Closet departure time is 9:45 p.m., arriving at 11:58 p.m.");
    }

    return 0;
}