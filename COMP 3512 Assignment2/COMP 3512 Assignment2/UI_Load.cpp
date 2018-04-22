#include "UI_Load.h"

void UI_Load::Load()
{
	int count = 0;
	std::ifstream fin("../patient.txt");
	std::string str;

	while (getline(fin, str))
	{
		mHandler.Insert(setElements(str));
	}

	fin.close();

	std::cout << "\n------------ Loaded Patient Data ------------\n";
}

void UI_Load::Action()
{
	Load();
}

Patient UI_Load::setElements(std::string str)
{
	Patient newPatient;
	std::string buffer;
	std::stringstream ss(str);
	std::vector<std::string> elems;

	//Separate elements from 1 string
	while (getline(ss, buffer, '\t'))
	{
		elems.push_back(buffer);
	}

	//Set Name
	//if middle name is "-", replace with ""
	if (elems[2] == "-")
	{
		elems[2] = "";
	}

	newPatient.SetName(elems[0], elems[2], elems[1]);

	//Separate and set dates
	std::stringstream ssDate(elems[3]);
	std::vector<std::string> dates;

	while (getline(ssDate, buffer, '-'))
	{
		dates.push_back(buffer);
	}

	newPatient.SetBirthYear(std::stoi(dates[0]));
	newPatient.SetBirthMonth(std::stoi(dates[1]));
	newPatient.SetBirthDay(std::stoi(dates[2]));

	//Set PIN
	newPatient.SetPIN(elems[4]);

	//Set Symptoms
	newPatient.SetSymptoms(elems[5]);

	//Set AdmissionTime
	newPatient.SetAdmissionDate(elems[6]);

	//Set Category
	newPatient.SetCategory(std::stoi(elems[7]));

	return newPatient;
}