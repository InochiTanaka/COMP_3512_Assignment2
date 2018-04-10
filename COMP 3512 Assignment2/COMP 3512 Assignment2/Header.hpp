#pragma once
#include<iostream>
#include <string>
#include <ctime>
#include <stdio.h>

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
