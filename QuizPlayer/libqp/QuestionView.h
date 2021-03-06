#pragma once
#include "IQuestionView.h"

#include "QuestionState_fwd.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestionView : public IQuestionView
{
public:
	CQuestionView(const IQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CQuestionView();

	virtual bool HandleUserInput() override final;
	virtual void Show() override final;

	virtual Connection DoOnSubmit(const OnSubmitSlotType & submitHandler) override final;
	virtual Connection DoOnSkip(const OnSkipSlotType & skipHandler) override final;
	virtual Connection DoOnExit(const OnExitSlotType & exitHandler) override final;

protected:
	virtual bool ProcessString(std::string const& inputString);
	virtual void ShowDetails() = 0;
	virtual void ShowPrompt(){};
	virtual void ShowReview(){};
	std::ostream & GetOutputStream() { return m_outputStream; };
private:
	void ShowDescription()const;
	const CQuestion & GetQuestion()const;

	std::ostream & m_outputStream;
	std::istream & m_inputStream;
	IQuestionStatePtr m_questionState;

	// Signals
	OnSubmit m_onSubmit;
	OnSkip m_onSkip;
	OnSkip m_onExit;
};

}