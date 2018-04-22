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
void 
Triage::Insert(Patient data) 
{
	//PriorityLevel eStatus = DefineCondition(data);
	mHospitalList.AddToList(data, (PriorityLevel)data.GetCategory());

	//mHospitalList.UpdateTime(data.GetAdmissionTime());		// Updates List's Time

	//mHospitalList.UpdateList();					// Update List 
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void Triage::RemoveMostRecent()
//------------------------------------------------------------------------------------------------------------------------
//	Removes Highest Priority Patient from the list
//------------------------------------------------------------------------------------------------------------------------
void 
Triage::RemoveMostRecent()
{
	if (mHospitalList.GetPatientCount() > 0)
		mHospitalList.RemoveHigestPriority();
	else
		std::cout << "No Patient to Attend to currently" << std::endl;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	bool Triage::SearchPatient(std::string str)
//------------------------------------------------------------------------------------------------------------------------
//	Checks if there is such patient with the correct PIN
//	Prevents null reference returns
//------------------------------------------------------------------------------------------------------------------------
bool 
Triage::SearchPatient(std::string str)
{
	return mHospitalList.Seek(str);
}

//------------------------------------------------------------------------------------------------------------------------
//	@	Patient& Triage::GetPatientByPIN(std::string str)
//------------------------------------------------------------------------------------------------------------------------
//	Returns the Patient that will need correction/update/editing
//------------------------------------------------------------------------------------------------------------------------
Patient& 
Triage::GetPatientByPIN(std::string str)
{
	return mHospitalList.GetPatient(str);
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void Triage::UpdateList()
//------------------------------------------------------------------------------------------------------------------------
//	Fixes List after any update with Time or Category
//------------------------------------------------------------------------------------------------------------------------
void 
Triage::UpdateList()	
{
	// Promote Based on Time
	mHospitalList.UpdateList();

	// Checks if all Patients Category are in the right Category
	mHospitalList.FixList();

}