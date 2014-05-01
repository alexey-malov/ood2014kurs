#pragma once
#include "QuestionState.h"
#include "MultipleChoiceQuestion_fwd.h"
#include "QuestionReview_fwd.h"
#include "MultipleChoiceQuestion_fwd.h"

namespace qp
{



class CMultipleChoiceQuestionState :
	public qp::CQuestionState
{
public:
	CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question);
	~CMultipleChoiceQuestionState();

	void SetUserAnswerIndex(size_t answerIndex);
	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
};
}
