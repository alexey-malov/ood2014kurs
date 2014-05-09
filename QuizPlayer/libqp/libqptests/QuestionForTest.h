#pragma once

#include "Question.h"

class CQuestionForTest : public qp::CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE()
		CQuestionForTest(std::string const& description, double score = 0.0)
		:CQuestion(description, score)
	{}

};