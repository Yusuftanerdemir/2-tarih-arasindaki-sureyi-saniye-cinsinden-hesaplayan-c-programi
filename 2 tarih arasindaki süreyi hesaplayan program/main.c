#include <stdio.h>
#include <time.h>

struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

union EpochTime {
    time_t epoch;
    struct tm tm_time;
};

time_t convertToEpoch(struct DateTime dt) {
    union EpochTime et;
    et.tm_time.tm_year = dt.year - 1900;
    et.tm_time.tm_mon = dt.month - 1;
    et.tm_time.tm_mday = dt.day;
    et.tm_time.tm_hour = dt.hour;
    et.tm_time.tm_min = dt.minute;
    et.tm_time.tm_sec = dt.second;
    et.tm_time.tm_isdst = -1; // Gun isigindan yararlanma bilgisi yok
    return mktime(&et.tm_time);
}

int main() {
    struct DateTime dt1, dt2;
    printf("ilk tarihi ve saati girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);

    printf("ikinci tarihi ve saati girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);

    time_t epoch1 = convertToEpoch(dt1);
    time_t epoch2 = convertToEpoch(dt2);

    double difference = difftime(epoch2, epoch1);

    printf("Epoch zamani (ilk tarih): %ld\n", epoch1);
    printf("Epoch zamani (ikinci tarih): %ld\n", epoch2);
    printf("iki tarih arasindaki fark (saniye): %.f\n", difference);

    return 0;
}
