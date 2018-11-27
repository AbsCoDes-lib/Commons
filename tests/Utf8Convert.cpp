#include "stdafx.h"
#include "CppUnitTest.h"

#include "Commons\Utf8Convert.h"
#include "Commons\Utf8Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AbsCoDes::Commons;

namespace CommonsTests
{		
	TEST_CLASS(Utf8Convert_Tests)
	{
	public:

		TEST_METHOD(BasicConversionsWithStlStrings)
		{   
			std::wstring s1u16 = L"Hello world";
			std::string s1u8 = Utf8Convert::Utf16ToUtf8(s1u16);
			std::wstring s1u16back = Utf8Convert::Utf8ToUtf16(s1u8);
			if (s1u16back != s1u16)
			{
				throw std::runtime_error("Converting from UTF-16 to UTF-8 and back gives different string.");
			}

			std::string s2u8 = "Ciao ciao";
			std::wstring s2u16 = Utf8Convert::Utf8ToUtf16(s2u8);
			std::string s2u8back = Utf8Convert::Utf16ToUtf8(s2u16);
			if (s2u8back != s2u8)
			{
				throw std::runtime_error("Converting from UTF-8 to UTF-16 and back gives different string.");
			}
		}

		TEST_METHOD(BasicConversionWithRawPointers)
		{
			const wchar_t* const s1u16 = L"Hello world";
			std::string s1u8 = Utf8Convert::Utf16ToUtf8(s1u16);
			std::wstring s1u16back = Utf8Convert::Utf8ToUtf16(s1u8);
			if (s1u16back != s1u16)
			{
				throw std::runtime_error("Converting raw pointers from UTF-16 to UTF-8 and back gives different string.");
			}

			const char* const s2u8 = "Ciao ciao";
			std::wstring s2u16 = Utf8Convert::Utf8ToUtf16(s2u8);
			std::string s2u8back = Utf8Convert::Utf16ToUtf8(s2u16);
			if (s2u8back != s2u8)
			{
				throw std::runtime_error("Converting raw pointers from UTF-8 to UTF-16 and back gives different string.");
			}
		}

		TEST_METHOD(EmptyStringConversions)
		{
			const std::wstring u16empty;
			const std::string u8empty;
			
			if (!Utf8Convert::Utf16ToUtf8(u16empty).empty())
			{
				throw std::runtime_error("Empty UTF-16 string is not converted to an empty UTF-8.");
			}

			if (!Utf8Convert::Utf8ToUtf16(u8empty).empty())
			{
				throw std::runtime_error("Empty UTF-8 string is not converted to an empty UTF-16.");
			}

			if (!Utf8Convert::Utf16ToUtf8(L"").empty())
			{
				throw std::runtime_error("Empty UTF-16 raw string ptr is not converted to an empty UTF-8.");
			}

			if (!Utf8Convert::Utf8ToUtf16("").empty())
			{
				throw std::runtime_error("Empty UTF-8 raw string ptr is not converted to an empty UTF-16.");
			}
		}

		TEST_METHOD(JapaneseKin)
		{
			//
			// Test "kin"
			// UTF-16: 91D1
			// UTF-8:  E9 87 91
			//

			const std::string kinU8 = "\xE9\x87\x91";
			const std::wstring kinU16 = L"\x91D1";
			Assert::IsTrue(Utf8Convert::Utf8ToUtf16(kinU8) == kinU16);
			Assert::IsTrue(Utf8Convert::Utf16ToUtf8(kinU16) == kinU8);
		}

		TEST_METHOD(InvalidUnicodeSequences)
		{
			try
			{
				// String containing invalid UTF-8
				const std::string invalidUtf8 = "Invalid UTF-8 follows: \xC0\x76\x77";

				// The following line should throw because of invalid UTF-8 sequence
				// in input string
				std::wstring invalidUtf16 = Utf8Convert::Utf8ToUtf16(invalidUtf8);
				
				throw std::runtime_error("Utf8Convert::Utf8ConversionException not thrown in presence of invalid UTF-8.");
			}
			catch (const Utf8Convert::Utf8ConversionException& utf8error)
			{
				if (utf8error.ErrorCode() != ERROR_NO_UNICODE_TRANSLATION)
				{
					throw std::runtime_error("Error code different than ERROR_NO_UNICODE_TRANSLATION.");
				}

				if (utf8error.Direction() != Utf8Convert::Utf8ConversionException::ConversionType::FromUtf8ToUtf16)
				{
					throw std::runtime_error("Wrong conversion type stored in exception class.");
				}
			}

			try
			{
				// String containing invalid UTF-16
				const std::wstring invalidUtf16 = L"Invalid UTF-16: \xD800\x0100";

				// The following line should throw because of invalid UTF-16 sequence
				// in input string
				std::string invalidUtf8 = Utf8Convert::Utf16ToUtf8(invalidUtf16);

				throw std::runtime_error("Utf8Convert::Utf8ConversionException not thrown in presence of invalid UTF-16.");
			}
			catch (const Utf8Convert::Utf8ConversionException& utf8error)
			{
				if (utf8error.ErrorCode() != ERROR_NO_UNICODE_TRANSLATION)
				{
					throw std::runtime_error("Error code different than ERROR_NO_UNICODE_TRANSLATION.");
				}

				if (utf8error.Direction() != Utf8Convert::Utf8ConversionException::ConversionType::FromUtf16ToUtf8)
				{
					throw std::runtime_error("Wrong conversion type stored in exception class.");
				}
			}
		}

	};
}