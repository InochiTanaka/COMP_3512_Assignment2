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

#include "PriorityLevel.h"

//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class Patient 
{
public:
	Patient() 
		: mTimePassed(0)
	{}
	~Patient() {}

public:		
	
	// Accessor ------------------------------------------------------------------------------------

	// Name
	std::string GetFirstName()			{ return mName.FirstName; }
	std::string GetMiddleName()			{ return mName.SecondName; }
	std::string GetLastName()			{ return mName.LastName; }
	std::string	GetFullName()			{ return mName.FirstName + ' ' + mName.SecondName + ' '+ mName.LastName; }

	
	// Time
	int GetBirthYear()					{ return mBday.Year; }
	int GetBirthMonth()					{ return mBday.Month; }
	int GetBirthDay()					{ return mBday.Day; }
	std::string GetAdmissionTime()		{ return mAdmissionTime; }


	// Data
	int GetCategory()					{ return (int)mCategory; }

	std::string GetPIN()				{ return mPIN; }
	std::string GetSymptoms()			{ return mSymptoms; }

	int GetTimePassed()					{ return mTimePassed; }


	// Mutators ------------------------------------------------------------------------------------

	// Name
	void SetName(std::string first, std::string middle, std::string last) 
	{
		mName.FirstName = first;
		mName.SecondName = middle;
		mName.LastName = last;
	}


	// Time
	void SetBirthYear(int year)					{ mBday.Year = year; }
	void SetBirthMonth(int month)				{ mBday.Month = month; }
	void SetBirthDay(int day)					{ mBday.Day = day; }
	void SetAdmissionDate(std::string data)		{ mAdmissionTime = data; }


	// Data
	void SetCategory(int category)				{ mCategory = (PriorityLevel)category; }

	void SetPIN(std::string data)				{ mPIN = data; }
	void SetSymptoms(std::string symptoms)		{ mSymptoms = symptoms; }
	
	void SetTimeDuration(int time)				{ mTimePassed = time; }

#pragma region Variables 

	// Shrinks code, People shouldn't see what kind of data it has only how to use it.
	// That and it saves my eyes for the horror

private:	// Memeber Variables ------------------------------------------------------------------

	// Time
	std::string mAdmissionTime; // 24h format, 4 digit
	int mTimePassed;			// Time passed since Admission

	PriorityLevel mCategory;	// Enum
	
	// String Data
	std::string mPIN;			// First Digits can be Zero as Inochi Pointed out, we wish to store that as well
	std::string mSymptoms;

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
#pragma endregion

};

#endif // __ASN2_PATIENT_H__