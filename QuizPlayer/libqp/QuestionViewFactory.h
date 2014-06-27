#pragma once

#include "IQuestionViewFactory.h"
#include "IQuestionView.h"
#include "Question_fwd.h"
#include "QuestionState_fwd.h"

namespace qp
{

class CQuestionViewFactory : public IQuestionViewFactory
{
public:
	std::unique_ptr<IQuestionView> CreateView(CQuestionStatePtr const& questionState)const override;

	~CQuestionViewFactory();
};

}