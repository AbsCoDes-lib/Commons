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


#ifndef Commons_StringUtils_INCLUDED
#define Commons_StringUtils_INCLUDED


#include <string>
#include <vector>

#include "Commons/CommonsApi.h"


namespace AbsCoDes {
namespace Commons {
  namespace StringUtils {

    /// Tests whether the string starts with the given prefix.
    Commons_API bool startsWith(__in const std::string& string, __in const std::string& prefix);
    /// Tests whether the string ends with the given suffix.
    Commons_API bool endsWith(__in const std::string& string, __in const std::string& suffix);

    /// Converts a string to an lowercase string.
    Commons_API std::string toLower(__in std::string& string);
    /// Converts a string to an uppercase string.
    Commons_API std::string toUpper(__in std::string& string);

    /// Trim from start
    Commons_API std::string ltrim(__in std::string& string);
    Commons_API std::string ltrim(__in std::string& string, int ch);
    /// Trim from end
    Commons_API std::string rtrim(__in std::string& string);
    Commons_API std::string rtrim(__in std::string& string, int ch);
    /// Trim from both ends
    Commons_API std::string trim(__in std::string& string);
    Commons_API std::string trim(__in std::string& string, int ch);

    /// Join a vector of string by a string delimiter.
    Commons_API std::string join(__in std::vector<std::string>& elements, __in const std::string& delimiter);

    /// Split a string on a single delimiter character (delimiter)
    Commons_API std::vector<std::string>& split(__in const std::string& toSplit, __in char delimiter, __inout std::vector<std::string>& elements);
    Commons_API std::vector<std::string> split(__in const std::string& toSplit, __in char delimiter);

    /// Split a string on any character found in the string of delimiters (delimiters)
    Commons_API std::vector<std::string>& split(__in const std::string& toSplit, __in const std::string& delimiters,
                                                __inout std::vector<std::string>& elements);
    Commons_API std::vector<std::string> split(__in const std::string& toSplit, __in const std::string& delimiters);

    /// Replace a string by an other
    Commons_API std::string replaceAll(__in std::string& string, __in const std::string& sFind, __in const std::string& sReplace);


    namespace InPlace {

      /// Converts a string to an lowercase string.
      Commons_API void toLower(__in std::string& string);
      /// Converts a string to an uppercase string.
      Commons_API void toUpper(__in std::string& string);

      /// Trim from start
      Commons_API void ltrim(__in std::string& string);
      Commons_API void ltrim(__in std::string& string, int ch);
      /// Trim from end
      Commons_API void rtrim(__in std::string& string);
      Commons_API void rtrim(__in std::string& string, int ch);
      /// Trim from both ends
      Commons_API void trim(__in std::string& string);
      Commons_API void trim(__in std::string& string, int ch);

      /// Replace a string by an other
      Commons_API void replaceAll(__in std::string& string, __in const std::string& sFind, __in const std::string& sReplace);

    } // namespace InPlace

  } // namespace StringUtils
} // namespace Commons
} // namespace AbsCoDes


#endif // Commons_StringUtils_INCLUDED
