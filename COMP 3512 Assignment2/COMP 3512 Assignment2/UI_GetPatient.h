#pragma once

#include "ProjectIncludes.h"

class UI_GetPatient : public UIBase
{
public:
	UI_GetPatient(Triage& Triageptr)
	{
		mPrimaryTriage = Triageptr;
	}
	virtual ~UI_GetPatient() {}

public:
	virtual void Print();
	virtual void Action();

};