#pragma once
#include "QuestionView.h"
#include "MultipleResponseQuestionState_fwd.h"

namespace qp
{

	class CMultipleResponseQuestionView : public CQuestionView
	{
	public:
		CMultipleResponseQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream);
		~CMultipleResponseQuestionView();

		void ShowDetails() override;

	private:
		CQuestionStatePtr m_questionState;
	};

}