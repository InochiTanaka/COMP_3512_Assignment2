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
//			A00978984			A00950913
//====================================================================================================

//----------------------------------------------------------------------------------------------------
//-- Dependency --------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#include <string.h>
#include <deque>
#include "Patient.h"
#include <vector>

// foward decleration
//class Patient;	

typedef std::vector<std::deque<Patient>>::iterator PaitentListIterator;
typedef std::deque<Patient>::iterator PaitentIterator;

//----------------------------------------------------------------------------------------------------
//-- Class Declerations ------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

public:
	// Mutators 
	// AddToList
	void AddPatient(Patient data);
	void RemovePatient(Patient data);
	Patient UpdatePatient(Patient data);
	// Accessors 
	Patient GetPatient(std::string name);

	// Local Functions
	bool Save();
	bool Load(Patient data);
	void Paint(Patient data);
	void Exit();

private:
	void Update();
	//PaitentListIterator Seek();

private:
	std::vector< std::deque<Patient> > mPatientList; // 2D Deque
};

#endif