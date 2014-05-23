#pragma once
#include "QuestionViewController.h"

#include "MultipleChoiceQuestionState_fwd.h"
#include "MultipleChoiceQuestionView_fwd.h"

namespace qp
{

class CMultipleChoiceQuestionViewController :
	public CQuestionViewController
{
public:
	CMultipleChoiceQuestionViewController(CMultipleChoiceQuestionStatePtr const& questionState, CMultipleChoiceQuestionViewPtr const& view);
	~CMultipleChoiceQuestionViewController();
};

}

