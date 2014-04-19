#pragma once

#include "Question_fwd.h"

namespace qp
{

class CQuestions
{
public:
	CQuestions();

	size_t GetCount()const;
	void AddQuestion(CQuestionPtr question);
	CConstQuestionPtr GetQuestionAtIndex(size_t index)const;

private:
	std::vector<CQuestionPtr> m_questions;
};

}