//========================================================================================================================
//	PriorityQueue.cpp
//========================================================================================================================


//------------------------------------------------------------------------------------------------------------------------
//-- Dependency ----------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

#include "PriorityQueue.h"
#include "Patient.h"
#include "PriorityLevel.h"

//------------------------------------------------------------------------------------------------------------------------
//-- Class Definitions ---------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

#define LIST_ITERATOR(x, y) for(int x = PriorityLevel::CRITICAL; x != PriorityLevel::END; ++x) for(int y = 0; y < mPatientList[x].size(); ++y)
using namespace std; // safe to call in this cpp

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityQueue::PriorityQueue()
//------------------------------------------------------------------------------------------------------------------------
//	Default Constructor 
//------------------------------------------------------------------------------------------------------------------------
PriorityQueue::PriorityQueue()
{
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
	for (int prioritylevel = PriorityLevel::CRITICAL; prioritylevel != PriorityLevel::END; ++prioritylevel)
		for (int i = 0; i < mPatientList[prioritylevel].size(); ++i) 
			if ( mPatientList[prioritylevel][i].GetPIN().compare(PIN)  // Triple Confirmation it if it's the same patient
				&& ( mPatientList[prioritylevel][i].GetFullName().compare(data.GetFullName()) && mPatientList[prioritylevel][i].GetAdmissionDate() == data.GetAdmissionDate() ) )
				fDuplicatePatient = true;


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

	// ASN2 #9 Requirement
	//	Removing After Adding
	Update();

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
	{
		IDHolder.compare(mPatientList[x][y].GetPIN());
	}
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
//	@	void PriorityQueue::UpdatePatient(Patient)
//------------------------------------------------------------------------------------------------------------------------
//	Called after every "edit" to the Queue
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::Update()
{
	for (int i = PriorityLevel::CRITICAL; i < PriorityLevel::END; ++i)
	{
		// If not Empty then Pop the front, Do this only once
		if (mPatientList[i].size() > 0)		
		{
			mPatientList[i].pop_front();	
			break;
		}

	}
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
	{
		if (name.compare(mPatientList[priority][x].GetFullName()) == 0)
		{
			return Patient();
		}
	}

}

//PaitentListIterator 
//PriorityQueue::Seek()
//{
//
//}