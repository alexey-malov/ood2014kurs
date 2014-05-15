#pragma once

#include "stdafx.h"
#include "Question.h"

namespace qp
{

class CTypeInQuestion : 
	public CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE()
	CTypeInQuestion(std::string const& description, std::set<std::string> const& answers, double score = 0.0);
	~CTypeInQuestion();
	std::set<std::string> const& GetAnswers() const;
private:
	std::set<std::string> m_answers;
};

}
