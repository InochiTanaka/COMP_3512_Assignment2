#pragma once
#include<iostream>
#include <string>
#include <stdio.h>

#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>

struct Patient
{
	public:
		std::string firstName;
		std::string middleName;
		std::string lastName;

		int year;
		int month;
		int day;
		int hour;
		int min;

		int personalNum;
		std::string symptoms;
		int categorySeriousness;
};

class PriorityQueue 
{
	private:

	public:
		PriorityQueue();
		void Add(Patient data);
		Patient Get();
		bool ChangeCategory(Patient data, int categoryNum);
		bool Save();
		bool Load(Patient data);
		void Paint(Patient data);
		void Exit();

		bool input();
};

PriorityQueue::PriorityQueue()
{
	struct Patient patient;

	patient.firstName = "Inochi";
	patient.lastName = "Tanaka";

	patient.year = 2018;
	patient.month = 5;
	patient.day = 20;
	patient.hour = 6;
	patient.min = 0;

	patient.symptoms = "none";

	patient.categorySeriousness = 6;

	Paint(patient);

}

void PriorityQueue::Add(Patient data)
{
}

Patient PriorityQueue::Get()
{
	return Patient();
}

bool PriorityQueue::ChangeCategory(Patient data, int categoryNum)
{
	return false;
}

bool PriorityQueue::Save()
{
	return false;
}

bool PriorityQueue::Load(Patient data)
{
	return false;
}

void PriorityQueue::Paint(Patient data)
{
	std::cout << "First Name :\t" << data.firstName << "\n"
		<< "Middle Name :\t" << data.middleName << "\n"
		<< "Last Name :\t" << data.lastName << "\n";
}

void PriorityQueue::Exit()
{
	exit(1);
}


bool input()
{

	int MAX_RESERVATION_MONTH = 3;
	int NUM_MONTH_ON_YEAR = 12;

	struct Patient patient;

	int inputYear;
	int inputMonth;
	int inputDay;

	//Input Name
	patient.firstName = "Inochi"; //any need check function
	patient.lastName = "Tanaka"; //any need check function

	//Input symptoms
	patient.symptoms = "none"; //any need check function

	//Input category of seriousness
	patient.categorySeriousness = 6; //any need check function


	//Input reservation date
	std::cout << "Input reservation Year: ";
	std::cin >> inputYear;

	std::cout << "Input reservation Month: ";
	std::cin >> inputMonth;

	std::cout << "Input reservation Day: ";
	std::cin >> inputDay;

	struct tm now;

	time_t longtime = time(NULL);

	localtime_s(&now, &longtime);

	int currentYear = now.tm_year + 1900;
	int currentMonth = now.tm_mon + 1;
	int currentDay = now.tm_mday;

	//int currentYear = 2018;
	//int currentMonth = 12;
	//int currentDay = 1;

	if (currentYear == inputYear)
	{
		if (currentMonth == inputMonth)
		{
			if (currentDay <= inputDay)
			{
				//Execute add and return true
				patient.year = inputYear;
				patient.month = inputMonth;
				patient.day = inputDay;
				return true;
			}
		}
		else if ((currentMonth < inputMonth && currentMonth + MAX_RESERVATION_MONTH >= inputMonth))
		{
			if (currentMonth + MAX_RESERVATION_MONTH == inputMonth
				&& currentDay < inputDay)
			{
				//Execute add and return true
				return false;
			}
			//Execute add and return true
			patient.year = inputYear;
			patient.month = inputMonth;
			patient.day = inputDay;
			return true;
		}
		//retrun fail
		return false;
	}
	else if (currentYear + 1 == inputYear)
	{
		if (currentMonth
			- NUM_MONTH_ON_YEAR + MAX_RESERVATION_MONTH
			>= inputMonth)
		{
			if (currentDay >= inputDay)
			{
				//Execute add and return true
				patient.year = inputYear;
				patient.month = inputMonth;
				patient.day = inputDay;
				return true;
			}
		}

		//retrun fail
		return false;
	}

	//retrun fail
	return false;
}