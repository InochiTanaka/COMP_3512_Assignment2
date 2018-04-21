#pragma once

#include "Patient.h"
//#include "PriorityQueue.hpp"
//#include "PriorityLevel.hpp"

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

#include <vector>
#include <deque>

#define PIN_LENGTH = 8;
#define MAX_RESERVATION_MONTH = 3;
#define NUM_MONTH_ON_YEAR = 12;


// Inochi's

class HosptialUI
{
private:
	static const int days_in_regular_year[];
	static const int days_in_leap_year[];
	std::vector<Patient> patientList;
	//std::deque<Patient> mTestList;

public:
	bool addSequence();
	Patient input();
	Patient inputRegisterTime(Patient p);
	time_t getAdmissionTime(int y, int mon, int d, int h, int min);
	Patient inputPatientName(Patient p);
	Patient inputPatientBirthday(Patient p);
	Patient inputPatientPIN(Patient p);
	Patient inputPatientSymptoms(Patient p);
	Patient inputPatientCategory(Patient p);
	bool checkValidName(std::string fName, std::string lName, std::string mName, int numData);
	bool checkValidBirthDay(int y, int m, int d);
	bool checkValidPIN(std::string pin);
	bool checkValidSymptoms(std::string symp);
	bool checkValidTime(int h, int min);
	bool checkValidCategory(int cateNum);

	void printPatient(Patient p);
};

