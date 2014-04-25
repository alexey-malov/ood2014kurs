#pragma once

#include "Question.h"
#include "GradedChoice.h"

namespace qp
{

class CMultipleChoiceQuestion : public CQuestion
{
public:
	CMultipleChoiceQuestion(std::string const &description, double score = 0.0);
	virtual ~CMultipleChoiceQuestion();
	size_t GetAnswersCount()const;
	void AddChoice(std::string const & answer, bool isCorrect);
	const GradedChoice GetChoice(size_t index) const;
private:
	std::vector<GradedChoice> m_choices;
};

}