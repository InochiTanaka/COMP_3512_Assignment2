#include "HospitalUI.h"

// Inochi's
const int HospitalUI::days_in_regular_year[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int HospitalUI::days_in_leap_year[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


//------------------------------------------------------------------------------------------------------------------------
//	@	bool HospitalUI::addSequence()
//------------------------------------------------------------------------------------------------------------------------
//	 All Actions related to adding a NEW patient is placed in here
//------------------------------------------------------------------------------------------------------------------------
bool HospitalUI::addSequence()
{
	Patient patient = input();

	std::cout << "\n------------ New Patient Data Summary ------------\n";
	printPatient(patient);
	//patientList.push_back(patient);
	//mTestList.push_back(patient);

	return false;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient HospitalUI::input()
//------------------------------------------------------------------------------------------------------------------------
//	All process that takes in User Input
//------------------------------------------------------------------------------------------------------------------------
Patient HospitalUI::input()
{
	Patient p;

	//Input Name
	p = inputPatientName(p);

	//Input birthday
	p = inputPatientBirthday(p);

	//Input personal healthcare number
	p = inputPatientPIN(p);

	//Input symptoms
	p = inputPatientSymptoms(p);

	//Input registered time
	p = inputRegisterTime(p);

	//Input category of seriousness
	p = inputPatientCategory(p);

	return p;
}

Patient HospitalUI::inputPatientName(Patient p)
{
	std::string inputFullName;

	std::string inputFirstName;
	std::string inputMiddleName;
	std::string inputLastName;

	bool checkResult;

	do
	{
		checkResult = true;

		std::cout << "Input Patient's Full Name \n(eg. \"FirstName LastName MiddleName\" or \"FirstName LastName,\" ): ";
		getline(std::cin, inputFullName);
		std::cin.clear();

		//inputFirstName >> inputLastName >> inputMiddleName;

		std::stringstream ss(inputFullName);
		std::string item;

		int numData = 0;
		while (std::getline(ss, item, ' ')) {

			switch (numData)
			{
			case 0:
				inputFirstName = item;
				break;
			case 1:
				inputLastName = item;
				break;
			case 2:
				inputMiddleName = item;
				break;
			}
			numData++;
		}

		checkResult = checkValidName(inputFirstName, inputLastName, inputMiddleName, numData);

	} while (!checkResult);

	p.SetName(inputFirstName, inputMiddleName, inputLastName);

	return p;
}

Patient HospitalUI::inputPatientBirthday(Patient p)
{
	int inputYear;
	int inputMonth;
	int inputDay;

	bool checkResult;

	do
	{
		std::cout << "Input Patient's Birth Year : ";
		std::cin >> inputYear;

		std::cout << "Input Patient's Birth Month: ";
		std::cin >> inputMonth;

		std::cout << "Input Patient's Birth Day: ";
		std::cin >> inputDay;

		checkResult = checkValidBirthDay(inputYear, inputMonth, inputDay);

		if (!checkResult)
		{
			std::cout << "\nPlease input BirthDay again \n";
		}

	} while (!checkResult);

	p.SetBirthYear(inputYear);
	p.SetBirthMonth(inputMonth);
	p.SetBirthDay(inputDay);

	return p;
}

Patient HospitalUI::inputPatientPIN(Patient p)
{
	std::string inputPIN;

	do
	{
		std::cout << "Input Patient's Personal Healthcare Number(PIN): ";
		std::cin >> inputPIN;
		std::cin.clear();
		std::cin.ignore();

		//inputFirstName >> inputLastName >> inputMiddleName;

		std::stringstream ss(inputPIN);

	} while (!checkValidPIN(inputPIN));

	p.SetPIN(inputPIN);
	return p;
}

Patient HospitalUI::inputPatientSymptoms(Patient p)
{
	std::string inputSymptoms;

	do 
	{
		std::cout << "Input Patient's Symptoms: ";
		getline(std::cin, inputSymptoms);
		std::cin.clear();

	} while (!checkValidSymptoms(inputSymptoms));

	p.SetSymptoms(inputSymptoms);
	return p;
}

Patient HospitalUI::inputPatientCategory(Patient p)
{
	int categorySeriousness;

	do
	{
		std::cout << "Category List of Seriousness :\n";
		std::cout << "0 : Critical and life-threatening, requires immediate care \n";
		std::cout << "1 : Critical, requires care every soon \n";
		std::cout << "2 : Serious, requires care 'soon' \n";
		std::cout << "3 : Serious \n";
		std::cout << "4 : Non-serious \n";
		std::cout << "5 : Not a priority \n" << "\n";
		std::cout << "Input Patient's Number of Seriousness's Category: ";

		std::cin >> categorySeriousness;
		std::cin.clear();

	} while (!checkValidCategory(categorySeriousness));

	p.SetCategory((PriorityLevel)(categorySeriousness - 1));

	return p;
}

Patient HospitalUI::inputRegisterTime(Patient p)
{
	int inputHour;
	int inputMin;

	std::string timeString;
	std::string hourString;
	std::string minString;

	bool checkResult;

	do
	{
		//Input reservation date
		std::cout << "Input Registered Hour: ";
		std::cin >> inputHour;

		std::cout << "Input Registered Minute: ";
		std::cin >> inputMin;

		checkResult = checkValidTime(inputHour, inputMin);

		if (!checkResult)
		{
			std::cout << "Please input Register time again \n";
		}

	} while (!checkResult);

	std::cin.clear();
	std::cin.ignore();

	if (inputHour < 10)
	{
		hourString = "0" + std::to_string(inputHour);
	}
	else
	{
		hourString = std::to_string(inputHour);
	}

	if (inputMin < 10)
	{
		minString = "0" + std::to_string(inputMin);
	}
	else
	{
		minString = std::to_string(inputMin);
	}

	timeString = hourString + ":" + minString;

	p.SetAdmissionDate(timeString);

	return p;
}

bool HospitalUI::checkValidName(std::string fName, std::string lName, std::string mName, int numData)
{
	if (fName == "" || lName == "")
	{
		std::cout << "Please input First Name and Last Name\n";
		return false;
	}
	else if (numData > 3)
	{
		std::cout << "Please input First Name, Last Name, and Middle Name only\n";
		return false;
	}

	return true;
}

bool HospitalUI::checkValidBirthDay(int y, int m, int d)
{
	//Get current time 
	struct tm now;
	time_t longtime = time(NULL);
	localtime_s(&now, &longtime);

	int currentYear = now.tm_year + 1900;
	int currentMonth = now.tm_mon + 1;
	int currentDay = now.tm_mday;

	//Check input BirthDay is valid

	const int* days;

	if (y % 4 == 0) {
		if (y % 100 == 0) {
			if (y % 400 == 0) {
				days = days_in_leap_year;
			}
			else {
				days = days_in_regular_year;
			}
		}
		else {
			days = days_in_leap_year;
		}
	}
	else {
		days = days_in_regular_year;
	}

	std::stringstream ssY, ssM, ssD;
	ssY << y;
	ssM << m;
	ssD << d;

	std::string stY = ssY.str();
	std::string stM = ssM.str();
	std::string stD = ssD.str();

	if (stY.length() != 4
		|| y > currentYear)
	{
		std::cout << "input BirthDay is invalid : the year should be 4 digits \n";
		return false;
	}

	if (stM.length() > 2
		|| !(1 <= m && m <= 12))
	{
		std::cout << "input BirthDay is invalid : the month should less than 2 digits and between 1 - 12 \n";
		return false;
	}

	if (stD.length() > 2
		|| !(1 <= d && d <= days[m]))
	{
		std::cout << "input BirthDay is invalid : the day is not less than 2 digits and valid day\n";
		return false;
	}

	if ((y > currentYear)
		&& (y == currentYear && m > currentMonth)
		&& (y == currentYear && m == currentMonth && d > currentDay))
	{
		std::cout << "input BirthDay is invalid : the Date is in the future \n";
		return false;
	}

	return true;
}

bool HospitalUI::checkValidPIN(std::string pin)
{
	if (pin.length() != 8)
	{
		std::cout << "input PIN is invalid : the length of PIN should be 8 numbers\n";
		return false;
	}

	return true;
}

bool HospitalUI::checkValidSymptoms(std::string symp)
{
	if (symp.length() == 0)
	{
		std::cout << "input Symptoms is invalid : Please input any Symptoms\n";
		return false;
	}
	return true;
}

bool HospitalUI::checkValidTime(int h, int min)
{
	//Get current time 
	struct tm now;
	time_t longtime = time(NULL);
	localtime_s(&now, &longtime);

	int currentYear = now.tm_year + 1900;
	int currentMonth = now.tm_mon + 1;
	int currentDay = now.tm_mday;
	int currentHour = now.tm_hour;
	int currentMin = now.tm_min;

	//Check input time is valid like between 00:00 and 23:59
	if ((h < 0 || 23 < h) || (min < 0 || 59 < min))
	{
		std::cout << " input time is invalid : the input hour should be 0 - 23, input minutes should be 0 - 59 \n";
		return false;
	}

	//retrun true as the input reservation date/time is not invalid on all test
	return true;
}

bool HospitalUI::checkValidCategory(int cateNum)
{
	if (0 > cateNum || cateNum > 5)
	{
		std::cout << "Please input Number of Seriousness's Category between 1 - 6 \n";
		return false;
	}
	return true;
}

time_t HospitalUI::getAdmissionTime(int y, int mon, int d, int h, int min)
{
	struct tm timeStruct = { 0, min, h, d, mon - 1, y - 1900 };
	time_t time = std::mktime(&timeStruct);

	return time;
}

void HospitalUI::printPatient(Patient p)
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