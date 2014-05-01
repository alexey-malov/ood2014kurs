#pragma once

#include "QuestionReview_fwd.h"


namespace qp
{

class CQuestionReview
{
public:
	CQuestionReview();
	bool AnswerIsCorrect()const;
	double GetAwardedScore()const;

	virtual ~CQuestionReview();
};

}