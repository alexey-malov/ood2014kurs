#pragma once
#include "QuestionView.h"
#include "TypeInQuestionState_fwd.h"

namespace qp
{

class CTypeInQuestionView :	public CQuestionView
{
public:
	CTypeInQuestionView(ITypeInQuestionStatePtr const& questionState, std::ostream & outputStream, std::istream & inputStream);
	~CTypeInQuestionView();

	virtual void ShowDetails() override;
	virtual void ShowPrompt() override final;
	virtual bool ProcessString(std::string const& inputString) override final;

	typedef boost::signals2::signal<void(std::string const& answer)> OnAnswerEntered;
	typedef OnAnswerEntered::slot_type OnAnswerEnteredSlotType;
	virtual Connection DoOnAnswerEntered(const OnAnswerEnteredSlotType & answerEnteredHandler);

private:
	const ITypeInQuestionStatePtr m_questionState;
	OnAnswerEntered m_onAnswerEntered;
};

}