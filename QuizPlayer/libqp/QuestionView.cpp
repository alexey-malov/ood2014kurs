#include "stdafx.h"
#include "QuestionView.h"
#include "QuestionState.h"
#include "Question.h"

namespace qp
{

using namespace std;

CQuestionView::CQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
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
		m_submitRequestedSignal();
	}
	else if (inputString == "skip")
	{
		m_skipRequestedSignal();
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

CQuestionView::SubmitRequestedSignal & CQuestionView::SubmitRequested()
{
	return m_submitRequestedSignal;
}

CQuestionView::SkipRequestedSignal & CQuestionView::SkipRequested()
{
	return m_skipRequestedSignal;
}

}