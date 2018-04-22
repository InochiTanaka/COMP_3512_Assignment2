#pragma once

#include "ProjectIncludes.h"

class UI_Main
{
public:
	UI_Main();
	~UI_Main() { delete mTriageHandler; };

public:
	void Print();
	void Action();

	bool IsRunning() { return bRunning; }

private:
	bool bRunning;
	Triage* mTriageHandler;

};