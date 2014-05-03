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

	bool GetUserResponse(size_t answerIndex) const;
	void ChangeUserResponse(size_t answerIndex, bool state);
	void SetUserResponse(size_t answerIndex) { ChangeUserResponse(answerIndex, true); };
	void ResetUserResponse(size_t answerIndex) { ChangeUserResponse(answerIndex, false); };

	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
	std::vector<bool> m_responses;
};
}
