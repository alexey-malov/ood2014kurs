#pragma once

#include "types.h"
#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "QuestionReview_fwd.h"


namespace qp
{
class IMultipleChoiceQuestionState : public IQuestionState
{
public:
	virtual optional_size_t GetUserAnswerIndex()const = 0;
	virtual void SetUserAnswerIndex(size_t answerIndex) = 0;
	virtual CConstMultipleChoiceQuestionPtr GetConcreteQuestion()const = 0;
	virtual CQuestionReview const GetReview()const = 0;
	virtual ~IMultipleChoiceQuestionState(){}
};
}