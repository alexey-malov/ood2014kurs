#pragma once

namespace qp
{

class CQuestion
{
public:
	CQuestion(std::string description);
	virtual ~CQuestion();
	std::string const& GetDescription()const;
	std::string const& GetCorrectFeedback()const;
	std::string const& GetIncorrectFeedback()const;
	double const& GetScore()const;
	
	std::string VerifyIfNotEmpty(std::string param);

private:
	double m_score;
	std::string m_description;
	std::string m_correctFeedback;
	std::string m_incorrectFeedback;
};

}