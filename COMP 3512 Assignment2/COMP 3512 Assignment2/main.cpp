#include "Header.hpp"

int main() 
{
	PriorityQueue test;
	std::cout<< (bool)test.input();
	return 0;
}

bool PriorityQueue::input()
{
	Patient patient;

	////Input Name
	//patient.SetName->FirstName = "Inochi"; //any need check function
	//patient.lastName = "Tanaka"; //any need check function

	//							 //Input symptoms
	//patient.symptoms = "none"; //any need check function

	//						   //Input category of seriousness
	//patient.categorySeriousness = 6; //any need check function

	//inputReservationDate();

	patient = inputReservationDate(patient);

	return true;
}

Patient PriorityQueue::inputReservationDate(Patient p)
{

	int inputYear;
	int inputMonth;
	int inputDay;
	int inputHour;
	int inputMin;

	int admissionTime = -1;

	//Input reservation date
	std::cout << "Input reservation Year: ";
	std::cin >> inputYear;

	std::cout << "Input reservation Month: ";
	std::cin >> inputMonth;

	std::cout << "Input reservation Day: ";
	std::cin >> inputDay;

	std::cout << "Input reservation hour: ";
	std::cin >> inputHour;

	std::cout << "Input reservation minute: ";
	std::cin >> inputMin;

	checkValidDateAndTime(inputYear, inputMonth, inputDay, inputHour, inputMin);

	return p;
}

bool PriorityQueue::checkValidDateAndTime(int y, int mon, int d, int h, int min)
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

	std::cout << "Current Time: " << longtime << "\n";
	std::cout << "Input Time: " << getAdmissionTime(y, mon, d, h, min) << "\n";

	if (longtime < getAdmissionTime(y, mon, d, h, min))
	{
		std::cout << " input date is valid \n";
	}
	else 
	{
		std::cout << " input date is invalid \n";
	}

	/*if (getAdmissionTime()<) 
	{
	}*/

	//if (currentYear == y)
	//{
	//	if (currentMonth == mon)
	//	{
	//		if (currentDay == d)
	//		{
	//			if (currentHour == h)
	//			{
	//				if (currentMin <= min)
	//				{
	//					//If the input date is on same year, same month, 
	//					//and later time than now on same date, return ture.
	//					return true;
	//				}
	//			}
	//		}
	//	}
	//	else if ((currentMonth < mon && currentMonth + MAX_RESERVATION_MONTH >= mon))
	//	{
	//		if (currentMonth + MAX_RESERVATION_MONTH == mon
	//			&& currentDay < d)
	//		{
	//			//If the input date is on same year, later current month but before the max reservation months
	//			// and  return true
	//			return false;
	//		}
	//		//Execute add and return true
	//		return true;
	//	}
	//	//retrun fail
	//	return false;
	//}
	//else if (currentYear + 1 == inputYear)
	//{
	//	if (currentMonth
	//		- NUM_MONTH_ON_YEAR + MAX_RESERVATION_MONTH
	//		>= inputMonth)
	//	{
	//		if (currentDay >= inputDay)
	//		{
	//			//Execute add and return true
	//			patient.year = inputYear;
	//			patient.month = inputMonth;
	//			patient.day = inputDay;
	//			return true;
	//		}
	//	}

	//	//retrun fail
	//	return false;
	//}

	//retrun true as the input reservation date time is valid 
	return true;
}

time_t PriorityQueue::getAdmissionTime(int y, int mon, int d, int h, int min)
{
	struct tm timeStruct = { min, h, d, d, mon, y - 1900 };
	time_t time = std::mktime(&timeStruct);

	return time;
}
