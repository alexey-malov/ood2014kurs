#include "stdafx.h"
#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionState.h"

using namespace std;

namespace qp
{

CMultipleResponseQuestionView::CMultipleResponseQuestionView(const CMultipleResponseQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
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
	// TODO: fix me
	CMultipleResponseQuestion const *question = static_cast<CMultipleResponseQuestion const *>(m_questionState->GetQuestion().get());
	auto & outputStream = GetOutputStream();
	auto const & choices = question->GetChoices();
	//outputStream << question->GetDescription() << endl;
	for (unsigned char idx = 0; idx < choices.GetChoiceCount(); ++idx)
	{
		outputStream << GetResponseBullet(idx) << ". " << choices.GetChoice(idx).text << endl;
	}
}

}