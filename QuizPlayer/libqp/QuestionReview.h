#pragma once

#include "QuestionReview_fwd.h"


namespace qp
{

class CQuestionReview
{
public:
	CQuestionReview(double awardedScore = 0.0, bool isCorrect = false);
	bool AnswerIsCorrect()const;
	double GetAwardedScore()const;

	virtual ~CQuestionReview();
private:
	double m_awardedScore;
	bool m_isCorrect;
};

}