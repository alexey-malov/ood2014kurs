#include "stdafx.h"
#include "QuestionView.h"
#include "Question.h"
#include "IQuestionState.h"

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

bool CQuestionView::HandleUserInput()
{
	ShowPrompt();
	string inputString;
	getline(m_inputStream, inputString);
	return ProcessString(inputString);
}

bool CQuestionView::ProcessString(std::string const& inputString)
{
	bool stringProcessed = true;
	if (inputString == "submit")
	{
		m_onSubmit();
	}
	else if (inputString == "skip" || (m_questionState->Submitted() && inputString == ""))
	{
		m_onSkip();
	}
	else if (inputString == "exit")
	{
		m_onExit();
	}
	else
	{
		stringProcessed = false;
	}
	return stringProcessed;
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

Connection CQuestionView::DoOnExit(const OnExitSlotType & exitHandler)
{
	return m_onExit.connect(exitHandler);
}

}