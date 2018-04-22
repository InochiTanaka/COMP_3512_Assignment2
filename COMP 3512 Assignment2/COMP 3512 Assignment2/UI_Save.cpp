#include "UI_Save.h"

void UI_Save::Save()
{
	int count = 0;
	std::ofstream ofs("../patient.txt");

	for (int currentLvl = PriorityLevel::CRITICAL; currentLvl != PriorityLevel::MAX; ++currentLvl)
	{
		UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl).size();
		for (int x = 0; x < UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl).size(); ++x)
		{
			ofs << "\n------------ Patient Data " << count++ << " ------------\n";
			printPatient(UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)currentLvl)[x], ofs);
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
	ofs << p.GetFirstName() << "\t";
	ofs << p.GetLastName() << "\t";
	if (p.GetMiddleName() == "")
	{
		ofs << "-" << "\t";
	}
	else 
	{
		ofs << p.GetMiddleName() << "\t";
	}
	ofs << p.GetBirthYear()
		<< "-" << p.GetBirthMonth()
		<< "-" << p.GetBirthDay()
		<< "\t";
	ofs << p.GetPIN() << "\t";
	ofs << p.GetSymptoms() << "\t";
	ofs << p.GetAdmissionTime() << "\t";
	ofs << p.GetCategory() + 1 << "\n";;

	return ofs;
}
