#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "Commons\NumberUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AbsCoDes::Commons;

namespace CommonsTests
{		
	TEST_CLASS(NumberUtils_Tests)
	{
	public:

		TEST_METHOD(toString)
		{
			Assert::IsTrue(NumberUtils::toString(1) == "1");
			Assert::IsTrue(NumberUtils::toString((int)1) == "1");
			Assert::IsTrue(NumberUtils::toString((unsigned int)1) == "1");
			Assert::IsTrue(NumberUtils::toString((long)1) == "1");
			Assert::IsTrue(NumberUtils::toString((unsigned long)1) == "1");
			
			Assert::IsTrue(NumberUtils::toString(-1) == "-1");
			Assert::IsTrue(NumberUtils::toString((int)-1) == "-1");
			Assert::IsTrue(NumberUtils::toString((long)-1) == "-1");
			
			Assert::IsTrue(NumberUtils::toString(2147483648) == "2147483648");
			Assert::IsTrue(NumberUtils::toString((unsigned long)2147483648) == "2147483648");
			
			Assert::IsTrue(NumberUtils::toString(1.2) == "1.2");
			Assert::IsTrue(NumberUtils::toString((float)1.2) == "1.2");
			Assert::IsTrue(NumberUtils::toString((double)1.2) == "1.2");
		}

		TEST_METHOD(toNumber)
		{
			Assert::IsTrue(NumberUtils::toNumber<int>("1") == 1);
			Assert::IsTrue(NumberUtils::toNumber<unsigned int>("1") == 1);
			Assert::IsTrue(NumberUtils::toNumber<long>("1") == 1);
			Assert::IsTrue(NumberUtils::toNumber<unsigned long>("1") == 1);
			
			Assert::IsTrue(NumberUtils::toNumber<int>("-1") == -1);
			Assert::IsTrue(NumberUtils::toNumber<long>("-1") == -1);
			
			Assert::IsTrue(NumberUtils::toNumber<unsigned long>("2147483648") == 2147483648);
			
			Assert::IsTrue(NumberUtils::toNumber<float>("1.2") == (float)1.2);
			Assert::IsTrue(NumberUtils::toNumber<double>("1.2") == 1.2);
		}

	};
}