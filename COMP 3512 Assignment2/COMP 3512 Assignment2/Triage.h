#pragma once
#ifndef __ASN2_TRIAGE_H__
#define __ASN2_TRIAGE_H__

//====================================================================================================
//	 Triage Class
//
//	Handles The Priority Queue when operating it.
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
//====================================================================================================

//----------------------------------------------------------------------------------------------------
//-- Dependency --------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include "PriorityLevel.h"
#include "PriorityQueue.h"

// foward decleration
class Patient;

//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class Triage 
{
public:
	Triage() {}
	~Triage() {}

public:

	// Mutators ------------------------------------------------------------------------------------
	void Insert(Patient data);
	void RemoveMostRecent();
	void UpdateList();

	// Accessor ------------------------------------------------------------------------------------
	bool SearchPatient(std::string str);
	Patient& GetPatientByPIN(std::string str);

	std::deque<Patient>& GetPriorityPatientList(PriorityLevel lvl)		{ return mHospitalList.GetList((int)lvl); }

private:
	PriorityQueue mHospitalList;
};

#endif