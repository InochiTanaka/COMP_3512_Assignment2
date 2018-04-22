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

#define LIST_ITERATOR(x, y) for(int x = PriorityLevel::CRITICAL; x != PriorityLevel::MAX; ++x) for(int y = 0; y < mPatientList[x].size(); ++y)  // ñÇñ@Ç≈Ç∑
using namespace std; // safe to call in this cpp

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityQueue::PriorityQueue()
//------------------------------------------------------------------------------------------------------------------------
//	Default Constructor 
//------------------------------------------------------------------------------------------------------------------------
PriorityQueue::PriorityQueue()
	: numOfPatient(0)
{
	mPatientList = new std::deque<Patient>[PriorityLevel::MAX];	// Magic, èoóàÇÈÇæÇ©ÇÁ <-- Look chris, Moon runes
	// Empty
}

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityQueue::~PriorityQueue()
//------------------------------------------------------------------------------------------------------------------------
//	Default Destructor 
//------------------------------------------------------------------------------------------------------------------------
PriorityQueue::~PriorityQueue()
{
	delete[] mPatientList;
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
	for (int prioritylevel = PriorityLevel::CRITICAL; prioritylevel != PriorityLevel::MAX; ++prioritylevel)	// Iterating by Enum values
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
		++numOfPatient;

		// After Adding, record that this is the latest addition
		UpdateTime(data.GetAdmissionTime());
		UpdateAllPatient();
	}
	else
		std::cout << "Patient already is on the list" << endl;

}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::FixList() 
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Fixes list
//------------------------------------------------------------------------------------------------------------------------
void PriorityQueue::RemoveHigestPriority()
{
	if (numOfPatient > 0)
	{
		// Remove the First from the list
		for (int i = PriorityLevel::CRITICAL; i < PriorityLevel::MAX; ++i)
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
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::FixList() 
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Updates the time
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::UpdateAllPatient() 
{
	LIST_ITERATOR(level, y)
		if(mPatientList[level].size() > 0)
			mPatientList[level][y].SetTimeDuration(TimeCheck(GetTime(mPatientList[level][y].GetAdmissionTime())));
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::Promote()
//------------------------------------------------------------------------------------------------------------------------
//	Iterates through the List and Fixes list
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::Promote(PaitentIterator itrPtr, PriorityLevel newLevel, PriorityLevel prev)
{
	Patient temp = (*itrPtr); // Copy
	mPatientList[prev].erase(itrPtr);
	mPatientList[newLevel].push_back(temp);
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::FixList()
//------------------------------------------------------------------------------------------------------------------------
// Checks if all Patients Category are in the right Category
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::FixList()
{
	for(int level = PriorityLevel::CRITICAL; level != PriorityLevel::MAX; ++level)
		if (mPatientList[level].size() > 0)	
		{
			for (PaitentIterator listItr = mPatientList[level].begin(); listItr != mPatientList[level].end(); ++listItr)
			{
				if ( (*listItr).GetCategory() != level)
				{
					Promote(listItr, (PriorityLevel)(*listItr).GetCategory(), (PriorityLevel)level);

					if (mPatientList[level].size() > 0)	// if there is still as list, reset the iterator, else the element we moved was the last element, just break the loop and move on
						listItr = mPatientList[level].begin();
					else
						break;
				}
			}
		}
}

//------------------------------------------------------------------------------------------------------------------------
//	@	int PriorityQueue::TimeCheck(vector<int> time)
//------------------------------------------------------------------------------------------------------------------------
// Promote Based on Time
//------------------------------------------------------------------------------------------------------------------------
void PriorityQueue::UpdateList()
{
	for (int level = PriorityLevel::CRITICAL_STABLE; level != PriorityLevel::MAX; ++level)
		for (int i = 0; i < mPatientList[level].size(); ++i)
		{
			if (level == PriorityLevel::CRITICAL_STABLE)
			{
				if (mPatientList[level][i].GetTimePassed() >= 1)
				{
					mPatientList[level][i].SetCategory(mPatientList[level][i].GetCategory() - 1);
					mPatientList[level][i].SetTimeDuration(0);			// reset counter
				}
			}
			else if (level <= PriorityLevel::SERIOUS)
			{
				if (mPatientList[level][i].GetTimePassed() >= 2)
				{
					mPatientList[level][i].SetCategory(mPatientList[level][i].GetCategory() - 1);
					mPatientList[level][i].SetTimeDuration(0);			// reset counter
				}
			}
			else  if (level <= PriorityLevel::COMFORTABLE)
			{
				if (mPatientList[level][i].GetTimePassed() >= 3)
				{
					mPatientList[level][i].SetCategory(mPatientList[level][i].GetCategory() - 1);
					mPatientList[level][i].SetTimeDuration(0);			// reset counter
				}
			}
		}
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
	else if (diff < 0)
		return (mCurrentTime[0] - (time[0] - 24 ));		//  24 hour clock reverts to 0 on the 24th hour. 

	return 0;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	bool PriorityQueue::Seek(std::string PIN)
//------------------------------------------------------------------------------------------------------------------------
//	Searches through the whole list for a matching PIN
//------------------------------------------------------------------------------------------------------------------------
bool 
PriorityQueue::Seek(std::string PIN)
{
	LIST_ITERATOR(priority, x)
		if (PIN.compare(mPatientList[priority][x].GetPIN()) == 0)
			return true;
	return false;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient& PriorityQueue::GetPatient(String)
//------------------------------------------------------------------------------------------------------------------------
//	Returns Patient for editting, searches by name
//------------------------------------------------------------------------------------------------------------------------
Patient&
PriorityQueue::GetPatient(std::string PIN)
{
	LIST_ITERATOR(priority, x)
		if(mPatientList[priority].size() > 0)
			if (PIN.compare(mPatientList[priority][x].GetPIN()) == 0)
				return mPatientList[priority][x];
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