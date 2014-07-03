#pragma once
#include "QuestionView.h"
#include "MultipleResponseQuestionState_fwd.h"

namespace qp
{

	class CMultipleResponseQuestionView : public CQuestionView
	{
	public:
		CMultipleResponseQuestionView(const IMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
		~CMultipleResponseQuestionView();

		void ShowDetails() override;

	private:
		const IMultipleResponseQuestionStatePtr m_questionState;
	};

}