#pragma once

//====================================================================================================
//	Hospital UI
//
//	UI Handler
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
//====================================================================================================


#include "ProjectIncludes.h"	// So it doesn't looked clumped up

#include "Patient.h"
#include "Triage.h"

//#include "PriorityQueue.hpp"
//#include "PriorityLevel.hpp"



#define PIN_LENGTH = 8;
#define MAX_RESERVATION_MONTH = 3;
#define NUM_MONTH_ON_YEAR = 12;


// Inochi's


namespace UIState 
{
	static enum state
	{
		ADD,
		GET_NEXT_PATIENT,
		CHANGE_CATEGORY,
		SAVE,
		LOAD,
		PRINT,
		EXIT
	};
	state currentstate = state::ADD;
};

class HospitalUI
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

