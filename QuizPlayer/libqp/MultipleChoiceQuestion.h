#pragma once

#include "QuestionWithChoices.h"
#include "GradedChoice.h"

namespace qp
{

class CMultipleChoiceQuestion : public CQuestionWithChoices
{
public:
	CMultipleChoiceQuestion(std::string const &description, double score = 0.0);
	virtual ~CMultipleChoiceQuestion();
};

}