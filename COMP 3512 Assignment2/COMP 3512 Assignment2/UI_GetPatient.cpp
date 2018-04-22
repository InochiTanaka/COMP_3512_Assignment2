#include "UI_GetPatient.h"

void UI_GetPatient::Print()
{
	for (int i = PriorityLevel::CRITICAL; i != PriorityLevel::END; ++i)
	{
		if (UIBase::mHandler.GetPriorityPatientList((PriorityLevel)i).size() > 0)	// this list must not be empty
			printPatient( ( UIBase::mHandler.GetPriorityPatientList((PriorityLevel)i)[0] ) );
	}
		
}

void UI_GetPatient::Action()
{
	Print();
	UIBase::mHandler.RemoveMostRecent();
}
