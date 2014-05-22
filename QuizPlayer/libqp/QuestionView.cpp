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

void CQuestionView::ShowDescription() const
{
	m_outputStream << GetQuestion().GetDescription() << endl;
}

const CQuestion & CQuestionView::GetQuestion() const
{
	return *m_questionState->GetQuestion();
}

}