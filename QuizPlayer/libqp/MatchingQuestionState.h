#pragma once
#include "QuestionStateWithCustomQuestion.h"
#include "MatchingQuestion_fwd.h"
#include "QuestionReview.h"
#include "types.h"

namespace qp
{

class CMatchingQuestionState : public CQuestionStateWithCustomQuestion<CMatchingQuestion>
{
public:
	CMatchingQuestionState(CConstMatchingQuestionPtr const& question, bool shuffleAnswers = true);
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
	std::vector<optional_size_t> m_responses;

	std::vector<size_t> m_leftItemIndexes;
	std::vector<size_t> m_rightItemIndexes;
	const size_t maxItemsCount = 26;
};

}