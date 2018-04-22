#include "CppUnitTest.h"
#include "../COMP 3512 Assignment2/UI_AddPatient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestHosptialUI)
	{
	public:
		UI_AddPatient unitTestHostpitalUI;

		TEST_METHOD(Test_check_input_name_valid)
		{
			//Try to input first, last, and middle name. 
			//The total number of inputs is 3.
			std::string fName = "testFirst";
			std::string lName = "testLast";
			std::string mName = "testMiddle";
			int numInput = 3;

			Assert::AreEqual(true, unitTestHostpitalUI.checkValidName(fName, lName, mName, numInput));

			//Try to input first, and last name. 
			//The total number of inputs is 2.
			fName = "testFirst";
			mName = "";
			lName = "testLast";
			int numImput = 2;

			Assert::AreEqual(true, unitTestHostpitalUI.checkValidName(fName, lName, mName, numImput));
		}

		TEST_METHOD(Test_check_input_name_invalid)
		{
			//Try to input first, last, middle name, and more. 
			//The total number of inputs is 4.
			std::string fName = "testFirst";
			std::string lName = "testLast";
			std::string mName = "testMiddle";
			int numImput = 4;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidName(fName, mName, lName, numImput));

			//Try to input first name only.
			//The total number of inputs is 1.
			fName = "testFirst";
			lName = "";
			mName = "";
			numImput = 1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidName(fName, mName, lName, numImput));

			//Try to input nothing.
			//The total number of inputs is 0.
			fName = "";
			lName = "";
			mName = "";
			numImput = 0;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidName(fName, mName, lName, numImput));
		}

		TEST_METHOD(Test_check_input_birthday_valid)
		{
			int year, month, day;
			struct tm now;
			time_t longtime = time(NULL);
			localtime_s(&now, &longtime);

			//Check by valid dates
			year = 2018;
			month = 1;
			day = 1;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			year = 1970;
			month = 12;
			day = 31;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check by valid by Feb 29 on regular year
			year = 2004;
			month = 2;
			day = 29;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));
		}

		TEST_METHOD(Test_check_input_birthday_invalid)
		{
			int year, month, day;

			//Check invalid by future year
			year = 2100;
			month = 1;
			day = 1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check invalid by month = 0
			year = 2018;
			month = 0;
			day = 1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check invalid by month 13
			year = 2018;
			month = 13;
			day = 1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check invalid by day 0
			year = 2018;
			month = 1;
			day = 0;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check invalid by day January 32
			year = 2018;
			month = 1;
			day = 32;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));

			//Check by invalid by Feb 29 on regular year
			year = 2003;
			month = 2;
			day = 29;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidBirthDay(year, month, day));
		}

		TEST_METHOD(Test_check_input_PiN_valid)
		{
			std::string pin = "01234567";

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidPIN(pin));
		}

		TEST_METHOD(Test_check_input_PiN_invalid)
		{
			std::string pin = "";

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidPIN(pin));

			pin = "0123456";

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidPIN(pin));

			pin = "012345678";

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidPIN(pin));
		}

		TEST_METHOD(Test_check_input_Symptoms_valid)
		{
			std::string symp = "test";

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidSymptoms(symp));
		}

		TEST_METHOD(Test_check_input_Symptoms_invalid)
		{
			std::string symp = "";

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidSymptoms(symp));
		}

		TEST_METHOD(Test_check_input_time_valid)
		{
			//check by valid time
			int h = 0;
			int min = 0;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidTime(h, min));

			h = 23;
			min = 59;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidTime(h, min));
		}

		TEST_METHOD(Test_check_input_time_invalid)
		{
			//check by invalid time -1:00
			int h = -1;
			int min = 0;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));

			//check by invalid time 0:-1
			h = 0;
			min = -1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));

			//check by invalid time -1:-1
			h = -1;
			min = -1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));

			//check by invalid time 24:00
			h = 24;
			min = 0;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));

			//check by invalid time 00:60
			h = 0;
			min = 60;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));

			//check by invalid time 24:60
			h = 24;
			min = 60;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidTime(h, min));
		}

		TEST_METHOD(Test_check_input_category_valid)
		{
			//check by valid category number
			int catNum = 0;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidCategory(catNum));

			catNum = 5;

			Assert::AreEqual(true,
				unitTestHostpitalUI.checkValidCategory(catNum));
		}

		TEST_METHOD(Test_check_input_category_invalid)
		{
			//check by invalid category number
			int catNum = -1;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidCategory(catNum));

			catNum = 6;

			Assert::AreEqual(false,
				unitTestHostpitalUI.checkValidCategory(catNum));
		}
	};
}