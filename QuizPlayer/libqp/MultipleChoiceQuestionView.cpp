#include "stdafx.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionState.h"

using namespace qp;
using namespace std;
using boost::format;

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
	CConstMultipleChoiceQuestionPtr question = m_questionState->GetConcreteQuestion();
	auto & outputStream = GetOutputStream();
	CGradedChoices const& choices = question->GetChoices();
	const auto numChoices = choices.GetChoiceCount();
	for (unsigned char idx = 0; idx < numChoices; ++idx)
	{
		outputStream << GetResponseBullet(idx) << ". " << choices.GetChoice(idx).text << endl;
	}

	outputStream << format("Choose an answer (%1%-%2%) or type 'submit': ") % GetResponseBullet(0) % GetResponseBullet(boost::numeric_cast<unsigned char>(numChoices - 1));
}

