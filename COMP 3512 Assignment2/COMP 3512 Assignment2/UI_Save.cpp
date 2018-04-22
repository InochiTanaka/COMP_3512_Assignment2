#include "UI_Save.h"

void UI_Save::Save()
{
	int count = 0;
	std::ofstream ofs("patient.txt");

	for (int currentLvl = PriorityLevel::CRITICAL; currentLvl != PriorityLevel::END; ++currentLvl)
	{
		UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl).size();
		for (int x = 0; x < UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl).size(); ++x)
		{
			ofs << "\n------------ Patient Data " << count++ << " ------------\n";
			printPatient(UIBase::mHandler.GetPriorityPatientList((PriorityLevel)currentLvl)[x], ofs);
		}
	}
	ofs.close();

	std::cout << "\n------------ Saved Patient Data ------------\n";
}

void UI_Save::Action()
{
	Save();
}

std::ostream& UI_Save::printPatient(Patient p, std::ostream& ofs)
{
	ofs << "Patient First Name : " << p.GetFirstName() << "\n";
	ofs << "Patient Last Name : " << p.GetLastName() << "\n";
	ofs << "Patient Middle Name : " << p.GetMiddleName() << "\n";

	ofs << "Patient Birthday : "
		<< p.GetBirthYear()
		<< " - " << p.GetBirthMonth()
		<< " - " << p.GetBirthDay()
		<< "\n";

	ofs << "Personal Healthcare Number : " << p.GetPIN() << "\n";
	ofs << "Symptoms : " << p.GetSymptoms() << "\n";
	ofs << "Registered time : " << p.GetAdmissionTime() << "\n";
	ofs << "Category of seriousness : " << p.GetCategory() + 1 << "\n";

	return ofs;
}
