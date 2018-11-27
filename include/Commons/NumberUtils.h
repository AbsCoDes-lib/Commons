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


#ifndef Commons_NumberUtils_INCLUDED
#define Commons_NumberUtils_INCLUDED


#include "Commons/CommonsApi.h"

#include <sstream>
#include <string>

namespace AbsCoDes {
namespace Commons {
  namespace NumberUtils {

    ///
    template<typename T>
    std::string toString(const T& number);

    ///
    template<typename T>
    T toNumber(const std::string& number);

  } // namespace NumberUtils


  template<typename T>
  std::string NumberUtils::toString(const T& number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
  }

  template<typename T>
  T NumberUtils::toNumber(const std::string& number) {
    T                  n = 0;
    std::istringstream iss(number);
    iss >> n;
    return n;
  }

} // namespace Commons
} // namespace AbsCoDes


#endif // Commons_NumberUtils_INCLUDED
