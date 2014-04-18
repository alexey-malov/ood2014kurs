#pragma once

#include "Questions.h"

namespace qp
{

class CQuiz
{
public:
	CQuiz(const std::string & title);

	std::string const& GetTitle()const;

	const CQuestions & GetQuestions()const;
	CQuestions & GetQuestions();

	~CQuiz(void);
private:
	std::string m_title;
	CQuestions m_questions;
};

}