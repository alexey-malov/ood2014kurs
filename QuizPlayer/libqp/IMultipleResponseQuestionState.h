#pragma once

#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "MultipleResponseQuestion_fwd.h"


namespace qp
{

class IMultipleResponseQuestionState : public IQuestionState
{
public:
	virtual CConstMultipleResponseQuestionPtr GetConcreteQuestion()const = 0;
	virtual ~IMultipleResponseQuestionState(){}
};

}
