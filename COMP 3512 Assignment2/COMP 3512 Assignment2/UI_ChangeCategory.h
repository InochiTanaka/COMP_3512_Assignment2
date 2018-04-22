#pragma once

#include "ProjectIncludes.h"

class UI_ChangeCategory : public UIBase
{
public:
	UI_ChangeCategory(Triage& Triageptr)
	{
		UIBase::mPrimaryTriage = Triageptr;
	}
	virtual ~UI_ChangeCategory() {}

public:
	virtual void Print();
	virtual void Action();

	

private:
	void InputPatientPIN();
	void InputPatientCategory(Patient& p);

private:
	std::string mInputPIN;

};