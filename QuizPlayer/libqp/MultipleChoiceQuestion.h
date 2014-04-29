#pragma once

#include "QuestionWithChoices.h"
#include "GradedChoice.h"
#include "MultipleChoiceQuestion_fwd.h"

namespace qp
{

class CMultipleChoiceQuestion : public CQuestionWithChoices
{
public:
	CMultipleChoiceQuestion(std::string const &description, double score = 0.0, const CGradedChoices & choices = CGradedChoices());
	virtual ~CMultipleChoiceQuestion();
};

}