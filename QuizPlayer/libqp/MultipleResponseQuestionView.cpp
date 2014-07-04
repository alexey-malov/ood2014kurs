#include "stdafx.h"
#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionState.h"

using namespace std;
using boost::format;

namespace qp
{

CMultipleResponseQuestionView::CMultipleResponseQuestionView(const IMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}


CMultipleResponseQuestionView::~CMultipleResponseQuestionView()
{
}

std::string GetResponseBullet(unsigned char offset)
{
	return string(1, 'A' + offset);
}

void CMultipleResponseQuestionView::ShowDetails()
{
	auto question = m_questionState->GetConcreteQuestion();
	auto & outputStream = GetOutputStream();
	auto const & choices = question->GetChoices();
	for (unsigned char idx = 0; idx < choices.GetChoiceCount(); ++idx)
	{
		outputStream 
			<< (m_questionState->Submitted() ? (choices.GetChoice(idx).isCorrect == m_questionState->ResponseIsSelected(idx) ? "+ " : "- ") : "")
			<< (m_questionState->ResponseIsSelected(idx) ? "[V] " : "[ ] ")
			<< GetResponseBullet(idx) 
			<< ". " 
			<< choices.GetChoice(idx).text 
			<< endl;
	}
}

void CMultipleResponseQuestionView::ShowPrompt()
{
	auto & outputStream = GetOutputStream();
	const auto numChoices = m_questionState->GetConcreteQuestion()->GetChoices().GetChoiceCount();
	if (m_questionState->Submitted())
	{
		outputStream << "Press Enter to go to the next question";
	}
	else
	{
		outputStream << format("Toggle an answer (%1%-%2%) or type 'submit' or 'skip': ") % GetResponseBullet(0) % GetResponseBullet(boost::numeric_cast<unsigned char>(numChoices - 1));
	}
}

bool CMultipleResponseQuestionView::ProcessString(std::string const& inputString)
{
	if (!CQuestionView::ProcessString(inputString))
	{
		const auto numChoices = m_questionState->GetConcreteQuestion()->GetChoices().GetChoiceCount();
		if (inputString.size() == 1 && inputString >= GetResponseBullet(0) && inputString <= GetResponseBullet(boost::numeric_cast<unsigned char>(numChoices - 1)))
		{
			m_onChoiceSelected((size_t)(inputString[0] - GetResponseBullet(0)[0]));
		}
		else
		{
			return false;
		}
	}
	return true;
}

qp::Connection CMultipleResponseQuestionView::DoOnChoiceSelected(const OnChoiceSelectedSlotType & choiceSelectedHandler)
{
	return m_onChoiceSelected.connect(choiceSelectedHandler);
}

}