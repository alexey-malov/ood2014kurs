#pragma once
#include "QuestionState_fwd.h"
#include "QuestionStateImpl.h"

namespace qp
{

template <typename QuestionType, typename Base = CQuestionState>
class CQuestionStateWithCustomQuestion : public Base
{
public:
	typedef std::shared_ptr<QuestionType const> ConstQuestionTypePtr;
	CQuestionStateWithCustomQuestion(ConstQuestionTypePtr const& question)
		:Base(question)
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