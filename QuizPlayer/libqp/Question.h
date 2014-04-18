#pragma once

#include "types.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestion
{
public:
	CQuestion(std::string description);
	virtual ~CQuestion();

	const std::string & GetDescription()const;

	const optional_string & GetCorrectFeedback()const;
	void SetCorrectFeedback(std::string text);

	const optional_string & GetIncorrectFeedback()const;
	void SetIncorrectFeedback(std::string text);

	double GetScore()const;
private:
	double m_score;
	std::string m_description;

	optional_string m_correctFeedback;
	optional_string m_incorrectFeedback;
};

}