#pragma once
#include "QuestionState.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "QuestionReview_fwd.h"
#include "types.h"

namespace qp
{

class CMultipleChoiceQuestionState : public qp::CQuestionState
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
	CConstMultipleChoiceQuestionPtr m_question;
};

}
