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
	auto & outputStream = GetOutputStream();
	CGradedChoices const& choices = m_questionState->GetConcreteQuestion()->GetChoices();
	const auto numChoices = choices.GetChoiceCount();
	for (unsigned char idx = 0; idx < numChoices; ++idx)
	{
		string radioVal = (m_questionState->GetUserAnswerIndex() == (size_t)idx) ? "o" : " ";
		outputStream << "(" << radioVal << ") ";
		outputStream << GetResponseBullet(idx) << ". " << choices.GetChoice(idx).text << endl;
	}
}

void CMultipleChoiceQuestionView::ShowPrompt()
{
	auto & outputStream = GetOutputStream();
	const auto numChoices = m_questionState->GetConcreteQuestion()->GetChoices().GetChoiceCount();
	outputStream << format("Choose an answer (%1%-%2%) or type 'submit': ") % GetResponseBullet(0) % GetResponseBullet(boost::numeric_cast<unsigned char>(numChoices - 1));
}

bool CMultipleChoiceQuestionView::ProcessString(string const& inputString)
{
	if (!CQuestionView::ProcessString(inputString))
	{
		const auto numChoices = m_questionState->GetConcreteQuestion()->GetChoices().GetChoiceCount();
		if (inputString.size() == 1 && inputString >= GetResponseBullet(0) && inputString <= GetResponseBullet(boost::numeric_cast<unsigned char>(numChoices - 1)))
		{
			m_onAnswerSelected((size_t)(inputString[0] - GetResponseBullet(0)[0]));
		}
		else
		{
			ShowPrompt();
		}
	}
	return true;
}

Connection CMultipleChoiceQuestionView::DoOnAnswerSelected(const OnAnswerSelectedSlotType & answerSelectedHandler)
{
	return m_onAnswerSelected.connect(answerSelectedHandler);
}