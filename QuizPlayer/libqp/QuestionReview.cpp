#include "stdafx.h"
#include "QuestionReview.h"

namespace qp
{
CQuestionReview::CQuestionReview(double awardedScore, bool isCorrect)
:m_awardedScore(awardedScore)
,m_isCorrect(isCorrect)
{ 
}

CQuestionReview::~CQuestionReview()
{
}

bool CQuestionReview::AnswerIsCorrect()const
{
	return m_isCorrect;
}

double CQuestionReview::GetAwardedScore()const
{
	return m_awardedScore;
}

}