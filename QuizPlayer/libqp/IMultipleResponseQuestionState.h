#pragma once

#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "MultipleResponseQuestion_fwd.h"


namespace qp
{

class IMultipleResponseQuestionState : public IQuestionState
{
public:
	LOKI_DEFINE_VISITABLE()

	virtual CConstMultipleResponseQuestionPtr GetConcreteQuestion()const = 0;
	virtual bool ResponseIsSelected(size_t index) const = 0;
	virtual ~IMultipleResponseQuestionState(){}
};

}
