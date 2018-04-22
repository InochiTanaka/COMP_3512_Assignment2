#pragma once

#include "ProjectIncludes.h"

class UI_Load : public UIBase
{
public:
	UI_Load(Triage& Triageptr)
	{
		UIBase::mHandler = Triageptr;
	}
	virtual ~UI_Load() {}

public:
	virtual void Load();
	virtual void Action();
	Patient setElements(std::string str);
};