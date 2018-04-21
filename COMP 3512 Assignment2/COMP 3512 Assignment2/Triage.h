#pragma once
#ifndef __ASN2_TRIAGE_H__
#define __ASN2_TRIAGE_H__

//==============================================================================================================
//	 Triage Class
//
//	Handles The Priority Queue when operating it.
//--------------------------------------------------------------------------------------------------------------
//
//==============================================================================================================

class PriorityQueue;
class Patient;
class Triage 
{
public:
	Triage() {}
	~Triage() {}

public:
	void Insert(Patient data);
	void Remove(Patient data);
	void Edit(Patient data);

};



#endif