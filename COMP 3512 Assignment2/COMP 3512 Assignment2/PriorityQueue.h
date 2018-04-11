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

// foward decleration
class Patient;	

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

private:
	std::deque< std::deque<Patient> > mPriority; // 2D Deque

};

#endif