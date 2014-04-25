#pragma once

#include "Question.h"

namespace qp
{

class CMultipleChoiceQuestion : public CQuestion
{
public:
	CMultipleChoiceQuestion(std::string const description, double score = 0.0);
	virtual ~CMultipleChoiceQuestion();
		
	void SetRightAnswer(unsigned int answer);

private:
	unsigned int rightAnswer;
	std::vector<std::string> questionAnswers;
};

}