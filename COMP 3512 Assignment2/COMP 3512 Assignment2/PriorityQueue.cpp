//========================================================================================================================
//	PriorityQueue.cpp
//========================================================================================================================


//------------------------------------------------------------------------------------------------------------------------
//-- Dependency ----------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
#include <sstream>
#include <iostream>

#include "PriorityQueue.h"
#include "Patient.h"
#include "PriorityLevel.h"

//------------------------------------------------------------------------------------------------------------------------
//-- Class Definitions ---------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

#define LIST_ITERATOR(x, y) for(int x = PriorityLevel::CRITICAL; x != PriorityLevel::END; ++x) for(int y = 0; y < mPatientList[x].size(); ++y)  // 魔法です
using namespace std; // safe to call in this cpp

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityQueue::PriorityQueue()
//------------------------------------------------------------------------------------------------------------------------
//	Default Constructor 
//------------------------------------------------------------------------------------------------------------------------
PriorityQueue::PriorityQueue()
	: numOfPatient(0)
{
	mPatientList = new std::deque<Patient>[PriorityLevel::END];	// Magic, 出来るだから <-- Look chris, Moon runes
	// Empty
}

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityQueue::~PriorityQueue()
//------------------------------------------------------------------------------------------------------------------------
//	Default Destructor 
//------------------------------------------------------------------------------------------------------------------------
PriorityQueue::~PriorityQueue()
{
	// Empty
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::AddPatient(Patient)
//------------------------------------------------------------------------------------------------------------------------
//	Addeds a patient to the queue
//------------------------------------------------------------------------------------------------------------------------
void
PriorityQueue::AddToList(Patient data, PriorityLevel level)
{
	std::string PIN = data.GetPIN();
	bool fDuplicatePatient = false;

	// Iterate through to see if patient is already added
	for (int prioritylevel = PriorityLevel::CRITICAL; prioritylevel != PriorityLevel::END; ++prioritylevel)	// Iterating by Enum values
		for (int i = 0; i < mPatientList[prioritylevel].size(); ++i)										// Inner List Iteration
		{
			if (mPatientList[prioritylevel][i].GetPIN().compare(PIN))  // Triple Confirmation it if it's the same patient
				if (mPatientList[prioritylevel][i].GetFullName().compare(data.GetFullName()) && mPatientList[prioritylevel][i].GetAdmissionTime() == data.GetAdmissionTime())
					fDuplicatePatient = true;
		}

	// Push to the Category Level
	if (!fDuplicatePatient)
	{
		mPatientList[level].push_back(data);
	}
	else	// Assume the Patient is updated
	{
		// Remove him from the list and readd him to the new level
		RemoveFromList(data);
		mPatientList[level].push_back(data);
	}

	++numOfPatient;

	// ASN2 #9 Requirement
	//	Removing After Adding

	// No point popping the first that was entered
	//if(numOfPatient > 1)
		//UpdateList();

	//	mPatientList[data.GetPriorityLevel()].push_back(data);	// Addes to the end of the Catagory Level
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::RemovePatient(Patient)
//------------------------------------------------------------------------------------------------------------------------
//	Removes a patient from the Queue
//------------------------------------------------------------------------------------------------------------------------
void
PriorityQueue::RemoveFromList(Patient data)
{
	string IDHolder = data.GetPIN();
	// Seek by ID No
	LIST_ITERATOR(x, y)
		IDHolder.compare(mPatientList[x][y].GetPIN());

}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient PriorityQueue::UpdatePatient(Patient)
//------------------------------------------------------------------------------------------------------------------------
//	Removes a patient from the Queue
//------------------------------------------------------------------------------------------------------------------------
Patient 
PriorityQueue::UpdatePatient(Patient data)
{
	return Patient();
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::Update()
//------------------------------------------------------------------------------------------------------------------------
//	Called after every "edit" to the Queue.
//	After every 
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::UpdateList()
{
	//FixList();
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::FixList() 
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Fixes list
//------------------------------------------------------------------------------------------------------------------------
void PriorityQueue::RemoveHigestPriority()
{
	// Remove the First from the list
	for (int i = PriorityLevel::CRITICAL; i < PriorityLevel::END; ++i)
	{
		// If not Empty then Pop the front, Do this only once
		if (mPatientList[i].size() > 0)
		{
			mPatientList[i].pop_front();
			--numOfPatient;
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::FixList() 
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Updates the time
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::FixList() 
{
	LIST_ITERATOR(x, y)
		mPatientList[x][y].SetTimeDuration(TimeCheck(GetTime(mPatientList[x][y].GetAdmissionTime())));

	// Checks if All Priority Levels are in the Correct Array
	// Checks if Any Patient Needs Promotion
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::Promote()
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Fixes list
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::Promote(Patient data)
{

}

//------------------------------------------------------------------------------------------------------------------------
//	@	int PriorityQueue::TimeCheck(vector<int> time)
//------------------------------------------------------------------------------------------------------------------------
//	Checks how much time has passed by comparing current time ( recently updated Patient's time ) vs Stored Time
//------------------------------------------------------------------------------------------------------------------------
int 
PriorityQueue::TimeCheck(vector<int> time)
{
	int diff = mCurrentTime[0] - time[0];

	if (diff > 0)	// Regular time, Current Time > listed time
	{
		// Check Minutes to see if 24 h has passed
		if (mCurrentTime[1] - time[1] < 0)
			return 24;

		return diff;
	}

	return (mCurrentTime[0] - (time[0] - 24 ));		//  24 hour clock reverts to 0 on the 24th hour. 
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient PriorityQueue::GetPatient(String)
//------------------------------------------------------------------------------------------------------------------------
//	Returns Patient for editting, searches by name
//------------------------------------------------------------------------------------------------------------------------
Patient
PriorityQueue::GetPatient(std::string name)
{
	LIST_ITERATOR(priority, x)
		if (name.compare(mPatientList[priority][x].GetFullName()) == 0)
			return Patient();
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Void PriorityQueue::GetTime(std::string string)
//------------------------------------------------------------------------------------------------------------------------
//	Converts String to Seperate Hour and Minutes and stores it in List's Time
//------------------------------------------------------------------------------------------------------------------------
void
PriorityQueue::UpdateTime(std::string string)
{
	using namespace std;
	vector<int> temp;

	stringstream ss(string);

	int i;

	while (ss >> i)
	{
		if (ss.peek() == ':')
			ss.ignore();

		temp.push_back(i);
	}

	mCurrentTime = temp;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	vector<int> PriorityQueue::GetTime(std::string string)
//------------------------------------------------------------------------------------------------------------------------
//	Converts String to Seperate Hour and Minutes
//------------------------------------------------------------------------------------------------------------------------
vector<int>
PriorityQueue::GetTime(std::string string)
{
	using namespace std;
	vector<int> temp;

	stringstream ss(string);

	int i;

	while (ss >> i)
	{
		if (ss.peek() == ':')
			ss.ignore();

		temp.push_back(i);
	}

	return temp;
}

//PaitentListIterator 
//PriorityQueue::Seek()
//{
//
//}