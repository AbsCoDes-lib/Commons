//===--- Utf8Exception.cpp -------------------------------------------------------------------------------*- C++ -*-===//
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


#include "Commons/Utf8Exception.h"


namespace AbsCoDes {
namespace Commons {
  namespace Utf8Convert {

    Utf8ConversionException::Utf8ConversionException(const char* const message, const uint32_t errorCode, const ConversionType type)
      : std::runtime_error(message)
      , _errorCode(errorCode)
      , _conversionType(type) {}


    Utf8ConversionException::Utf8ConversionException(const std::string& message, const uint32_t errorCode, const ConversionType type)
      : std::runtime_error(message)
      , _errorCode(errorCode)
      , _conversionType(type) {}


    uint32_t Utf8ConversionException::ErrorCode() const {
      return _errorCode;
    }


    Utf8ConversionException::ConversionType Utf8ConversionException::Direction() const {
      return _conversionType;
    }

  } // namespace Utf8Exception
} // namespace Commons
} // namespace AbsCoDes
