
#include <stdio.h>

#define DAY 11
#define MONTH 3
#define YEAR 1982

int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap(int year) {

	if (year % 4 == 0) {
	
		if (year % 400 == 0) {
		
			return 1;
		}

		if (year % 100 == 0) {
		
			return 0;
		}

		return 1;
	} 
	
	return 0;
}

int leap_num(int year) {

	int i;
	int total = 0;


	for (i = 1; i <= year; i++) {
	
		if (is_leap(i)) {
		
			total++;
		}
	}

	return total;
}

int main() {
	
	int leap = leap_num(YEAR - 1);
	int non_leap = (YEAR - 1) - leap;
	int days = 0;
	int i;

	//Add all the days total besides the current specified year
	for (i = 0; i < 12; i ++) {
	
		//if feb
		if (i == 1) {
			
			days += (leap * 29) + (non_leap * m[i]);
			
		} else {

			days += (YEAR - 1) * m[i];
		}
	}

	//Add all the days in the current year besides the current month to the total so far
	if (MONTH > 1) {
		
		for (i = 0; i < MONTH - 1; i++) {
		
			// if FEB
			if (i == 1) {
				
				if (is_leap(YEAR)) {
					
					days += m[i] + 1;

				} else {
				
					days += m[i];
				}
			
			} else {

				days += m[i];
			}
		}
	}
	
	//Add the days in the current month to the total
	days += DAY;

	int d = days % 7;

	switch (d) {
		
		case 1:
			puts("monday");
		break;
		
		case 2:
			puts("tuesday");
		break;

		case 3:
			puts("wednesday");
		break;

		case 4:
			puts("thursday");
		break;

		case 5:
			puts("friday");
		break;

		case 6:
			puts("saturday");
		break;

		case 0:
			puts("sunday");
		break;
	}

	return 0;
}

