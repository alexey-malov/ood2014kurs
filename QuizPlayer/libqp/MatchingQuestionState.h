#pragma once
#include "QuestionState.h"
#include "MatchingQuestion_fwd.h"
#include "QuestionReview.h"
#include "types.h"

namespace qp
{

class CMatchingQuestionState : public CQuestionState
{
public:
	CMatchingQuestionState(CConstMatchingQuestionPtr & question);
	~CMatchingQuestionState();
	void SelectResponse(size_t leftItem, size_t rightItem);
	void UnselectResponse(size_t leftItem);
	CQuestionReview const GetReview()const;

	std::vector<size_t> const& GetLeftIndexes()const;
	std::vector<size_t> const& GetRightIndexes()const;
	std::vector<optional_size_t> const& GetResponses()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
	CConstMatchingQuestionPtr m_question;
	std::vector<optional_size_t> m_responses;

	std::vector<size_t> m_leftItemIndexes;
	std::vector<size_t> m_rightItemIndexes;
};

}