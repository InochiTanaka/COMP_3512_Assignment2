#include "HospitalUI.h"
#include "PriorityQueue.h"
// Input Class Should have a local Patient that will be passed afterwards

void quetest();
int main() 
{
	
	//HospitalUI test;
	
	//std::cout << test.addSequence();

	quetest();

	system("Pause");

	return 0;
}
void quetest() 
{
	PriorityQueue newList;
	Patient test1;
	test1.SetName("Joseph", "", "Yang");
	test1.SetPIN("01234567");
	test1.SetBirthYear(1991);
	test1.SetBirthMonth(2);
	test1.SetBirthDay(13);
	test1.SetCategory(0);
	test1.SetSymptoms("I'm Sick");
	test1.SetAdmissionDate("23:00");

	newList.AddToList(test1, (PriorityLevel)test1.GetCategory());
	test1.SetPIN("01234568");
	newList.AddToList(test1, PriorityLevel::GOOD);
	test1.SetPIN("01234597");
	newList.AddToList(test1, PriorityLevel::SERIOUS);
	

	system("Pause");

}

