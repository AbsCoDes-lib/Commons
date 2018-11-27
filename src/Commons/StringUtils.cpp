//===--- StringUtils.cpp -------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#include <algorithm>
#include <cctype>
#include <functional>
#include <sstream>

#include "Commons/StringUtils.h"


namespace AbsCoDes {
namespace Commons {
  namespace StringUtils {

    // Tests whether the string starts with the given prefix.
    bool startsWith(__in const std::string& string, __in const std::string& prefix) {
      return prefix.size() <= string.size() && string.compare(0, prefix.size(), prefix) == 0;
    }

    // Tests whether the string ends with the given suffix.
    bool endsWith(__in const std::string& string, __in const std::string& suffix) {
      return string.size() >= suffix.size() && string.compare(string.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    // Converts a string to an lowercase string.
    std::string toLower(__in std::string& string) {
      std::string s = string;
      InPlace::toLower(s);
      return s;
    }

    // Converts a string to an uppercase string.
    std::string toUpper(__in std::string& string) {
      std::string s = string;
      InPlace::toUpper(s);
      return s;
    }

    // Trim from start
    std::string ltrim(__in std::string& string) {
      std::string s = string;
      InPlace::ltrim(s);
      return s;
    }

    // Trim from start
    std::string ltrim(std::string& string, int ch) {
      std::string s = string;
      InPlace::ltrim(s, ch);
      return s;
    }

    // Trim from end
    std::string rtrim(__in std::string& string) {
      std::string s = string;
      InPlace::rtrim(s);
      return s;
    }

    // Trim from end
    std::string rtrim(__in std::string& string, int ch) {
      std::string s = string;
      InPlace::rtrim(s, ch);
      return s;
    }

    // Trim from both ends
    std::string trim(__in std::string& string) {
      std::string s = string;
      InPlace::trim(s);
      return s;
    }

    // Trim from both ends
    std::string trim(__in std::string& string, int ch) {
      std::string s = string;
      InPlace::trim(s, ch);
      return s;
    }

    // Join a vector of string by a string delimiter.
    std::string join(__in std::vector<std::string>& elements, __in const std::string& delimiter) {
      std::stringstream ss;
      auto              element = elements.begin();
      ss << *element++;
      for(; element != elements.end(); ++element) {
        ss << delimiter << *element;
      }
      return ss.str();
    }

    // Split a string on a single delimiter character (delimiter)
    std::vector<std::string>& split(__in const std::string& toSplit, __in char delimiter, __inout std::vector<std::string>& elements) {
      std::stringstream ss(toSplit);
      std::string       item;
      while(std::getline(ss, item, delimiter)) {
        elements.push_back(item);
      }
      return elements;
    }

    // Split a string on a single delimiter character (delimiter)
    std::vector<std::string> split(__in const std::string& toSplit, __in char delimiter) {
      std::vector<std::string> elements;
      return split(toSplit, delimiter, elements);
    }

    // Split a string on any character found in the string of delimiters (delimiters)
    std::vector<std::string>& split(__in const std::string& toSplit, __in const std::string& delimiters, __inout std::vector<std::string>& elements) {
      char* token;
      char* next_token;
      char* cstr = _strdup(toSplit.c_str());

      token = strtok_s(cstr, delimiters.c_str(), &next_token);

      while(token != nullptr) {
        elements.push_back(token);
        token = strtok_s(nullptr, delimiters.c_str(), &next_token);
      }
      return elements;
    }

    // Split a string on any character found in the string of delimiters (delimiters)
    std::vector<std::string> split(__in const std::string& toSplit, __in const std::string& delimiters) {
      std::vector<std::string> elements;
      return split(toSplit, delimiters, elements);
    }

    std::string replaceAll(std::string& string, const std::string& sFind, const std::string& sReplace) {
      std::string s = string;
      InPlace::replaceAll(s, sFind, sReplace);
      return s;
    }

    void InPlace::toLower(std::string& string) {
      transform(string.begin(), string.end(), string.begin(), tolower);
    }

    void InPlace::toUpper(std::string& string) {
      transform(string.begin(), string.end(), string.begin(), toupper);
    }

    void InPlace::ltrim(std::string& string) {
      string.erase(string.begin(), std::find_if(string.begin(), string.end(), [](int c) { return !std::isspace(c); }));
    }

    void InPlace::ltrim(std::string& string, int ch) {
      string.erase(string.begin(), std::find_if(string.begin(), string.end(), [ch](int c) { return ch != c; }));
    }

    void InPlace::rtrim(std::string& string) {
      string.erase(std::find_if(string.rbegin(), string.rend(), [](int ch) { return !std::isspace(ch); }).base(), string.end());
    }

    void InPlace::rtrim(std::string& string, int ch) {
      string.erase(std::find_if(string.rbegin(), string.rend(), [ch](int c) { return ch != c; }).base(), string.end());
    }

    void InPlace::trim(std::string& string) {
      InPlace::ltrim(string);
      InPlace::rtrim(string);
    }

    void InPlace::trim(std::string& string, int ch) {
      InPlace::ltrim(string, ch);
      InPlace::rtrim(string, ch);
    }

    void InPlace::replaceAll(std::string& string, const std::string& sFind, const std::string& sReplace) {
      std::string::size_type n = 0;
      while((n = string.find(sFind, n)) != std::string::npos) {
        string.replace(n, sFind.size(), sReplace);
        n += sReplace.size();
      }
    }

  } // namespace StringUtils
} // namespace Commons
} // namespace AbsCoDes
