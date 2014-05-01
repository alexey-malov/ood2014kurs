// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <boost/optional.hpp>
#include <boost/noncopyable.hpp>
#include <sstream>

#define BOOST_TEST_MODULE LibQPTestModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)	// отключаем предупреждение компилятора Visual Studio об unreachable code
#include <boost/test/unit_test.hpp>
