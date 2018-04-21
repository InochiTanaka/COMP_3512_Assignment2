#pragma once
#ifndef __ASN2_PATIENT_H__
#define __ASN2_PATIENT_H__

//====================================================================================================
//	Patient.h
//
//	A Class holds all Patient Data and Condition for the ER
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
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

public:		//	Accessors ----------------------------------------------------------------------

	std::string GetFirstName()		{ return mName.FirstName; }
	std::string GetMiddleName()		{ return mName.SecondName; }
	std::string GetLastName()		{ return mName.LastName; }
	std::string	GetFullName()		{ return mName.FirstName + ' ' + mName.SecondName + ' '+ mName.LastName; }
	std::string GetSymptoms()		{ return mSymptoms; }
	int GetCategory()				{ return mCategory; }
	int GetBirthYear()				{ return mBday.Year; }
	int GetBirthMonth()				{ return mBday.Month; }
	int GetBirthDay()				{ return mBday.Day; }
	std::string  GetPIN()					{ return mPIN; }
	std::string GetAdmissionDate()			{ return mAdmissionTime; }

public:		// Mutators ----------------------------------------------------------------------

	void SetName(std::string first, std::string middle, std::string last) 
	{
		mName.FirstName = first;
		mName.SecondName = middle;
		mName.LastName = last;
	}
	void SetPIN(std::string data)					{ mPIN = data; }

	void SetBirthYear(int year)				{ mBday.Year = year; }
	void SetBirthMonth(int month)			{ mBday.Month = month; }
	void SetBirthDay(int day)				{ mBday.Day = day; }

	void SetAdmissionDate(std::string data)			{ mAdmissionTime = data; }
	void SetSymptoms(std::string symptoms)	{ mSymptoms = symptoms; }
	void SetCategory(int category)			{ mCategory = category; }

	
private:	// Memeber Variables ----------------------------------------------------------------------

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

	std::string mSymptoms;
	int mCategory;

	std::string mAdmissionTime; // 24h format, 4 digit

	std::string mPIN;

};

#endif // __ASN2_PATIENT_H__