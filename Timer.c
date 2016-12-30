//THis program is a timer
//User inputs a start time and an end time
//DAQ module 7 segment display will count down the time per second until it reaches the end time


#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <DAQlib.h>
#include <math.h>

#define SWITCH_0 0
#define SWITCH_1 1
#define ON 1
#define TRUE 1
#define OFF 0
#define FALSE 0

void writetime (int, int);
int main (void) {

	if (setupDAQ(4) == TRUE) {

	//	while (continueSuperLoop () == TRUE) {

			int stop = 0;
			int start = 0;
		
			printf("THIS IS A TIMER (PER SECOND. YOUR START TIME MUST BE HIGHER THAN YOUR FINAL TIME");
			printf ("Enter an integer start value: ");
			scanf ("%d", &start);

			printf ("Enter a integer stop value: ");
			scanf ("%d", &stop);

			while ((digitalRead(0) == TRUE) || (digitalRead(1) == TRUE)) {

				printf("Turn off switch one and switch two.");
				Sleep (1000);
			}

		while (start >= stop) {

			writetime(start, stop); 
			Sleep (1000);
			start--;
		}
	}

	else {
		printf("Error");

	}

system("PAUSE");
return 0;
}

void writetime (int starttime, int stopttime) {
	//checking how many numbers there are in starttime

int i;
int num;
int ten;

	static int digits[] = {258, 96, 218, 242, 102, 182, 190, 224, 254, 246};

	for (i = 0; i < 8; i++) {

		if (starttime/10 <= 0) {
			displayWrite(digits[starttime], i);
			break;
		}
		else {
		num = starttime%10;
		displayWrite(digits[num], i);
		starttime = (starttime/10);
		}

	}
}

