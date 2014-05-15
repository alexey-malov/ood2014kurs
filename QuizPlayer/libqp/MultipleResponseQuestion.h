#pragma once

#include "QuestionWithChoices.h"
#include "GradedChoice.h"

namespace qp
{

class CMultipleResponseQuestion : public CQuestionWithChoices
{
public:
	LOKI_DEFINE_CONST_VISITABLE()
	CMultipleResponseQuestion(std::string const &description, double score = 0.0, const CGradedChoices & choices = CGradedChoices());
	virtual ~CMultipleResponseQuestion();
};

}