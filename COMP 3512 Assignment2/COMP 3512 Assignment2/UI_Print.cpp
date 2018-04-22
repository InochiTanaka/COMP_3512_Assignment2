#include "UI_Print.h"

void UI_Print::Print()
{
	int listsize = 0;
	for (int currentLvl = PriorityLevel::CRITICAL; currentLvl != PriorityLevel::MAX; ++currentLvl)
	{
		listsize += UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl).size(); // if its not empty it will be greater than one

		for (int x = 0; x < UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl).size(); ++x)
		{
			std::cout << "\n------------ Patient Data Summary ------------\n";
			printPatient(UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl)[x]);
			std::cout << std::endl;
		}
	}
	if(!listsize)
		std::cout << "List is Empty" << std::endl;
}

void UI_Print::Action()
{
	Print();
}
