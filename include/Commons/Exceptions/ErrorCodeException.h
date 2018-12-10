//===--- ErrorCodeException.h --------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019-2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef ERROR_CODE_EXCEPTION_INCLUDED
#define ERROR_CODE_EXCEPTION_INCLUDED

#include <stdexcept>

#include "Commons/CommonsApi.h"


#pragma warning(push)
#pragma warning(disable : 4275)

namespace abscodes {
namespace commons {
  namespace exceptions {


    ///
    class COMMONS_API ErrorCodeException : public std::runtime_error {
     public:
      /// Construct a ErrorCodeException.
      explicit ErrorCodeException(const std::string& message, LONG errorCode);

      /// Construct a ErrorCodeException.
      explicit ErrorCodeException(const char* message, LONG errorCode);

      /// Construct a ErrorCodeException.
      explicit ErrorCodeException(LONG errorCode);

     public:
      /// Get the error code returned by Windows registry APIs
      LONG ErrorCode() const noexcept;

      /// Get the error code returned by Windows registry APIs
      std::string ErrorCodeMessage() const noexcept;

      /// Create a std::string containg the last Win32 error.
      /// Returns an empty string if there is no error.
      static std::string GetErrorString();

      /// Create a std::string containg the Win32 error.
      /// Returns an empty string if there is no error.
      static std::string GetErrorString(LONG errorCode);

     private:
      /// Error code, as returned by Windows registry APIs
      LONG _errorCode;
    };


  } // namespace exceptions
} // namespace commons
} // namespace abscodes

#pragma warning(pop)

#endif // ERROR_CODE_EXCEPTION_INCLUDED
