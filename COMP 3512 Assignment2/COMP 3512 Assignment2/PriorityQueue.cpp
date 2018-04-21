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
#define LIST_ITERATOR(x, y) for (int x = 0; x < mPatientList.size(); ++x) for (int y = 0; y < mPatientList[x].size(); ++y)
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
PriorityQueue::AddPatient(Patient data)
{
	std::string PIN = data.GetPIN();
	bool flag = false;

	// Iterate through to see if patient is already added
	for (int prioritylevel = PriorityLevel::CRITICAL; prioritylevel != PriorityLevel::END; ++prioritylevel)
		for (int i = 0; i < mPatientList[prioritylevel].size(); ++i) 
			if (mPatientList[prioritylevel][i].GetPIN() == PIN)
				flag = true;

	// Check Catagory Level
	//if (flag)
	//	mPatientList[data.GetPriorityLevel()].push_back(data);	// Addes to the end of the Catagory Level
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void PriorityQueue::RemovePatient(Patient)
//------------------------------------------------------------------------------------------------------------------------
//	Removes a patient from the Queue
//------------------------------------------------------------------------------------------------------------------------
void 
PriorityQueue::RemovePatient(Patient data)
{
	
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
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient PriorityQueue::GetPatient(String)
//------------------------------------------------------------------------------------------------------------------------
//	Returns Patient for editting, searches by name
//------------------------------------------------------------------------------------------------------------------------
Patient
PriorityQueue::GetPatient(std::string name)
{
	return Patient();
}

//PaitentListIterator 
//PriorityQueue::Seek()
//{
//
//}