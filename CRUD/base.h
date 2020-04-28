#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all(PEOPLE[]); //2
void add_a_record(PEOPLE[]); //1

void update_date(PEOPLE[]); // 3
void delete(PEOPLE[]); // 4
void load_Date(PEOPLE[]); // 6
void save_to_txt(PEOPLE[]); // 7
void overwrite_from_txt(PEOPLE[]); // 8

void get_date(PEOPLE[], int n);

void clear_buffer(void);
int get_lines(char filename[]);
#endif
