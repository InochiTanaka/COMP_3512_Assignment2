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
	Patient GetPatient(std::string name);
	void UpdateList();

	std::deque<Patient> GetList(int category) { return mPatientList[category]; }


public:
	// Local Functions
	bool Save() {}
	bool Load() {}
	void Paint() {}
	void Exit() {}

private:
	int TimeCheck(std::vector<int> time);
	std::vector<int> GetTime(std::string string);

										// Standard Update After External Input / output
	void FixList();									// Update After Internal Alterations
	void Promote(Patient data);
	//PaitentListIterator Seek();

private:
	std::vector<int> mCurrentTime;
public: // Temporary
	std::deque<Patient> mPatientList[]; // 2D Deque
	

};

#endif