#include "stdafx.h"
#include "MultipleResponseQuestionState.h"
#include "MultipleResponseQuestion.h"
#include "QuestionReview.h"

namespace qp
{

using namespace std;

CMultipleResponseQuestionState::CMultipleResponseQuestionState(CConstMultipleResponseQuestionPtr const& question)
:CQuestionStateWithCustomQuestion(question)
, m_responses(std::vector<bool>(question->GetChoices().GetChoiceCount(), false))
, m_question(question)
{
}

CMultipleResponseQuestionState::~CMultipleResponseQuestionState()
{
}


bool CMultipleResponseQuestionState::ResponseIsSelected(size_t index) const
{
	return m_responses.at(index);
}


void CMultipleResponseQuestionState::ChangeResponse(size_t index, bool selected)
{
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}
	m_responses.at(index) = selected;
}


void CMultipleResponseQuestionState::DoSubmit()
{
	CGradedChoices const choices = m_question->GetChoices();

	bool isCorrect = true;
	for (size_t idx = 0; idx < choices.GetChoiceCount(); ++idx)
	{
		isCorrect &= (choices.GetChoice(idx).isCorrect == m_responses.at(idx));
	}

	m_review = make_unique<CQuestionReview>(isCorrect ? m_question->GetScore() : 0, isCorrect);
}

CQuestionReview const CMultipleResponseQuestionState::GetReview()const
{
	if (!m_review)
	{
		throw logic_error("Multiple response question has not been submitted");
	}
	return *m_review;
}


}
