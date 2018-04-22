#include "CppUnitTest.h"
#include "../COMP 3512 Assignment2/HospitalUI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestHosptialUI)
	{
	public:
		HospitalUI unitTestHostpitalUI;
		
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

		////TEST_METHOD(Test_check_input_name_invalid)
		////{
		////}

	};
}