#include <iostream>
#include "UI_Main.h"

using namespace std;

UI_Main::UI_Main()
	:bRunning(true)
{
	mTriageHandler = new Triage();
}

void UI_Main::Print()
{
	cout << "\n------------ Main Menu ------------" << endl
		<< "(a) Add new patient" << endl
		<< "(b) Get next patient" << endl
		<< "(c) Change patient category" << endl
		<< "(d) Save patient list" << endl
		<< "(e) Load patient list" << endl
		<< "(f) Print patient list" << endl
		<< "(g) Exit program" << endl;
}

void UI_Main::Action()
{
	UIBase* UIAgent = new UIBase();
	char input;

	cin >> input;
	cin.clear();			// after storing it, clear the buffer
	cin.ignore(100, '\n');	// Get Buffer values / manual Flush
	//fflush(stdin);			// Flush cin

	if (input == 'g' || input == '7')
		bRunning = false;				// Immediately quit
	else
	{
		if (input == 'a' || input == '1')
		{
			UIAgent = new UI_AddPatient(*mTriageHandler);
		}
		else if (input == 'b' || input == '2')
		{
			UIAgent = new UI_GetPatient(*mTriageHandler);
		}
		else if (input == 'c' || input == '3')
		{
			UIAgent = new UI_ChangeCategory(*mTriageHandler);
		}
		else if (input == 'd' || input == '4')
		{
			UIAgent = new UI_Save(*mTriageHandler);
		}
		else if (input == 'e' || input == '5')
		{
			//UIAgent = new UI_Load(*mTriageHandler);
		}
		else // else if (input == 'f' || input == '6')
		{
			UIAgent = new UI_Print(*mTriageHandler);
		}

		// Do Action based on state
		UIAgent->Action();

	} //end of else (input == 'g' || input == '7')

	cout << endl << endl;		// Spacing
	delete UIAgent;				// After you finished action, delete ptr
	UIAgent = nullptr;	

}
