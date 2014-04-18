#pragma once

#include "Question_fwd.h"

namespace qp
{

class CQuestions : boost::noncopyable
{
public:
	CQuestions();
	CQuestions(CQuestions && questions);
	CQuestions& operator=(CQuestions && questions);

	size_t GetCount()const;
	void AddQuestion(CQuestionPtr question);
	CConstQuestionPtr GetQuestionAtIndex(size_t index)const;
};

}