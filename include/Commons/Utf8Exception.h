//===--- Utf8Exception.h ---------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef COMMONS_UTF8_EXCEPTION_INCLUDED
#define COMMONS_UTF8_EXCEPTION_INCLUDED


#include "Commons/CommonsApi.h"

#pragma warning(push)
#pragma warning(disable : 4275)

namespace abscodes {
namespace commons {
  namespace utf8convert {

    ///
    class COMMONS_API Utf8ConversionException : public std::runtime_error {

     public:
      ///
      /// Possible conversion "directions"
      ///
      enum class ConversionType { FromUtf8ToUtf16 = 0, FromUtf16ToUtf8 };

      ///
      /// Initialize with error message raw C-string, last Win32 error code and conversion direction
      ///
      Utf8ConversionException(const char* message, uint32_t errorCode, ConversionType type);

      ///
      /// Initialize with error message string, last Win32 error code and conversion direction
      ///
      Utf8ConversionException(const std::string& message, uint32_t errorCode, ConversionType type);

      ///
      /// Retrieve error code associated to the failed conversion
      ///
      uint32_t ErrorCode() const;

      ///
      /// Direction of the conversion (e.g. from UTF-8 to UTF-16)
      ///
      ConversionType Direction() const;


     private:
      ///
      /// Error code from GetLastError()
      ///
      uint32_t _errorCode;

      ///
      /// Direction of the conversion
      ///
      ConversionType _conversionType;
    };

  } // namespace Utf8Exception
} // namespace commons
} // namespace abscodes

#pragma warning(pop)

#endif // COMMONS_UTF8_EXCEPTION_INCLUDED
