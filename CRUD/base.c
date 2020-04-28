#include "base.h"
#include <stdlib.h>
void print_all(PEOPLE records[]) {
    // TODO: Modify this function as you need
    if (current_number == 0) {
	printf("No one is currently registered\n");
    }
    for (int i = 1; i <= current_number; i++) {
	printf("%s\t%d\t%c\t%d-%02d-%02d\t%d-%02d-%02d\n", records[i].name, records[i].age, records[i].gender,
		records[i].registeration_Date.year, records[i].registeration_Date.month, records[i].registeration_Date.mday,
		records[i].Expiration_Date.year, records[i].Expiration_Date.month, records[i].Expiration_Date.mday);
    }

}
void add_a_record(PEOPLE records[]) {
    // TODO : over flow
    current_number++;

    printf("Enter Name: ");
    scanf("%s", records[current_number].name);
    clear_buffer();

    // Get Age
    while (1) {
	printf("Enter Age:  ");
	int age = 0;
	scanf("%d", &age);
	clear_buffer();
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
	clear_buffer();
	if (ch != 'W' && ch != 'M') {
	    printf("Please Try Again.\n");
	    continue;
	}
	records[current_number].gender = ch;
	break;
    }

    get_date(records, current_number);

    printf("New %s is added.\n", records[current_number].name);

}
void update_date(PEOPLE records[]) {
    char name[NAME_SIZE];

    printf("Whose Information Would You Like To Change?\n");
    printf("Name: ");
    scanf("%s", name);
    clear_buffer();

    for (int i = 1; i <= current_number; i++) {
	if (strcmp(name, records[i].name) == 0) {

	    get_date(records, i);

	    printf("%s Is Updated.\n", records[i].name);
	    return;
	}
    }

    printf("There Is No One Named %s\n", name);
}
void delete(PEOPLE records[]) {
    // Check Current_number
    if (current_number < 1) {
	printf("There Are No Members\n");
	return;
    }
    char name[NAME_SIZE];

    printf("Enter The Name Of The Person You Want To Delete\n");
    printf("Name: ");
    scanf("%s", name);
    clear_buffer();

    for (int i = 1; i <= current_number; i++) {
	if (strcmp(name, records[i].name) == 0) {
	    strcpy(records[i].name, "null");   // Change Name to NULL

	    // Initialize gender, Age
	    records[i].gender = 'M';
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
void load_from_txt(PEOPLE records[]) {
    char filename[20];
    char txt[10] = ".txt";

    printf("Enter the file name : ");
    scanf("%s", filename);
    clear_buffer();

    strcat(filename, txt);
    printf("filename:: %s\n", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
	printf("File Does Not Exist\n");
	exit(0);
    }

    // Number of get_lines in file
    int fileline = get_lines(filename);

    for (int i = 0; i < fileline; i++) {
	current_number++;

	fscanf(fp, "%s %d %c", records[current_number].name, &records[current_number].age, &records[current_number].gender);

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

    }
    printf("Content loaded\n");

    fclose(fp);
}
void overwrite_from_txt(PEOPLE records[]) {
    char filename[20];
    char txt[10] = ".txt";

    printf("Enter the file name : ");
    scanf("%s", filename);
    clear_buffer();

    strcat(filename, txt);
    printf("filename:: %s\n", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
	printf("File Does Not Exist\n");
	exit(0);
    }

    // Number of get_lines in file
    int fileline = get_lines(filename);

    for (int i = 1; i <= fileline; i++) {
	fscanf(fp, "%s %d %c", records[i].name, &records[i].age, &records[i].gender);

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
void save_to_txt(PEOPLE records[]) {
    char filename[20];
    char txt[10] = ".txt";

    printf("Enter the file name : ");
    scanf("%s", filename);
    clear_buffer();

    strcat(filename, txt);
    printf("filename:: %s\n", filename);

    FILE* fp = fopen(filename, "w");

    for (int i = 1; i <= current_number; i++) {

	// 파일에 각 사람의 정보 입력하기.
	fprintf(fp, "%s %d %c ", records[i].name, records[i].age, records[i].gender);
	fprintf(fp, "%d-%d-%d ", records[i].registeration_Date.year, records[i].registeration_Date.month, records[i].registeration_Date.mday);
	fprintf(fp, "%d-%d-%d", records[i].Expiration_Date.year, records[i].Expiration_Date.month, records[i].Expiration_Date.mday);

	if (current_number != i) fprintf(fp, "\n");

    }
    printf("Content Updated\n");

    fclose(fp);
}
void get_date(PEOPLE records[], int n) {
    while (1) {
	printf("Enter Start Year: ");
	int year = 0;
	scanf("%d", &year);
	clear_buffer();
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
	clear_buffer();
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
	clear_buffer();
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
	clear_buffer();
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

    // calculation
    if (want + records[n].registeration_Date.month > 12) {
	records[n].Expiration_Date.year++;
	records[n].Expiration_Date.month -= 12;
    }
    else records[n].Expiration_Date.month += want;


}
void clear_buffer() {
    while (getchar() != '\n');  // Clean Buffer
}
int get_lines(char filename[]) {
    FILE* fp;
    int line = 1;
    fp = fopen(filename, "r");
    char c;
    while ((c = fgetc(fp)) != EOF)
	if (c == '\n') line++;

    fclose(fp);
    return line;
}
