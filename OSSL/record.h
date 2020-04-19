#ifndef _RECORD_H_
#define _RECORD_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_SIZE 20

int current_number; // Current Number Of People

typedef struct {
        int year;
            int month;
                int mday;
} DATE;

typedef struct {
        char name[NAME_SIZE];
            int age;
                char sex;  // M: man, W: woman

                    DATE registeration_Date; // Registeration Date
                        DATE Expiration_Date;  // Expiration_Date 
} PEOPLE;


#endif
