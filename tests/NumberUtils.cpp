#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "Commons\NumberUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace abscodes::commons;

namespace CommonsTests
{		
	TEST_CLASS(NumberUtils_Tests)
	{
	public:

		TEST_METHOD(toString)
		{
			Assert::IsTrue(number::toString(1) == "1");
			Assert::IsTrue(number::toString((int)1) == "1");
			Assert::IsTrue(number::toString((unsigned int)1) == "1");
			Assert::IsTrue(number::toString((long)1) == "1");
			Assert::IsTrue(number::toString((unsigned long)1) == "1");
			
			Assert::IsTrue(number::toString(-1) == "-1");
			Assert::IsTrue(number::toString((int)-1) == "-1");
			Assert::IsTrue(number::toString((long)-1) == "-1");
			
			Assert::IsTrue(number::toString(2147483648) == "2147483648");
			Assert::IsTrue(number::toString((unsigned long)2147483648) == "2147483648");
			
			Assert::IsTrue(number::toString(1.2) == "1.2");
			Assert::IsTrue(number::toString((float)1.2) == "1.2");
			Assert::IsTrue(number::toString((double)1.2) == "1.2");

			Assert::IsTrue(number::toString("1") == "1");
		}

		TEST_METHOD(toNumber)
		{
			Assert::IsTrue(number::toNumber<int>("1") == 1);
			Assert::IsTrue(number::toNumber<unsigned int>("1") == 1);
			Assert::IsTrue(number::toNumber<long>("1") == 1);
			Assert::IsTrue(number::toNumber<unsigned long>("1") == 1);

			Assert::IsTrue(number::toNumber<int>("-1") == -1);
			Assert::IsTrue(number::toNumber<long>("-1") == -1);

			Assert::IsTrue(number::toNumber<unsigned long>("2147483648") == 2147483648);

			Assert::IsTrue(number::toNumber<float>("1.2") == (float)1.2);
			Assert::IsTrue(number::toNumber<double>("1.2") == 1.2);
		}

		TEST_METHOD(toNumber_wide)
		{
			Assert::IsTrue(number::toNumber<int>(L"1") == 1);
			Assert::IsTrue(number::toNumber<unsigned int>(L"1") == 1);
			Assert::IsTrue(number::toNumber<long>(L"1") == 1);
			Assert::IsTrue(number::toNumber<unsigned long>(L"1") == 1);

			Assert::IsTrue(number::toNumber<int>(L"-1") == -1);
			Assert::IsTrue(number::toNumber<long>(L"-1") == -1);

			Assert::IsTrue(number::toNumber<unsigned long>(L"2147483648") == 2147483648);

			Assert::IsTrue(number::toNumber<float>(L"1.2") == (float)1.2);
			Assert::IsTrue(number::toNumber<double>(L"1.2") == 1.2);
		}

	};
}
