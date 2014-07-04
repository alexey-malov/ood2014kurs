// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma warning (disable: 4996)

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <boost/optional.hpp>
#include <boost/noncopyable.hpp>
#include <boost/format.hpp>
#include <boost/numeric/conversion/cast.hpp>
#pragma warning (push)
#pragma warning (disable:4512 4913 4100 4702)
#include <boost/signals2.hpp>
#pragma warning (pop)
#include <loki/Visitor.h> // Unzip loki-0.1.7.zip to SDK and setup include files of Visual studio to {sdk}/{lokidir}/include


// TODO: reference additional headers your program requires here
