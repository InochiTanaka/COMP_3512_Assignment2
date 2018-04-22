#include "UI_Print.h"

void UI_Print::Print()
{
	for (int currentLvl = PriorityLevel::CRITICAL; currentLvl != PriorityLevel::END; ++currentLvl)
	{
		UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl).size();
		for (int x = 0; x < UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl).size(); ++x)
		{
			std::cout << "\n------------ Patient Data Summary ------------\n";
			printPatient(UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl)[x]);
			std::cout << std::endl;
		}
	}
}

void UI_Print::Action()
{
	Print();
}
