#pragma once

#include "Question.h"

namespace qp
{

	class CMultipleChoiceQuestion : public CQuestion
	{
	public:
		CMultipleChoiceQuestion(std::string description, double score = 0.0);
		virtual ~CMultipleChoiceQuestion();
		

	private:
		
	};

}