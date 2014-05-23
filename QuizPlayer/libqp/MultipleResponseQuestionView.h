#pragma once
#include "QuestionView.h"
#include "MultipleResponseQuestionState_fwd.h"

namespace qp
{

	class CMultipleResponseQuestionView : public CQuestionView
	{
	public:
		CMultipleResponseQuestionView(const CMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
		~CMultipleResponseQuestionView();

		void ShowDetails() override;

	private:
		const CMultipleResponseQuestionStatePtr m_questionState;
	};

}