#pragma once
//====================================================================================================
//	Patient.h
//
//	A Class holds all Patient Data and Condition for the ER
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//		A00978984		A00950913
//====================================================================================================

//----------------------------------------------------------------------------------------------------
//-- Dependency --------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class Patient 
{
public:
	Patient() {}
	~Patient() {}

public:
	//	Accessors
	std::string GetFirstName()		{ return mName.FirstName; }
	std::string GetMiddleName()		{ return mName.SecondName; }
	std::string GetLastName()		{ return mName.LastName; }
	std::string	GetFullName()		{ return mName.FirstName + ' ' + mName.SecondName + ' '+ mName.LastName; }
	int GetPIN()					{ return mPIN; }
	int GetAdmissionDate()			{ return mAdmissionTime; }

	void SetName(std::string first, std::string middle, std::string last) 
	{
		mName.FirstName = first;
		mName.SecondName = middle;
		mName.LastName = last;
	}
	void SetPIN(int data)			{ mPIN = data; }
	int SetAdmissionDate(int data)	{ mAdmissionTime = data; }

private:
	struct Name { 
		std::string FirstName; 
		std::string SecondName; 
		std::string LastName;
	} mName;
	struct Birthdate 
	{
		int Year;
		int Month;
		int Day;
	} mBday;

	int mAdmissionTime; // 24h format, 4 digit

	int mPIN;

};