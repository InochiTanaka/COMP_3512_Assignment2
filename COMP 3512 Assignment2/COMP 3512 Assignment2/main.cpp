#include "HospitalUI.h"
#include "PriorityQueue.h"
#include "Triage.h"
// Input Class Should have a local Patient that will be passed afterwards

#include "UI_Main.h"

int main() 
{
	UI_Main HospitalUI; // EVERYTHING IS IN HERE CHRIS

	while (HospitalUI.IsRunning())
	{
		HospitalUI.Print();
		HospitalUI.Action();
	}

	//HospitalUI test;
	//std::cout << test.addSequence();
	return 0;
}

