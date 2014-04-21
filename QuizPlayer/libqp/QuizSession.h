#pragma once

#include "Quiz_fwd.h"

namespace qp
{

class CQuizSession : boost::noncopyable
{
public:
	CQuizSession(CConstQuizPtr const& quiz);
	~CQuizSession();
};

}