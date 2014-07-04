#include "stdafx.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;

CTypeInQuestionView::CTypeInQuestionView(ITypeInQuestionStatePtr const& questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}


CTypeInQuestionView::~CTypeInQuestionView()
{
}

void CTypeInQuestionView::ShowDetails()
{

}

void CTypeInQuestionView::ShowPrompt()
{
	auto & outputStream = GetOutputStream();
	if (m_questionState->Submitted())
	{
		outputStream << "Press Enter to go to the next question";
	}
	else
	{
		outputStream << "Enter an answer or type 'submit' or 'skip': ";
	}
}



bool CTypeInQuestionView::ProcessString(std::string const& inputString)
{
	if (!CQuestionView::ProcessString(inputString))
	{
		if (inputString == "")
		{
			return false;
		}
		else
		{
			m_onAnswerEntered(inputString);
		}
	}
	return true;
}

Connection CTypeInQuestionView::DoOnAnswerEntered(const OnAnswerEnteredSlotType & answerEnteredHandler)
{
	return m_onAnswerEntered.connect(answerEnteredHandler);
}