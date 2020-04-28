#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"

#define MAX_RECORDS 1000

void input_handler(char[], PEOPLE[]);
void display_menu();
void load_from_txt(PEOPLE records[]);

int main() {
    PEOPLE records[MAX_RECORDS];
    char user_input[64] = "";
    while (strcmp(user_input, "99") != 0) {
	display_menu();
	printf("\nSelect a menu> ");
	fgets(user_input, 64, stdin);
	user_input[strlen(user_input) - 1] = '\0';
	input_handler(user_input, records);
    }

    return 0;
}

void input_handler(char input[], PEOPLE records[]) {

    // TODO: Modify this function as you need

    if (!strcmp(input, "1"))         // ok
	add_a_record(records);
    else if (!strcmp(input, "2"))    // ok
	print_all(records);
    else if (!strcmp(input, "3"))    // ok
	update_date(records);
    else if (!strcmp(input, "4"))    // ok 
	delete(records);
    else if (!strcmp(input, "5"))    // ok
	search(records);
    else if (!strcmp(input, "6"))    // ok
	load_from_txt(records);
    else if (!strcmp(input, "7"))    // ok
	overwrite_from_txt(records);
    else if (!strcmp(input, "8"))    // ok
	save_to_txt(records);
    else if (!strcmp(input, "9"))    // ok
	defragment(records);
    else if (!strcmp(input, "10"))   // ok
	sort(records);
    else if (!strcmp(input, "11"))   // ok
	service(records);
    else if (!strcmp(input, "99"))
	printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
    else
	printf("Unknown menu: %s \n\n", input);
}


void display_menu() {
    printf("******************************\n");
    printf("Fitness club management system\n");
    printf("******************************\n");
    printf(" 1. add a new membber\n");
    printf(" 2. print all members\n");
    printf(" 3. update member information\n");
    printf(" 4. delete a member\n");
    printf(" 5. search a member\n");
    printf(" 6. load a new data from .txt\n");
    printf(" 7. overWrite a new data from .txt\n");
    printf(" 8. save data to .txt file\n");
    printf(" 9. optimize (defragment) the records\n");
    printf(" 10. sort by age\n");
    printf(" 11. service (give all member a month)\n");
    printf(" 99. quit\n");
}
