#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "Commons\StringUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace abscodes::commons;

namespace CommonsTests
{		
	TEST_CLASS(StringUtils_Tests)
	{
	public:

		TEST_METHOD(startsWith)
		{
			std::string s = "This start with : This";
			Assert::IsTrue(string::startsWith(s, "This"));
			Assert::IsFalse(string::startsWith(s, "this"));
		}

		TEST_METHOD(endsWith)
		{
			std::string s = "This end with : This";
			Assert::IsTrue(string::endsWith(s, "This"));
			Assert::IsFalse(string::endsWith(s, "this"));
		}

		TEST_METHOD(toLower)
		{
			std::string s = "This contains Upper and Lower strings";
			std::string ls = "this contains upper and lower strings";
			Assert::IsTrue(s != ls);
			Assert::IsTrue(string::toLower(s) == ls);
			Assert::IsTrue(s != ls);
		}

		TEST_METHOD(toLower_inPlace)
		{
			std::string s = "This contains Upper and Lower strings";
			std::string ls = "this contains upper and lower strings";
			Assert::IsTrue(s != ls);
			string::InPlace::toLower(s);
			Assert::IsTrue(s == ls);
		}

		TEST_METHOD(toUpper)
		{
			std::string s = "This contains Upper and Lower strings";
			std::string us = "THIS CONTAINS UPPER AND LOWER STRINGS";
			Assert::IsTrue(s != us);
			Assert::IsTrue(string::toUpper(s) == us);
			Assert::IsTrue(s != us);
		}

		TEST_METHOD(toUpper_inPlace)
		{
			std::string s = "This contains Upper and Lower strings";
			std::string us = "THIS CONTAINS UPPER AND LOWER STRINGS";
			Assert::IsTrue(s != us);
			string::InPlace::toUpper(s);
			Assert::IsTrue(s == us);
		}

		TEST_METHOD(trim)
		{
			std::string s = "     This string is  shorter  once escapes removed     ";
			Assert::IsTrue(string::trim(s) == "This string is  shorter  once escapes removed");
		}

		TEST_METHOD(trim_inPlace)
		{
			std::string s = "     This string is  shorter  once escapes removed     ";
			string::InPlace::trim(s);
			Assert::IsTrue(s == "This string is  shorter  once escapes removed");
		}

		TEST_METHOD(trim_ch)
		{
			std::string s = "this string as no ! at the end !!!!!!";
			Assert::IsTrue(string::trim(s, '!') == "this string as no ! at the end ");
		}

		TEST_METHOD(join)
		{
			std::vector<std::string> s;
			s.push_back("this");
			s.push_back("will");
			s.push_back("be");
			s.push_back("joined");

			std::string joined = string::join(s, "|");

			Assert::IsTrue(joined == "this|will|be|joined");
		}

		TEST_METHOD(Split)
		{
			std::string toSplit = "this will be split on\ttabs\tand spaces";
			std::string delimiter = " \t";
			std::vector<std::string> v1 = string::split(toSplit, delimiter);
			Assert::IsTrue(v1.size() == 8);

			toSplit = "this will be split on spaces";
			std::vector<std::string> v2 = string::split(toSplit, ' ');
			Assert::IsTrue(v2.size() == 6);
		}

		TEST_METHOD(Replaceall)
		{
			std::string string = "***|***|***|***";
			std::string sFind = "|";
			std::string sReplace = ".";
			Assert::IsTrue(string::replaceAll(string,sFind,sReplace) == "***.***.***.***");
		}

	};
}