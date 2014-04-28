#pragma once

#include "Question.h"
#include "GradedChoice.h" // TODO: ���� ����� ����������?

namespace qp
{

class CGradedChoices
{
public:
	CGradedChoices(void) {};
	~CGradedChoices() {};
	size_t GetChoiceCount()const;
	void AddChoice(std::string const & text, bool isCorrect);
	const GradedChoice GetChoice(size_t index) const;
private:
	std::vector<GradedChoice> m_choices;
};



class CQuestionWithChoices : public CQuestion
{
public:
	CQuestionWithChoices(std::string const &description, double score = 0.0);
	virtual ~CQuestionWithChoices();
	CGradedChoices const& GetChoices()const;
	void SetChoices(CGradedChoices const& choices);
private:
	CGradedChoices m_choices;
};

}