#pragma once
#include "QuestionView.h"
#include "MatchingQuestionState_fwd.h"

namespace qp
{

class CMatchingQuestionView : public CQuestionView
{
public:
	CMatchingQuestionView(const IMatchingQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CMatchingQuestionView();

	virtual void ShowDetails() override;

private:
	const IMatchingQuestionStatePtr m_questionState;
};

}