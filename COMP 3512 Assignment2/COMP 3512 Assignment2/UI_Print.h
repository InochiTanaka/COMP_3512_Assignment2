#pragma once

#include "ProjectIncludes.h"

class UI_Print : public UIBase
{
public:
	UI_Print(Triage& Triageptr) 
	{
		mPrimaryTriage = Triageptr;
	}
	virtual ~UI_Print() {}

public:
	virtual void Print();
	virtual void Action();

};