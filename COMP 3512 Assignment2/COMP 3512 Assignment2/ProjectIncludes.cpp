#include "ProjectIncludes.h"

void printPatient(Patient p)
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
