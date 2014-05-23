// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#pragma warning (disable: 4996)

#include <stdio.h>
#include <tchar.h>

#include <boost/optional.hpp>
#include <boost/noncopyable.hpp>
#pragma warning (push)
#pragma warning (disable:4512 4913 4100 4702)
#include <boost/signals2.hpp>
#pragma warning (pop)
#include <sstream>
#include <vector>

#include <loki/Visitor.h> // Unzip loki-0.1.7.zip to SDK and setup include files of Visual studio to {sdk}/{lokidir}/include


#define BOOST_TEST_MODULE LibQPTestModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702 4913)	// отключаем предупреждение компилятора Visual Studio об unreachable code
#include <boost/test/unit_test.hpp>
