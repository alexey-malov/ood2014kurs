#pragma once

#include "IQuestionView.h"
#include "Question_fwd.h"
#include "QuestionState_fwd.h"

namespace qp
{

class IQuestionViewFactory : boost::noncopyable
{
public:
	virtual std::unique_ptr<IQuestionView> CreateView(CQuestionStatePtr const& questionState)const = 0;

	virtual ~IQuestionViewFactory(){};
};

}