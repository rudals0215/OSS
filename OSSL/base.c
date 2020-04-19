#include "base.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Print All Information Of People.
void print_all_records(PEOPLE records[]) {
        // TODO: Modify this function as you need
        if (current_number == 0) {
                    printf("No one is currently registered\n");
                        }
            for (int i = 1; i <= current_number; i++) {
                        printf("%s\t%d\t%c\t%d-%02d-%02d\t%d-%02d-%02d\n", records[i].name, records[i].age, records[i].sex,
                                                records[i].registeration_Date.year, records[i].registeration_Date.month, records[i].registeration_Date.mday,
                                                                records[i].Expiration_Date.year, records[i].Expiration_Date.month, records[i].Expiration_Date.mday);
                            }
                
}

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Add People
void add_a_record(PEOPLE records[]) {
        // TODO : over flow
        current_number++;

            printf("Enter Name: ");
                scanf("%s", records[current_number].name);
                    ClearBuffer();

                        // Get Age
                        while (1) {
                                    printf("Enter Age:  ");
                                            int age = 0;
                                                    scanf("%d", &age);
                                                            ClearBuffer();
                                                                    if (age < 0 || age > 100) {
                                                                                    printf("Please Try Again.\n");
                                                                                                continue;
                                                                                                        }
                                                                            records[current_number].age = age;
                                                                                    break;
                                                                                        }

                            while (1) {
                                        printf("Enter W or M: ");
                                                char ch;
                                                        scanf("%c", &ch);
                                                                ClearBuffer();
                                                                        if (ch != 'W' && ch != 'M') {
                                                                                        printf("Please Try Again.\n");
                                                                                                    continue;
                                                                                                            }
                                                                                records[current_number].sex = ch;
                                                                                        break;
                                                                                            }

                                Get_Date(records,current_number);
                                   
                                    printf("New %s is added.\n", records[current_number].name);

}

// Function: Update()
// Input: 
// Output: 
// - Leave a brief information about the function
void Update(PEOPLE records[]) {
        char name[NAME_SIZE];

            printf("Whose Information Would You Like To Change?\n");
                printf("Name: ");
                    scanf("%s", name);
                        ClearBuffer();

                            for (int i = 1; i <= current_number; i++) {
                                        if (strcmp(name, records[i].name) == 0) {
                                                        
                                                        Get_Date(records, i);

                                                                    printf("%s Is Updated.\n", records[i].name);
                                                                                return;
                                                                                        }
                                            }

                                printf("There Is No One Named %s\n", name);
}

// Function: Delete()
// Input: 
// Output: 
// - Leave a brief information about the function
void Delete(PEOPLE records[]) {
        // Check Current_number
        if (current_number < 1) {
                    printf("There Are No Members\n");
                            return;
                                }
            char name[NAME_SIZE];
                
                printf("Enter The Name Of The Person You Want To Delete\n");
                    printf("Name: ");
                        scanf("%s", name);
                            ClearBuffer();

                                for (int i = 1; i <= current_number; i++) {
                                            if (strcmp(name, records[i].name) == 0) {
                                                            strcpy(records[i].name,"null");   // Change Name to NULL
                                                                       
                                                                        // Initialize Sex, Age
                                                                        records[i].sex = 'M';
                                                                                    records[i].age = 99;

                                                                                                // Initialize registeration_Date
                                                                                                records[i].registeration_Date.year = 9999;
                                                                                                            records[i].registeration_Date.month = 99;
                                                                                                                        records[i].registeration_Date.mday = 99;

                                                                                                                                    // Initialize Expiration_Date
                                                                                                                                    records[i].Expiration_Date.year = 9999;
                                                                                                                                                records[i].Expiration_Date.month = 99;
                                                                                                                                                            records[i].Expiration_Date.mday = 99;

                                                                                                                                                                        printf("Delete Complete.\n");
                                                                                                                                                                                    return;
                                                                                                                                                                                            }
                                                }
                                    // current_number--;

                                    printf("There Is No One Named %s\n", name);
}

// Function: load_Date()
// Input: 
// Output: 
//
void load_Data(PEOPLE records[]) {
        FILE* fp = fopen("list.txt", "r");

            // Number of lines in file
            int fileline = lines("list.txt");

                for (int i = 0; i < fileline; i++) {
                            current_number++;

                                    fscanf(fp, "%s %d %c", records[current_number].name, &records[current_number].age, &records[current_number].sex);

                                            fseek(fp, 1, SEEK_CUR);
                                                    fscanf(fp, "%d", &records[current_number].registeration_Date.year);
                                                            fseek(fp, 1, SEEK_CUR);
                                                                    fscanf(fp, "%d", &records[current_number].registeration_Date.month);
                                                                            fseek(fp, 1, SEEK_CUR);
                                                                                    fscanf(fp, "%d", &records[current_number].registeration_Date.mday);

                                                                                            fseek(fp, 1, SEEK_CUR);
                                                                                                    fscanf(fp, "%d", &records[current_number].Expiration_Date.year);
                                                                                                            fseek(fp, 1, SEEK_CUR);
                                                                                                                    fscanf(fp, "%d", &records[current_number].Expiration_Date.month);
                                                                                                                            fseek(fp, 1, SEEK_CUR);
                                                                                                                                    fscanf(fp, "%d", &records[current_number].Expiration_Date.mday);
                                                                                                                                            
                                                                                                                                            //records[temp+i].registeration_Date.year, records[temp+i].registeration_Date.month, records[temp+i].registeration_Date.mday, 
                                                                                                                                            //records[temp+i].Expiration_Date.year , records[temp+i].Expiration_Date.month, records[temp+i].Expiration_Date.mday);

                                                                                                                                        }
                    printf("Content loaded\n");

                        fclose(fp);
}

