#pragma once
#include "QuestionView.h"
#include "MultipleChoiceQuestionState_fwd.h"

namespace qp
{

class CMultipleChoiceQuestionView : public CQuestionView
{
public:
	CMultipleChoiceQuestionView(const CMultipleChoiceQuestionStatePtr & questionState, std::ostream & outputStream);
	~CMultipleChoiceQuestionView();

	virtual void ShowDetails() const;

private:
	CMultipleChoiceQuestionStatePtr m_questionState;
};

}