#include "UI_ChangeCategory.h"

using namespace std;

void UI_ChangeCategory::Print()
{
	InputPatientPIN();
}

void UI_ChangeCategory::Action()
{
	Print();

	if (UIBase::mPrimaryTriage.SearchPatient(mInputPIN))
	{
		InputPatientCategory(UIBase::mPrimaryTriage.GetPatientByPIN(mInputPIN));

		mPrimaryTriage.UpdateList();
	}
	else
	{
		cout << "No Match" << endl;
	}
}

void UI_ChangeCategory::InputPatientPIN()
{
	do
	{
		std::cout << "Input Patient's Personal Healthcare Number(PIN): ";
		std::cin >> mInputPIN;
		std::cin.clear();
		std::cin.ignore();

		//inputFirstName >> inputLastName >> inputMiddleName;

		std::stringstream ss(mInputPIN);

	} while (!CheckValidPIN(mInputPIN));
}

void UI_ChangeCategory::InputPatientCategory(Patient& p)
{
	int categorySeriousness;

	do
	{
		std::cout << "Category List of Seriousness :\n";
		std::cout << "1 : Critical and life-threatening, requires immediate care \n";
		std::cout << "2 : Critical, requires care every soon \n";
		std::cout << "3 : Serious, requires care 'soon' \n";
		std::cout << "4 : Serious \n";
		std::cout << "5 : Non-serious \n";
		std::cout << "6 : Not a priority \n" << "\n";
		std::cout << "Input Patient's Number of Seriousness's Category: ";

		std::cin >> categorySeriousness;
		std::cin.clear();

	} while (!CheckValidCategory(categorySeriousness));

	// Indexing starts at 0
	p.SetCategory((PriorityLevel)(categorySeriousness - 1));

}
