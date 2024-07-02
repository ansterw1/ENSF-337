// ENSF 337 - Lab 3 Exercise E
//  lab3exe_E.h

#ifndef lab3ExE_h
#define lab3ExE_h

typedef struct Date {
    int day, month, year;
}Date;

typedef struct Time {
    int second, minute, hour;
}Time;

typedef struct Timestamp{
    Date date;
    Time *time;
}Timestamp;


void change_date_time(Date *d, Time *t);

#endif /* lab3ExE_h */
