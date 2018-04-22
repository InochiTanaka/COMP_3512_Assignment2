#include "UI_GetPatient.h"

//------------------------------------------------------------------------------------------------------------------------
//	@	UI_GetPatient::UI_GetPatient(Triage & Triageptr)
//------------------------------------------------------------------------------------------------------------------------
//	 Default Constructor that takes the Address of the Triage Class
//------------------------------------------------------------------------------------------------------------------------
UI_GetPatient::UI_GetPatient(Triage & Triageptr)
{
	mPrimaryTriage = Triageptr;
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void UI_GetPatient::Print()
//------------------------------------------------------------------------------------------------------------------------
//	Class's Print Msg requirements
//------------------------------------------------------------------------------------------------------------------------
void 
UI_GetPatient::Print()
{
	for (int i = PriorityLevel::CRITICAL; i != PriorityLevel::MAX; ++i)
	{
		if (UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)i).size() > 0)	// this list must not be empty
			printPatient( ( UIBase::mPrimaryTriage.GetPriorityPatientList((PriorityLevel)i)[0] ) );
	}
		
}

//------------------------------------------------------------------------------------------------------------------------
//	@	void UI_GetPatient::Action()
//------------------------------------------------------------------------------------------------------------------------
//	Initiates the Action 
//------------------------------------------------------------------------------------------------------------------------
void UI_GetPatient::Action()
{
	Print();
	UIBase::mPrimaryTriage.RemoveMostRecent();
}
