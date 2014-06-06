#pragma once
#include "QuestionView.h"
#include "MultipleChoiceQuestionState_fwd.h"
#include "MultipleChoiceQuestionView_fwd.h"

namespace qp
{

class CMultipleChoiceQuestionView : public CQuestionView
{
public:
	CMultipleChoiceQuestionView(const CMultipleChoiceQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CMultipleChoiceQuestionView();

	typedef boost::signals2::signal<void(size_t answerIndex)> OnAnswerSelected;
	typedef OnAnswerSelected::slot_type OnAnswerSelectedSlotType;
	virtual Connection DoOnAnswerSelected(const OnAnswerSelectedSlotType & answerSelectedHandler);

	virtual void ShowDetails() override final;
	virtual void ShowPrompt() override final;
	virtual bool ProcessString(std::string const& inputString) override final;

private:
	const CMultipleChoiceQuestionStatePtr m_questionState;
	OnAnswerSelected m_onAnswerSelected;
};

}