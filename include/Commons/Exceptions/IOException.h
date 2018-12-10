//===--- IOException.h ---------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019-2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef IO_EXCEPTION_INCLUDED
#define IO_EXCEPTION_INCLUDED


#include "Commons/CommonsApi.h"
#include "Commons/Exceptions/ErrorCodeException.h"


namespace abscodes {
namespace commons {
  namespace exceptions {


    ///
    class COMMONS_API IOException : public ErrorCodeException {
     public:
      /// Construct a IOException.
      explicit IOException(const std::string& message, LONG errorCode);

      /// Construct a IOException.
      explicit IOException(const char* message, LONG errorCode);

      /// Construct a IOException.
      explicit IOException(LONG errorCode);
    };


  } // namespace exceptions
} // namespace commons
} // namespace abscodes


#endif // IO_EXCEPTION_INCLUDED
