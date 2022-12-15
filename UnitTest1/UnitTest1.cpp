#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_0.9.3/Lab_0.9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Note* p = new Note;
			p->prizv = "Kryk";
			p->name = "Olo";
			p->tel_number = 38023124;
			p->birthday[1] = 05;
			p->birthday[2] = 05;
			p->birthday[3] = 2005;

			double t = BinSearch(p, 1, "Kryk");

			Assert::AreEqual(t, 0.);
		}
	};
}
