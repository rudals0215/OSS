#include <stdio.h>
#include <string.h>

#include "base.h"
#include "extras.h"
//#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], PEOPLE[]);
void display_menu();
void load_Data(PEOPLE records[]);
// main function
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


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], PEOPLE records[]) {

        // TODO: Modify this function as you need

        if (!strcmp(input, "1"))         // ok
                    add_a_record(records);
            else if (!strcmp(input, "2"))    // ok
                        print_all_records(records);
                else if (!strcmp(input, "3"))    // ok
                            Update(records);
                    else if (!strcmp(input, "4"))    // ok 
                                Delete(records);
                        else if (!strcmp(input, "5"))    // ok
                                    Search(records);
                            else if (!strcmp(input, "6"))    // ok
                                        load_Data(records);
                                else if (!strcmp(input, "7"))    // ok
                                            load_Data_OverWrite(records);
                                    else if (!strcmp(input, "8"))    // ok
                                                save_Data(records);
                                        else if (!strcmp(input, "9"))    // ok
                                                    defragment(records);
                                            else if (!strcmp(input, "10"))   // ok
                                                        sort(records);
                                                else if (!strcmp(input, "11"))   // ok
                                                            Service(records);
                                                    else if (!strcmp(input, "99"))
                                                                printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
                                                        else
                                                                    printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// Show  Menu
void display_menu() {
        printf("******************************\n");
            printf("Fitness club management system\n");
                printf("******************************\n");
                    printf(" 1. Add a new membber\n");
                        printf(" 2. Print all members\n");
                            printf(" 3. Update member information\n");
                                printf(" 4. Delete a member\n");
                                    printf(" 5. Search \n");
                                        printf(" 6. Load a new data from .txt\n");
                                            printf(" 7. OverWrite a new data file\n");
                                                printf(" 8. Save data to .txt file\n");
                                                    printf(" 9. Optimize (defragment) the records\n");
                                                        printf(" 10. Sort \n");
                                                            printf(" 11. Service (give all member a month)\n");
                                                                printf(" 99. Quit\n");
}
