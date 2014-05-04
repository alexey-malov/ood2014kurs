#pragma once
#include "QuestionView.h"
#include "MultipleResponseQuestionState_fwd.h"

namespace qp
{

	class CMultipleResponseQuestionView : public CQuestionView
	{
	public:
		CMultipleResponseQuestionView(const CMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream);
		~CMultipleResponseQuestionView();

		void ShowDetails() override;

	private:
		CMultipleResponseQuestionStatePtr m_questionState;
	};

}