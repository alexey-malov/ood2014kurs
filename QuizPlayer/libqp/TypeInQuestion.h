#pragma once
#include "Question.h"

namespace qp
{

class CTypeInQuestion : 
	public CQuestion
{
public:
	CTypeInQuestion(std::string const& description, double score = 0.0);
	~CTypeInQuestion();
	void SetAnswers(std::vector<std::string> const& answers);
	std::vector<std::string> const& GetAnswers() const;
private:
	std::vector<std::string> m_answers;
};

}
