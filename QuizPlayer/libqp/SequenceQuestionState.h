#pragma once
#include "QuestionState.h"
#include "SequenceQuestionState_fwd.h"
#include "QuestionReview.h"
#include "types.h"

namespace qp
{

class CSequenceQuestionState : CQuestionState
{
public:
	CSequenceQuestionState(CSequenceQuestionPtr const& question);
	~CSequenceQuestionState();

	void SetAnswer(std::vector<std::string> sequence);
	const std::vector<std::string> & GetAnswer()const;

	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::unique_ptr<CQuestionReview> m_review;
	CConstSequenceQuestionPtr m_question;
	std::vector<std::string>  m_shuffledSequence;
	std::vector<std::string>  m_answer;
};

}