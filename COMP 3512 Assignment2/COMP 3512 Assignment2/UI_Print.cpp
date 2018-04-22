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

void UI_Print::printPatient(Patient p)
{
	std::cout << "Patient First Name : " << p.GetFirstName() << "\n";
	std::cout << "Patient Last Name : " << p.GetLastName() << "\n";
	std::cout << "Patient Middle Name : " << p.GetMiddleName() << "\n";

	std::cout << "Patient Birthday : "
		<< p.GetBirthYear()
		<< " - " << p.GetBirthMonth()
		<< " - " << p.GetBirthDay()
		<< "\n";

	std::cout << "Personal Healthcare Number : " << p.GetPIN() << "\n";
	std::cout << "Symptoms : " << p.GetSymptoms() << "\n";
	std::cout << "Registered time : " << p.GetAdmissionTime() << "\n";
	std::cout << "Category of seriousness : " << p.GetCategory() + 1 << "\n";
}