#pragma once

#include "Patient.h"

#include<iostream>
#include <string>
#include <stdio.h>

#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>

#define MAX_RESERVATION_MONTH = 3;
#define NUM_MONTH_ON_YEAR = 12;

class PriorityQueue 
{
	private:

	public:
		//bool input();
		Patient inputReservationDate(Patient p);
		//void inputReservationDate();
		time_t getAdmissionTime(int y, int mon, int d, int h, int min);
		bool input();
		bool checkValidDateAndTime(int y, int mon, int d, int h, int min);
};

