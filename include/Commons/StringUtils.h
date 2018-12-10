//===--- StringUtils.h ---------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef COMMONS_STRING_UTILS_INCLUDED
#define COMMONS_STRING_UTILS_INCLUDED


#include <string>
#include <vector>

#include "Commons/CommonsApi.h"


namespace abscodes {
namespace commons {
  namespace string {

    /// Tests whether the string starts with the given prefix.
    COMMONS_API bool startsWith(__in const std::string& string, __in const std::string& prefix);
    /// Tests whether the string ends with the given suffix.
    COMMONS_API bool endsWith(__in const std::string& string, __in const std::string& suffix);

    /// Converts a string to an lowercase string.
    COMMONS_API std::string toLower(__in std::string& string);
    /// Converts a string to an uppercase string.
    COMMONS_API std::string toUpper(__in std::string& string);

    /// Trim from start
    COMMONS_API std::string ltrim(__in std::string& string);
    COMMONS_API std::string ltrim(__in std::string& string, int ch);
    /// Trim from end
    COMMONS_API std::string rtrim(__in std::string& string);
    COMMONS_API std::string rtrim(__in std::string& string, int ch);
    /// Trim from both ends
    COMMONS_API std::string trim(__in std::string& string);
    COMMONS_API std::string trim(__in std::string& string, int ch);

    /// Join a vector of string by a string delimiter.
    COMMONS_API std::string join(__in std::vector<std::string>& elements, __in const std::string& delimiter);

    /// Split a string on a single delimiter character (delimiter)
    COMMONS_API std::vector<std::string>& split(__in const std::string& toSplit, __in char delimiter, __inout std::vector<std::string>& elements);
    COMMONS_API std::vector<std::string> split(__in const std::string& toSplit, __in char delimiter);

    /// Split a string on any character found in the string of delimiters (delimiters)
    COMMONS_API std::vector<std::string>& split(__in const std::string& toSplit, __in const std::string& delimiters,
                                                __inout std::vector<std::string>& elements);
    COMMONS_API std::vector<std::string> split(__in const std::string& toSplit, __in const std::string& delimiters);

    /// Replace a string by an other
    COMMONS_API std::string replaceAll(__in std::string& string, __in const std::string& sFind, __in const std::string& sReplace);


    namespace InPlace {

      /// Converts a string to an lowercase string.
      COMMONS_API void toLower(__in std::string& string);
      /// Converts a string to an uppercase string.
      COMMONS_API void toUpper(__in std::string& string);

      /// Trim from start
      COMMONS_API void ltrim(__in std::string& string);
      COMMONS_API void ltrim(__in std::string& string, int ch);
      /// Trim from end
      COMMONS_API void rtrim(__in std::string& string);
      COMMONS_API void rtrim(__in std::string& string, int ch);
      /// Trim from both ends
      COMMONS_API void trim(__in std::string& string);
      COMMONS_API void trim(__in std::string& string, int ch);

      /// Replace a string by an other
      COMMONS_API void replaceAll(__in std::string& string, __in const std::string& sFind, __in const std::string& sReplace);

    } // namespace InPlace

  } // namespace string
} // namespace commons
} // namespace abscodes


#endif // COMMONS_STRING_UTILS_INCLUDED
