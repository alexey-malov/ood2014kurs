#pragma once
#include "QuestionView.h"
#include "TypeInQuestionState_fwd.h"

namespace qp
{

class CTypeInQuestionView :	public CQuestionView
{
public:
	CTypeInQuestionView(CTypeInQuestionStatePtr const& questionState, std::ostream & outputStream);
	~CTypeInQuestionView();

	void ShowDetails() override;

private:
	const CTypeInQuestionStatePtr m_questionState;
};

}