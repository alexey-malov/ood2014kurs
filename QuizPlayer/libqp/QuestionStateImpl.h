#pragma once

#include "utils.h"
#include "QuestionState_fwd.h"
#include "IQuestionState.h"

namespace qp
{
template <typename Base>
class CQuestionStateImpl : public Base
{
public:
	CQuestionStateImpl(CConstQuestionPtr const& question)
	:m_question(Verify(question))
	,m_submitted(false)
	{

	}


	CConstQuestionPtr GetQuestion() const override final
	{
		return m_question;
	}

	// Indicates whether the question has been submitted (user has given an  answer to the question)
	bool Submitted()const override final
	{
		return m_submitted;
	}

	void Submit() override final
	{
		if (m_submitted)
		{
			throw std::logic_error("Question state has been already submitted");
		}
		else
		{
			DoSubmit();
			m_submitted = true;
		}
	}
protected:
	virtual void DoSubmit() = 0;

private:
	CConstQuestionPtr const m_question;
	bool m_submitted;
};
}