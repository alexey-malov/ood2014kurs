#pragma once

#include "QuestionState_fwd.h"

namespace qp
{

class CQuestionStates
{
public:
	CQuestionStates();
	virtual ~CQuestionStates();

	size_t GetCount()const;
	void AddQuestionState(CQuestionStatePtr questionState);
	CQuestionStatePtr GetQuestionStateAtIndex(size_t index)const;

private:
	std::vector<CQuestionStatePtr> m_questionStates;
};

}