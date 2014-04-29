#pragma once

#include "Question.h"
#include "GradedChoice.h" // TODO: есть смысл объединить?

namespace qp
{

class CGradedChoices
{
public:
	CGradedChoices(const std::initializer_list<GradedChoice> & choices = {});
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
	CQuestionWithChoices(std::string const &description, double score = 0.0, const CGradedChoices & choices = CGradedChoices());
	virtual ~CQuestionWithChoices();
	CGradedChoices const& GetChoices()const;
	void SetChoices(CGradedChoices const& choices);
private:
	CGradedChoices m_choices;
};

}