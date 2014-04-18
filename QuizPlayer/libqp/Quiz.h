#pragma once

#include "Questions.h"

namespace qp
{

class CQuiz
{
public:
	CQuiz(std::string title = std::string());

	std::string const& GetTitle()const;

	const CQuestions & GetQuestions()const;

	void SetQuestions(const CQuestions & questions);

	~CQuiz(void);
private:
	std::string m_title;
	CQuestions m_questions;
};

}