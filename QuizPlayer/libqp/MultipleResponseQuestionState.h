#pragma once
#include "QuestionState.h"
#include "MultipleResponseQuestion_fwd.h"
#include "QuestionReview_fwd.h"

namespace qp
{

class CMultipleResponseQuestionState :
	public qp::CQuestionState
{
public:
	CMultipleResponseQuestionState(CConstMultipleResponseQuestionPtr const& question);
	~CMultipleResponseQuestionState();

	bool ChoiceIsSelected(size_t index) const;
	void ChangeResponse(size_t index, bool selected);
	void SelectResponse(size_t index) { ChangeResponse(index, true); };
	void UnselectResponse(size_t index) { ChangeResponse(index, false); };

	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
	std::vector<bool> m_responses;
	CConstMultipleResponseQuestionPtr const m_question;
};
}
