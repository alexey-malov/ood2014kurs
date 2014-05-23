#include "stdafx.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestion.h"
#include "QuestionReview.h"
#include "utils.h"

namespace qp
{

using namespace std;


CTypeInQuestionState::CTypeInQuestionState(CConstTypeInQuestionPtr const& question)
	:CQuestionState(question)
	,m_question(question)
{
}

CTypeInQuestionState::~CTypeInQuestionState()
{
}

void CTypeInQuestionState::SetUserAnswer(string const& answer) 
{
	m_answer = RemoveExtraSpaces(answer);
}

string const& CTypeInQuestionState::GetUserAnswer()const 
{
	return m_answer;
}

void CTypeInQuestionState::DoSubmit()
{
	if (!m_answer.empty())
	{
		std::set<std::string> const& answers = m_question->GetAnswers();
		std::set<std::string>::iterator it;
		it = answers.find(m_answer);
		if (it != answers.end())
		{
			m_review = make_unique<CQuestionReview>(m_question->GetScore(), true);
			return;
		}
	}
	m_review = make_unique<CQuestionReview>();
}
CQuestionReview const CTypeInQuestionState::GetReview()const
{
	if (!m_review)
	{
		throw logic_error("TypeIn question has not been submitted");
	}
	return *m_review;
}

}

