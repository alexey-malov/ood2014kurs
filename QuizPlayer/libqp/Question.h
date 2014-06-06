#pragma once

#include "types.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestion 
	: boost::noncopyable
	, public Loki::BaseVisitable<void, Loki::DefaultCatchAll, true>
	, public std::enable_shared_from_this<CQuestion>
{
public:
	CQuestion(std::string const& description, double score = 0.0);
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