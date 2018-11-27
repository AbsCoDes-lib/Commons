//===--- Commons.h ----------------------------------------------------------------------------------*- C++ -*-===//
//
// This source file is part of the Absolute Codes Design open source projects
//
// Copyright (c) 2016 - 2019 Absolute Codes Design and the project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://raw.githubusercontent.com/AbsCoDes/AbsCoDes.github.io/master/Licence.txt for license information
//
//===-------------------------------------------------------------------------------------------------------------===//


#ifndef Commons_INCLUDED
#define Commons_INCLUDED

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000


//
// By default this library is intended to be used as a DLL
// To use it as a static library add COMMONS_STATIC to your preprocessor list
//


//
// Ensure that Visual Studio is used
//
#if !defined(_MSC_VER)
#  error "This set of tools only works with Visual Studio"
#endif


// Ensure that we build with the multithreaded
// versions of the runtime libraries
#if defined(_MSC_VER) && !defined(_MT)
#  error Must compile with /MD, /MDd, /MT or /MTd
#endif


//
// Ensure that COMMONS_DLL is default unless COMMONS_STATIC is defined
//
#if defined(_WIN32) && defined(_DLL)
#  if !defined(COMMONS_DLL) && !defined(COMMONS_STATIC)
#    define COMMONS_DLL
#  endif
#endif


//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the COMMONS_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// Commons_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(COMMONS_DLL)
#  ifdef COMMONS_EXPORTS
#    define Commons_API __declspec(dllexport)
#  else
#    define Commons_API __declspec(dllimport)
#  endif
#endif


#if !defined(Commons_API)
#  define Commons_API
#endif


//
// Automatically link Commons library.
//
#if defined(_MSC_VER)
#  if defined _WIN64
#    define X64_SUFFIX "_x64"
#  else
#    define X64_SUFFIX ""
#  endif

#  if defined(COMMONS_DLL)
#    if defined(_DEBUG)
#      define COMMONS_LIB_SUFFIX X64_SUFFIX "_d"
#    else
#      define COMMONS_LIB_SUFFIX X64_SUFFIX ""
#    endif
#  elif defined(_DLL)
#    if defined(_DEBUG)
#      define COMMONS_LIB_SUFFIX X64_SUFFIX "_mdd"
#    else
#      define COMMONS_LIB_SUFFIX X64_SUFFIX "_md"
#    endif
#  else
#    if defined(_DEBUG)
#      define COMMONS_LIB_SUFFIX X64_SUFFIX "_mtd"
#    else
#      define COMMONS_LIB_SUFFIX X64_SUFFIX "_mt"
#    endif
#  endif

#  if !defined(COMMONS_NO_AUTOLIB) && !defined(COMMONS_EXPORTS)
#    pragma comment(lib, "Commons" COMMONS_LIB_SUFFIX ".lib")
#    pragma message("Automatically linking with Commons" COMMONS_LIB_SUFFIX ".lib")
#  endif
#endif


// Reduce bloat
#if defined(_WIN32) && !defined(WIN32_LEAN_AND_MEAN)
#  define WIN32_LEAN_AND_MEAN
#endif


// Last Windows platform
#include <SDKDDKVer.h>

//
#include <Windows.h> // Windows Platform SDK
#include <crtdbg.h> // _ASSERTE()

//
#include <string>


#endif // Commons_INCLUDED
