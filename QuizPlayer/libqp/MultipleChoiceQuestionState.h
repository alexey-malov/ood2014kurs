#pragma once
#include "QuestionState.h"
#include "MultipleChoiceQuestion_fwd.h"

namespace qp
{

class CMultipleChoiceQuestionState :
	public qp::CQuestionState
{
public:
	CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question);
	~CMultipleChoiceQuestionState();
};
}
