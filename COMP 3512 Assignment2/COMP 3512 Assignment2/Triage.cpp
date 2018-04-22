//========================================================================================================================
//	Triage.cpp
//========================================================================================================================

//------------------------------------------------------------------------------------------------------------------------
//-- Dependency ----------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

#include "Triage.h"

//------------------------------------------------------------------------------------------------------------------------
//-- Class Definitions ---------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------
//	@	void Triage::Insert(Patient data)
//------------------------------------------------------------------------------------------------------------------------
//	Places the patient in the correct Priority
//------------------------------------------------------------------------------------------------------------------------
void Triage::Insert(Patient data) 
{
	//PriorityLevel eStatus = DefineCondition(data);
	mHospitalList.AddToList(data, (PriorityLevel)data.GetCategory());

	//mHospitalList.UpdateTime(data.GetAdmissionTime());		// Updates List's Time

	//mHospitalList.UpdateList();					// Update List 
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void Triage::Remove(Patient data) 
//------------------------------------------------------------------------------------------------------------------------
//	Removes Patient from the list
//------------------------------------------------------------------------------------------------------------------------
void Triage::Remove(Patient data) 
{
	mHospitalList.RemoveFromList(data);
	//mHospitalList.UpdateList();		// Fixes list after change, if needed
	// Print !!
}

void Triage::RemoveMostRecent()
{
	if (mHospitalList.GetPatientCount() > 0)
		mHospitalList.RemoveHigestPriority();
	else
		std::cout << "No Patient to Attend to currently" << std::endl;
}

bool Triage::SearchPatient(std::string str)
{
	return mHospitalList.Seek(str);
}

Patient& Triage::GetPatientByPIN(std::string str)
{
	return mHospitalList.GetPatient(str);
}
void Triage::UpdateList()	// Fixes List
{
	// Promote Based on Time
	mHospitalList.UpdateList();

	// Checks if all Patients Category are in the right Category
	mHospitalList.FixList();

	

}


