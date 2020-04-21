#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(PEOPLE records[]) {
    // Find PEOPLE non-null people at the end
    while (strcmp(records[current_number].name, "null") == 0) {
	current_number--;
    }
    for (int i = 1; i < current_number; i++) {

	if (strcmp(records[i].name, "null") == 0) {
	    //swap
	    PEOPLE* p = records + i;
	    records[i] = records[current_number];
	    records[current_number] = *p;
	    current_number--;
	}
    }
    printf("defragment succeed\n");

    return 1;    
}

// Function: sort()
// Input: 
// Output: 
// 
void sort(PEOPLE records[]) {
    for (int i = 2; i <= current_number; i++) {
	// Insertion Sort
	PEOPLE temp = records[i];
	int j = i - 1;
	while (j > 0 && temp.age < records[j].age) {
	    records[j + 1] = records[j];
	    j--;
	}
	records[j + 1] = temp;
    }
    printf("Sorting Is Complete\n");
    return;
}
// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// The Name Is Entered And All Information Of The Person Is Printed Out
void Search(PEOPLE records[]) {
    char name[NAME_SIZE];
    printf("Type Your Name: ");
    scanf("%s", name);
    ClearBuffer();
    for (int i = 1; i <= current_number; i++) {
	if (strcmp(name, records[i].name) == 0) {
	    printf("%s\t%d\t%c\t%d-%02d-%02d\t%d-%02d-%02d\n", records[i].name, records[i].age, records[i].gender,
		    records[i].registeration_Date.year, records[i].registeration_Date.month, records[i].registeration_Date.mday,
		    records[i].Expiration_Date.year, records[i].Expiration_Date.month, records[i].Expiration_Date.mday);
	    return;
	}
    }
    printf("There Is No One Named %s\n", name);


}
// Function: Service()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// Give bonus Month, as service.
void Service(PEOPLE records[]) {
    if (current_number < 1) {
	printf("There Are No Members\n");
	return;
    }

    int service_month = 0;
    // Get service_month
    while (1) {
	printf("How Many Month Will You Give?\n");
	scanf("%d", &service_month);
	ClearBuffer();
	if (service_month < 1 || service_month > 12) {
	    printf("Please Try Again.\n");
	}
	break;
    }

    for (int i = 1; i <= current_number; i++) {
	records[i].Expiration_Date.month = records[i].Expiration_Date.month + service_month;
	// calculation
	if (records[i].Expiration_Date.month > 12) {
	    records[i].Expiration_Date.year++;
	    records[i].Expiration_Date.month = records[i].Expiration_Date.month - 12;
	}

    }
    printf("Service Complete\n");
}
