#pragma once
#ifndef __ASN2_ADDPATIENT_H__
#define __ASN2_ADDPATIENT_H__



#include "ProjectIncludes.h"	// So it doesn't looked clumped up

class Patient;

class UI_AddPatient : public UIBase
{
public:
	UI_AddPatient(Triage& Triageptr) 
	{
		UIBase::mHandler = Triageptr;
	}
	virtual ~UI_AddPatient() {}

public:
	virtual void Print() { /* Empty */ }
	virtual void Action();

private:
	static const int days_in_regular_year[];
	static const int days_in_leap_year[];
	//Triage mHandler;
	//std::vector<Patient> patientList;
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



#endif // !__ASN2_ADDPATIENT_H__
