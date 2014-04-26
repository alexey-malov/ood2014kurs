#pragma once

#include "QuestionWithChoices.h"
#include "GradedChoice.h"

namespace qp
{

class CMultipleResponseQuestion : public CQuestionWithChoices
{
public:
	CMultipleResponseQuestion(std::string const &description, double score = 0.0);
	virtual ~CMultipleResponseQuestion();
};

}