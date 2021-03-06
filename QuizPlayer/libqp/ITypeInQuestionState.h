#pragma once

#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "TypeInQuestion_fwd.h"
#include "QuestionReview_fwd.h"

namespace qp
{

class ITypeInQuestionState : public IQuestionState
{
public:
	LOKI_DEFINE_VISITABLE()

	virtual void SetUserAnswer(std::string const& answer) = 0;
	virtual std::string const& GetUserAnswer()const = 0;
	virtual CConstTypeInQuestionPtr GetConcreteQuestion()const = 0;
	virtual CQuestionReview const GetReview()const = 0;

	virtual ~ITypeInQuestionState(){}
};

}