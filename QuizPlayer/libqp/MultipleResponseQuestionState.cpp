#include "stdafx.h"
#include "MultipleResponseQuestionState.h"
#include "MultipleResponseQuestion.h"
#include "QuestionReview.h"

namespace qp
{

using namespace std;

CMultipleResponseQuestionState::CMultipleResponseQuestionState(CConstMultipleResponseQuestionPtr const& question)
:CQuestionState(question)
, m_responses(std::vector<bool>(dynamic_pointer_cast<const CQuestionWithChoices>(question)->GetChoices().GetChoiceCount(), false))
{
}

CMultipleResponseQuestionState::~CMultipleResponseQuestionState()
{
}


bool CMultipleResponseQuestionState::GetUserResponse(size_t answerIndex) const
{
	return m_responses.at(answerIndex);
}


void CMultipleResponseQuestionState::ChangeUserResponse(size_t answerIndex, bool state)
{
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}
	m_responses[answerIndex] = state;
}


void CMultipleResponseQuestionState::DoSubmit()
{
	auto question = dynamic_pointer_cast<const CQuestionWithChoices>(GetQuestion());
	CGradedChoices choices = question->GetChoices();

	bool isCorrect = true;
	for (size_t idx = 0; idx < choices.GetChoiceCount(); ++idx)
	{
		isCorrect &= (choices.GetChoice(idx).isCorrect == m_responses.at(idx));
	}

	if (isCorrect)
	{
		m_review = make_unique<CQuestionReview>(question->GetScore(), true);
	}
	else
	{
		m_review = make_unique<CQuestionReview>();
	}
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
