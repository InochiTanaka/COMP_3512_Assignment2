#include "Header.hpp"

const int PriorityQueue::days_in_regular_year[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int PriorityQueue::days_in_leap_year[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() 
{
	PriorityQueue test;
	std::cout<< test.input();
	return 0;
}

bool PriorityQueue::input()
{
	Patient patient;

	//Input Name
	patient = inputPatientName(patient);

	//Input birthday
	patient = inputPatientBirthday(patient);

	//Input personal healthcare number
	patient = inputPatientPIN(patient);

	//Input symptoms
	patient = inputPatientSymptoms(patient);

	//Input registered time
	patient = inputRegisterTime(patient);

	//Input category of seriousness
	patient = inputPatientCategory(patient);

	return true;
}

Patient PriorityQueue::inputPatientName(Patient p)
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

		if (inputFirstName == "" || inputLastName == "")
		{
			std::cout << "Please input First Name and Last Name\n";
			checkResult = false;
		}
		else if (numData > 3)
		{
			std::cout << "Please input First Name, Last Name, and Middle Name only\n";
			checkResult = false;
		}


	} while (!checkResult);

	p.SetName(inputFirstName, inputMiddleName, inputLastName);

	return p;
}

Patient PriorityQueue::inputPatientBirthday(Patient p)
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
			std::cout << "Please input BirthDay again \n";
		}

	} while (!checkResult);

	p.SetBirthYear(inputYear);
	p.SetBirthMonth(inputMonth);
	p.SetBirthDay(inputDay);

	return p;
}

Patient PriorityQueue::inputPatientPIN(Patient p)
{
	std::string inputPIN;

	do 
	{
		std::cout << "Input Patient's Personal Healthcare Number(PIN): ";
		std::cin >> inputPIN;

		if (inputPIN.length() != 8)
		{
			std::cout << "input PIN is invalid : the length of PIN should be 8 numbers";
		}
	} while (inputPIN.length() != 8);

	p.SetPIN(std::stoi(inputPIN));
	return p;
}

Patient PriorityQueue::inputPatientSymptoms(Patient p)
{
	std::string inputSymptoms;

	std::cout << "Input Patient's Symptoms: ";
	std::cin >> inputSymptoms;

	p.SetSymptoms(inputSymptoms);
	return p;
}

Patient PriorityQueue::inputPatientCategory(Patient p)
{
	int categorySeriousness;

	do
	{
		std::cout << "Input Patient's Number of Seriousness's Category: \n";
		std::cout << "1 : Critical and life-threatening, requires immediate care \n";
		std::cout << "2 : Critical, requires care every soon \n";
		std::cout << "3 : Serious, requires care 'soon' \n";
		std::cout << "4 : Serious \n";
		std::cout << "5 : Non-serious \n";
		std::cout << "6 : Not a priority \n";

		std::cin >> categorySeriousness;

		if (0 >= categorySeriousness || categorySeriousness > 6)
		{
			std::cout << "Please input Number of Seriousness's Category between 1 - 6 \n";
		}
	} while (0 >= categorySeriousness || categorySeriousness > 6);

	p.SetCategory(categorySeriousness - 1);

	return p;
}

Patient PriorityQueue::inputRegisterTime(Patient p)
{
	int inputHour;
	int inputMin;

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

	std::cout << inputHour << "\n";
	std::cout << inputMin << "\n";

	std::string timeString = std::to_string(inputHour) +":"+ std::to_string(inputMin);

	std::cout << timeString << "\n";
	p.SetAdmissionDate(timeString);

	return p;
}

bool PriorityQueue::checkValidBirthDay(int y, int m, int d)
{
	//Get current time 
	struct tm now;
	time_t longtime = time(NULL);
	localtime_s(&now, &longtime);

	int currentYear = now.tm_year + 1900;
	int currentMonth = now.tm_mon + 1;
	int currentDay = now.tm_mday;

	//Check input time is valid like between 00:00 and 23:59
	if ( y > currentYear)
	{
		std::cout << " input BirthDay is invalid : the year is in the future \n";
		return false;
	}

	if (y >= currentYear && m > currentMonth)
	{
		std::cout << " input BirthDay is invalid : the month is in the future \n";
		return false;
	}

	if (y >= currentYear && m >= currentMonth && d > currentDay)
	{
		std::cout << " input BirthDay is invalid : the day is in the future \n";
		return false;
	}

	if (getAdmissionTime(y, m, d, 0, 0) > getAdmissionTime(currentYear, currentMonth, currentDay, 0, 0))
	{
		std::cout << " input BirthDay is invalid : the date is in the future \n";
		return false;
	}

	return true;
}

bool PriorityQueue::checkValidTime(int h, int min)
{
	//Get current time 
	struct tm now;
	time_t longtime = time(NULL);
	localtime_s(&now, &longtime);

	int currentYear = now.tm_year;
	int currentMonth = now.tm_mon;
	int currentDay = now.tm_mday;
	int currentHour = now.tm_hour;
	int currentMin = now.tm_min;

	//Check input time is valid like between 00:00 and 23:59
	if ((0 > h && h < 23) || (0 > min && min < 59)) 
	{
		std::cout << " input time is invalid : the input hour should be 0 - 23, input minutes should be 0 - 59 \n";
		return false;
	}

	//Check input date/time is at the day of "MAX_RESERVATION_MONTH" later
	if (getAdmissionTime(currentYear, currentMonth, currentDay, currentHour, currentMin) > getAdmissionTime(currentYear, currentMonth, currentDay, h, min))
	{
		std::cout << " input time is invalid : the time is in past \n";
		return false;
	}

	//retrun true as the input reservation date/time is not invalid on all test
	return true;
}

time_t PriorityQueue::getAdmissionTime(int y, int mon, int d, int h, int min)
{
	struct tm timeStruct = { min, h, d, d, mon, y - 1900 };
	time_t time = std::mktime(&timeStruct);

	return time;
}
