#include "stdafx.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestion.h"
#include "QuestionReview.h"

namespace qp
{

using namespace std;


CTypeInQuestionState::CTypeInQuestionState(CTypeInQuestionPtr const& question)
	:CQuestionState(question)
{
}

CTypeInQuestionState::~CTypeInQuestionState()
{
}

void CTypeInQuestionState::SetUserAnswer(string answer) 
{
	m_answer = answer;
}

string CTypeInQuestionState::GetUserAnswer()const 
{
	return m_answer;
}

void CTypeInQuestionState::DoSubmit()
{
	
}


}

