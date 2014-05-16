#pragma once
#include "QuestionState.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "QuestionReview_fwd.h"
#include "types.h"

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

	ConstQuestionTypePtr GetQuestion()const
	{
		return m_question;
	}
private:
	const ConstQuestionTypePtr m_question;
};

class CMultipleChoiceQuestionState : public CQuestionStateWithCustomQuestion<CMultipleChoiceQuestion>
{
public:
	CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question);
	~CMultipleChoiceQuestionState();

	void SetUserAnswerIndex(size_t answerIndex);
	optional_size_t GetUserAnswerIndex()const;
	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
	optional_size_t m_answerIndex;
};

}
