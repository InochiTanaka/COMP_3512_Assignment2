#pragma once
// Legacy
#ifndef __ASN2_PRIORITYQUE_H__
#define __ASN2_PRIORITYQUE_H__

//====================================================================================================
//	Priority Queue CLass
//
//	A Class that Mimics a Priority Que, but with assignment specific Optimization
//----------------------------------------------------------------------------------------------------
//	Inochi Tanaka		Joseph Yang
//	A00978984			A00950913
//====================================================================================================

//----------------------------------------------------------------------------------------------------
//-- Dependency --------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include <string.h>
#include <deque>
#include <vector>

#include "Patient.h"
#include "PriorityLevel.h"


// foward decleration
//class Patient;	

typedef std::deque<Patient>::iterator PaitentIterator;

//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class PriorityQueue
{

public:		
	//	Constructors -------------------------------------------------------------------
	PriorityQueue();
	~PriorityQueue();
	
	//	Mutators -----------------------------------------------------------------------
	void AddToList(Patient data, PriorityLevel level);
	void RemoveFromList(Patient data);

	Patient UpdatePatient(Patient data);
	void UpdateTime(std::string string);

	//	Accessors ----------------------------------------------------------------------
	bool Seek(std::string PIN);
	Patient& GetPatient(std::string PIN);

	void RemoveHigestPriority();							// Pops after a general Update
	int GetPatientCount() const							{ return numOfPatient; }

	std::deque<Patient>& GetList(int category) const	{ return mPatientList[category]; }

private:
	int TimeCheck(std::vector<int> time);
	std::vector<int> GetTime(std::string string);

	void FixList();									// Update After Internal Alterations
	void Promote(Patient data);
	//PaitentListIterator Seek();

private:
	std::vector<int> mCurrentTime;
	std::deque<Patient>* mPatientList; // 2D Deque
	int numOfPatient;
};

#endif