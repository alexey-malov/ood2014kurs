#include "stdafx.h"
#include "QuestionView.h"
#include "QuestionState.h"
#include "Question.h"

namespace qp
{

using namespace std;

CQuestionView::CQuestionView(const IQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
:m_questionState(questionState)
,m_outputStream(outputStream)
,m_inputStream(inputStream)
{
}


CQuestionView::~CQuestionView()
{
}

void CQuestionView::Show()
{
	ShowDescription();
	ShowDetails();
}

void CQuestionView::HandleUserInput()
{
	string inputString;
	getline(m_inputStream, inputString);
	ProcessString(inputString);
}

void CQuestionView::ProcessString(std::string const& inputString)
{
	if (inputString == "submit")
	{
		m_onSubmit();
	}
	else if (inputString == "skip")
	{
		m_onSkip();
	}
	else if (static_pointer_cast<CQuestionState>(m_questionState)->Submitted() && inputString == "")
	{
		m_onNextQuestion();
	}
}

void CQuestionView::ShowDescription() const
{
	m_outputStream << GetQuestion().GetDescription() << endl;
}

const CQuestion & CQuestionView::GetQuestion() const
{
	return *m_questionState->GetQuestion();
}

Connection CQuestionView::DoOnSubmit(const OnSubmitSlotType & submitHandler)
{
	return m_onSubmit.connect(submitHandler);
}

Connection CQuestionView::DoOnSkip(const OnSkipSlotType & skipHandler)
{
	return m_onSkip.connect(skipHandler);
}

Connection CQuestionView::DoOnNextQuestion(const OnNextQuestionSlotType & nextQuestionHandler)
{
	return m_onNextQuestion.connect(nextQuestionHandler);
}

}