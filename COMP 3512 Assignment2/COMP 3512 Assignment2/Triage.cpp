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
	// Print !!
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

//------------------------------------------------------------------------------------------------------------------------
//	@	void Triage::Edit(Patient data) 
//------------------------------------------------------------------------------------------------------------------------
//	Removes Patient from the list
//------------------------------------------------------------------------------------------------------------------------
void Triage::Edit(Patient data) 
{
}

//------------------------------------------------------------------------------------------------------------------------
//	@	PriorityLevel Triage::DefineCondition(Patient data) 
//------------------------------------------------------------------------------------------------------------------------
//	Defines Priority Condition of the Patient
//------------------------------------------------------------------------------------------------------------------------
PriorityLevel Triage::DefineCondition(Patient data) 
{
	std::string tempString = data.GetSymptoms();

	if (tempString.compare("Critical and life-threatening, requires immediate care") == 0)
		return PriorityLevel::CRITICAL;

	if (tempString.compare("Critical, requires care `very soon'") == 0)
		return PriorityLevel::CRITICAL_STABLE;

	if (tempString.compare("Serious, requires care `soon'") == 0)
		return PriorityLevel::SEVERE;

	if (tempString.compare("Serious") == 0)
		return PriorityLevel::SERIOUS;

	if (tempString.compare("Non-serious") == 0)
		return PriorityLevel::GOOD;

	// If it isn't any of the above, then they are probably comfortable and/or not dying É∞(ÅLÑtÅM;)
	return PriorityLevel::COMFORTABLE;

}

