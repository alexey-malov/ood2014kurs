#pragma once

#include "Question_fwd.h"
#include "QuestionState_fwd.h"

namespace qp
{

class IQuestionStateFactory : boost::noncopyable
{
public:
	virtual std::unique_ptr<IQuestionState> CreateStateForQuestion(CConstQuestionPtr const& question)const = 0;

	virtual ~IQuestionStateFactory(){};
};

}