#include "stdafx.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"

using namespace qp;
using namespace std;

CMultipleChoiceQuestionView::CMultipleChoiceQuestionView(const CMultipleChoiceQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}

CMultipleChoiceQuestionView::~CMultipleChoiceQuestionView()
{
}

std::string GetResponseBullet(unsigned char offset)
{
	return string(1, 'A' + offset);
}

void CMultipleChoiceQuestionView::ShowDetails()
{
	CConstMultipleChoiceQuestionPtr question = m_questionState->GetQuestion();
	auto & outputStream = GetOutputStream();
	CGradedChoices const& choices = question->GetChoices();
	for (unsigned char idx = 0; idx < choices.GetChoiceCount(); ++idx)
	{
		outputStream << GetResponseBullet(idx) << ". " << choices.GetChoice(idx).text << endl;
	}
}

