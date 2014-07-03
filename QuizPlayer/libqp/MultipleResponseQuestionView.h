#pragma once
#include "QuestionView.h"
#include "MultipleResponseQuestionView_fwd.h"
#include "MultipleResponseQuestionState_fwd.h"

namespace qp
{

class CMultipleResponseQuestionView : public CQuestionView
{
public:
	CMultipleResponseQuestionView(const IMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CMultipleResponseQuestionView();

	typedef boost::signals2::signal<void(size_t answerIndex)> OnChoiceSelected;
	typedef OnChoiceSelected::slot_type OnChoiceSelectedSlotType;
	virtual Connection DoOnChoiceSelected(const OnChoiceSelectedSlotType & choiceSelectedHandler);

	virtual void ShowDetails() override final;
	virtual void ShowPrompt() override final;
	virtual bool ProcessString(std::string const& inputString) override final;

private:
	const IMultipleResponseQuestionStatePtr m_questionState;
	OnChoiceSelected m_onChoiceSelected;
};

}