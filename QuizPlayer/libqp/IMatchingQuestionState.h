#pragma once

#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "MatchingQuestion_fwd.h"

namespace qp
{

class IMatchingQuestionState : public IQuestionState
{
public:
	LOKI_DEFINE_VISITABLE()

	virtual CConstMatchingQuestionPtr GetConcreteQuestion()const = 0;
	virtual std::vector<size_t> const& GetLeftIndexes()const = 0;
	virtual std::vector<size_t> const& GetRightIndexes()const = 0;

	virtual ~IMatchingQuestionState(){}
};

}