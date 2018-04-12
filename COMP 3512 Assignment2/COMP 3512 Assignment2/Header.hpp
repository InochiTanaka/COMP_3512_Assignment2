#pragma once

#include "Patient.h"

#include<iostream>
#include <string>
#include <stdio.h>

#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>

#include <string>
#include <cstring>
#include <sstream>

#define PIN_LENGTH = 8;
#define MAX_RESERVATION_MONTH = 3;
#define NUM_MONTH_ON_YEAR = 12;


class PriorityQueue 
{
	private:
		static const int days_in_regular_year[];
		static const int days_in_leap_year[];

	public:
		bool input();
		Patient inputRegisterTime(Patient p);
		time_t getAdmissionTime(int y, int mon, int d, int h, int min);
		Patient inputPatientName(Patient p);
		Patient inputPatientBirthday(Patient p);
		Patient inputPatientPIN(Patient p);
		Patient inputPatientSymptoms(Patient p);
		Patient inputPatientCategory(Patient p);
		bool checkValidBirthDay(int y, int m, int d);
		bool checkValidTime(int h, int min);
};

