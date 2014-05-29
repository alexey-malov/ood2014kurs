#pragma once

#include "IQuestionStateFactory.h"
#include "Question_fwd.h"
#include "QuestionState_fwd.h"

namespace qp
{

class CQuestionStateFactory : public IQuestionStateFactory
{
public:
	std::unique_ptr<IQuestionState> CreateStateForQuestion(CConstQuestionPtr const& question)const override;

private:
	struct QuestionStateCreationVisitor;
};

}