// Function: over_Write()
// Input: records- array
// Output: none
// Overwrite Contents from .txt file
void load_Data_OverWrite(PEOPLE records[]) {
        FILE* fp = fopen("list.txt", "r");

            // Number of lines in file
            int fileline = lines("list.txt");

                for (int i = 1; i <= fileline; i++) {
                            fscanf(fp, "%s %d %c", records[i].name, &records[i].age, &records[i].sex);

                                    fseek(fp, 1, SEEK_CUR);
                                            fscanf(fp, "%d", &records[i].registeration_Date.year);
                                                    fseek(fp, 1, SEEK_CUR);
                                                            fscanf(fp, "%d", &records[i].registeration_Date.month);
                                                                    fseek(fp, 1, SEEK_CUR);
                                                                            fscanf(fp, "%d", &records[i].registeration_Date.mday);

                                                                                    fseek(fp, 1, SEEK_CUR);
                                                                                            fscanf(fp, "%d", &records[i].Expiration_Date.year);
                                                                                                    fseek(fp, 1, SEEK_CUR);
                                                                                                            fscanf(fp, "%d", &records[i].Expiration_Date.month);
                                                                                                                    fseek(fp, 1, SEEK_CUR);
                                                                                                                            fscanf(fp, "%d", &records[i].Expiration_Date.mday);
                                                                                                                                }
                    current_number = fileline;
                        printf("Content OverWrited\n");

                            fclose(fp);
}

// Function: save_Data()
// Input: records- array
// Output:
// Save The Contents Again as a .txt file
void save_Data(PEOPLE records[]) {
        FILE* fp = fopen("list.txt", "w");

            for (int i = 1; i <= current_number ; i++) {

                        // 파일에 각 사람의 정보 입력하기.
                        fprintf(fp, "%s %d %c ", records[i].name, records[i].age, records[i].sex);
                                fprintf(fp, "%d-%d-%d ", records[i].registeration_Date.year,records[i].registeration_Date.month,records[i].registeration_Date.mday);
                                        fprintf(fp, "%d-%d-%d", records[i].Expiration_Date.year, records[i].Expiration_Date.month, records[i].Expiration_Date.mday);

                                                if(current_number != i) fprintf(fp, "\n");

                                                    }
                printf("Content Updated\n");

                    fclose(fp);
}

void Get_Date(PEOPLE records[], int n) {
        while (1) {
                    printf("Enter Start Year: ");
                            int year = 0;
                                    scanf("%d", &year);
                                            ClearBuffer();
                                                    if (year < 2000 || year>2020) {
                                                                    printf("Wrong Input Please Try Again\n");
                                                                                continue;
                                                                                        }
                                                            records[n].registeration_Date.year = year;
                                                                    break;
                                                                        }

            while (1) {
                        printf("Enter Start Month: ");
                                int month = 0;
                                        scanf("%d", &month);
                                                ClearBuffer();
                                                        if (month < 0 || month>12) {
                                                                        printf("Wrong Input Please Try Again\n");
                                                                                    continue;
                                                                                            }
                                                                records[n].registeration_Date.month = month;
                                                                        break;
                                                                            }

                while (1) {
                            printf("Enter Start mDay: ");
                                    int day = 0;
                                            scanf("%d", &day);
                                                    ClearBuffer();
                                                            if (day > 31 || day < 0) {
                                                                            printf("Wrong Input Please Try Again\n");
                                                                                        continue;
                                                                                                }
                                                                    records[n].registeration_Date.mday = day;
                                                                            break;
                                                                                }

                    int want;
                        while (1) {
                                    printf("How Many Months Do You Want?: ");
                                            scanf("%d", &want);
                                                    ClearBuffer();
                                                            if (want < 0 || want>12) {
                                                                            printf("Wrong Input Please Try Again\n");
                                                                                        continue;
                                                                                                }
                                                                    break;
                                                                        }
                                // Initialization expiration date
                                records[n].Expiration_Date.year = records[n].registeration_Date.year;
                                        records[n].Expiration_Date.month = records[n].registeration_Date.month;
                                                records[n].Expiration_Date.mday = records[n].registeration_Date.mday;

                                                    // Calculation
                                                    if (want + records[n].registeration_Date.month > 12) {
                                                                records[n].Expiration_Date.year++;
                                                                        records[n].Expiration_Date.month -= 12;
                                                                            }
                                                        else records[n].Expiration_Date.month += want;


}
void ClearBuffer() {
        while (getchar() != '\n');  // Clean Buffer
}
int lines(char filename[]) {
        FILE* fp;
            int line = 0;
                fp = fopen(filename, "r");
                    char c;
                        while ((c = fgetc(fp)) != EOF)
                                    if (c == '\n') line++;

                            fclose(fp);
                                return line;
}
