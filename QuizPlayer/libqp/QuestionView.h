#pragma once
#include "IQuestionView.h"

#include "QuestionState_fwd.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestionView : public IQuestionView
{
public:
	CQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CQuestionView();

	virtual void HandleUserInput() override final;
	virtual void Show() override final;

	virtual Connection DoOnSubmit(const OnSubmitSlotType & submitHandler) override final;
	virtual Connection DoOnSkip(const OnSkipSlotType & skipHandler) override final;
protected:
	virtual void ProcessString(std::string const& inputString);
	virtual void ShowDetails() = 0;
	std::ostream & GetOutputStream() { return m_outputStream; };
private:
	void ShowDescription()const;
	const CQuestion & GetQuestion()const;
private:
	std::ostream & m_outputStream;
	std::istream & m_inputStream;
	CQuestionStatePtr m_questionState;

	// Signals
	OnSubmit m_onSubmit;
	OnSkip m_onSkip;

};

}