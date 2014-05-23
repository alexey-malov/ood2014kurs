#pragma once
#include "QuestionState.h"

namespace qp
{

template <typename QuestionType>
class CQuestionStateWithCustomQuestion : public CQuestionState
{
public:
	typedef std::shared_ptr<QuestionType const> ConstQuestionTypePtr;
	CQuestionStateWithCustomQuestion(ConstQuestionTypePtr const& question)
		:CQuestionState(question)
		, m_question(question)
	{
	}
	
	ConstQuestionTypePtr GetConcreteQuestion()const
	{
		return m_question;
	}
private:
	const ConstQuestionTypePtr m_question;
};

}