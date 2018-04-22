#pragma once

#include "ProjectIncludes.h"

class UI_Print : public UIBase
{
public:
	UI_Print(Triage& Triageptr) 
	{
		UIBase::mHandler = Triageptr;
	}
	virtual ~UI_Print() {}

public:
	virtual void Print();
	virtual void Action();

private:
	void printPatient(Patient p);

};