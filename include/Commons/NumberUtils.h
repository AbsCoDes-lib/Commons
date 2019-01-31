//===--- NumberUtils.h ---------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef COMMONS_NUMBER_UTILS_INCLUDED
#define COMMONS_NUMBER_UTILS_INCLUDED


#include "Commons/CommonsApi.h"

#include <sstream>
#include <string>

namespace abscodes {
namespace commons {
  namespace number {

    ///
    template<typename T>
    std::string toString(const T& number);

    ///
    template<typename T>
    T toNumber(const std::string& number);

    ///
    template<typename T>
    T toNumber(const std::wstring& number);

  } // namespace number


  template<typename T>
  std::string number::toString(const T& number) {
     std::ostringstream oss;
     oss << number;
     return oss.str();
  }

  template<typename T>
  T number::toNumber(const std::string& number) {
    T                  n = 0;
    std::istringstream iss(number);
    iss >> n;
    return n;
  }

  template<typename T>
  T number::toNumber(const std::wstring& number) {
    T                   n = 0;
    std::wistringstream iss(number);
    iss >> n;
    return n;
  }

} // namespace commons
} // namespace abscodes


#endif // COMMONS_NUMBER_UTILS_INCLUDED
