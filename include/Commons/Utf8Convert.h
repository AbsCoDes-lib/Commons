//===--- Utf8Convert.h ---------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//
//
// utf8conv.h -- Copyright (C) by Giovanni Dicanio
//
// This header file defines a couple of C++ functions to convert between
// UTF-8 and UTF-16 Unicode encodings.
//
// Function implementations are inline, so this module can be simply reused in
// C++ projects just by adding to your project this header file and the associated
// "utf8except.h" header defining the UTF-8 conversion exception class.
// Note that #including this header automatically #includes "utf8except.h".
//
// std::string is used to store UTF-8-encoded strings.
// std::wstring is used to store UTF-16-encoded strings.
//
// In case of conversion errors, instances of the Utf8ConversionException
// class are thrown.
//
// If the input string is too big and its size can't be safely converted
// to a value of type int, a std::overflow_error exception is thrown.
//
// Note that std::wstring is non-portable, as wchar_t's size is non-portable
// (e.g. 16 bits on Win32/Visual C++, 32 bits on Linux/GCC).
// But since this code directly interacts with Win32 APIs (MultiByteToWideChar
// and WideCharToMultiByte in particular), this portion of code is already
// platform-specific.
//
// This code is based on my MSDN Magazine article published
// on the 2016 September issue:
//
// "C++ - Unicode Encoding Conversions with STL Strings and Win32 APIs"
// https://msdn.microsoft.com/magazine/mt763237
//
//===-------------------------------------------------------------------------------------------------------------===//

#ifndef Commons_Utf8Convert_INCLUDED
#define Commons_Utf8Convert_INCLUDED


#include <Windows.h> // Win32 Platform SDK main header
#include <crtdbg.h> // For _ASSERTE()

#include <limits> // For std::numeric_limits
#include <stdexcept> // For std::overflow_error
#include <string> // For std::string and std::wstring
#include <vector>

#include "Commons/CommonsApi.h"

namespace AbsCoDes {
namespace Commons {
  namespace Utf8Convert {


    //------------------------------------------------------------------------------
    /// Convert form UTF-8 to UTF-16.
    /// Throws Utf8ConversionException on conversion errors
    /// (e.g. invalid UTF-8 sequence found in input string).
    //------------------------------------------------------------------------------
    Commons_API std::wstring Utf8ToUtf16(const std::string& utf8);


    //------------------------------------------------------------------------------
    /// Convert form UTF-8 to UTF-16.
    /// Throws Utf8ConversionException on conversion errors
    /// (e.g. invalid UTF-8 sequence found in input string).
    //------------------------------------------------------------------------------
    Commons_API std::vector<std::wstring> Utf8ToUtf16(const std::vector<std::string>& utf8vector);


    //------------------------------------------------------------------------------
    /// Convert form UTF-16 to UTF-8.
    /// Throws Utf8ConversionException on conversion errors
    /// (e.g. invalid UTF-16 sequence found in input string).
    //------------------------------------------------------------------------------
    Commons_API std::string Utf16ToUtf8(const std::wstring& utf16);


    //------------------------------------------------------------------------------
    /// Convert form UTF-16 to UTF-8.
    /// Throws Utf8ConversionException on conversion errors
    /// (e.g. invalid UTF-16 sequence found in input string).
    //------------------------------------------------------------------------------
    Commons_API std::vector<std::string> Utf16ToUtf8(const std::vector<std::wstring>& utf16vector);

  } // namespace Utf8Convert
} // namespace Commons
} // namespace AbsCoDes


#endif // Commons_Utf8Convert_INCLUDED
