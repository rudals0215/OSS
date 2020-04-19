#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all_records(PEOPLE[]); //2
void add_a_record(PEOPLE[]); //1

void Update(PEOPLE[]); // 3
void Delete(PEOPLE[]); // 4
void load_Date(PEOPLE[]); // 6
void save_Data(PEOPLE[]); // 7
void load_Data_OverWrite(PEOPLE[]); // 8

void Get_Date(PEOPLE[], int n);

//void swap();
void ClearBuffer(void);
int lines(char filename[]);
#endif
