#pragma once

#include "Question_fwd.h"

namespace qp
{
class IQuestionState : public boost::noncopyable
{
public:

	virtual CConstQuestionPtr GetQuestion()const = 0;

	virtual void Submit() = 0;

	virtual bool Submitted()const = 0;

	virtual ~IQuestionState(){}
};
}