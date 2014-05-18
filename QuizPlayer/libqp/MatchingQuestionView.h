#pragma once
#include "QuestionView.h"
#include "MatchingQuestionState_fwd.h"

namespace qp
{

class CMatchingQuestionView : public CQuestionView
{
public:
	CMatchingQuestionView(const CMatchingQuestionStatePtr & questionState, std::ostream & outputStream);
	~CMatchingQuestionView();

	virtual void ShowDetails() override;

private:
	const CMatchingQuestionStatePtr m_questionState;
};

}