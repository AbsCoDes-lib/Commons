//===--- ErrorCodeException.cpp ------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019-2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#include "Commons/Exceptions/ErrorCodeException.h"


namespace abscodes {
namespace commons {
  namespace exceptions {


    ErrorCodeException::ErrorCodeException(const std::string& message, LONG errorCode)
      : std::runtime_error(message)
      , _errorCode(errorCode) {}

    ErrorCodeException::ErrorCodeException(const char* message, LONG errorCode)
      : std::runtime_error(message)
      , _errorCode(errorCode) {}

    ErrorCodeException::ErrorCodeException(LONG errorCode)
      : std::runtime_error(nullptr)
      , _errorCode(errorCode) {}

    LONG ErrorCodeException::ErrorCode() const noexcept {
      return _errorCode;
    }

    std::string ErrorCodeException::ErrorCodeMessage() const noexcept {
      return GetErrorString(_errorCode);
    }

    std::string ErrorCodeException::GetErrorString() {
      return GetErrorString(::GetLastError());
    }

    std::string ErrorCodeException::GetErrorString(LONG errorCode) {
      if(errorCode == 0)
        return std::string();

      LPSTR lpMsgBuf = nullptr;

      const size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, errorCode,
                                         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPSTR>(&lpMsgBuf), 0, nullptr);

      std::string message(lpMsgBuf, size);

      // Free the buffer.
      LocalFree(lpMsgBuf);

      return message;

      // LPVOID lpMsgBuf = nullptr;

      // const size_t size = FormatMessageW(
      //	FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
      //	,nullptr
      //	, errorCode
      //	,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
      //	,reinterpret_cast<LPTSTR>(&lpMsgBuf)
      //	,0
      //	, nullptr);
      //
      // if (size)
      //{
      //	const auto lpMsgStr = static_cast<LPCSTR>(lpMsgBuf);
      //	std::string result(lpMsgStr, lpMsgStr + size);

      //	LocalFree(lpMsgBuf);

      //	return result;
      //}

      // return std::string();
    }

  } // namespace exceptions
} // namespace commons
} // namespace abscodes
