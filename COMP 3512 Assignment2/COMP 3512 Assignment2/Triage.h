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
	Triage() 
	{

	}
	~Triage() {}

public:
	void Insert(Patient data);
	void Remove(Patient data);
	void Edit(Patient data);
	void RemoveMostRecent();

	std::deque<Patient>& GetPriorityPatientList(PriorityLevel lvl)
	{
		return mHospitalList.GetList((int)lvl);
	}
private:
	PriorityLevel DefineCondition(Patient data);

private:
	PriorityQueue mHospitalList;
};

#endif