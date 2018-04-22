#pragma once

#include "ProjectIncludes.h"

class UI_Save : public UIBase
{
public:
	UI_Save(Triage& Triageptr)
	{
		UIBase::mPrimaryTriage = Triageptr;
	}
	virtual ~UI_Save() {}

public:
	virtual void Save();
	virtual void Action();
	std::ostream& printPatient(Patient p, std::ostream & ofs);
};