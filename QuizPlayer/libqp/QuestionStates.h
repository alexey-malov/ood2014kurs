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
	void AddQuestionState(IQuestionStatePtr const& questionState);
	IQuestionStatePtr GetQuestionStateAtIndex(size_t index)const;

private:
	std::vector<IQuestionStatePtr> m_questionStates;
};

}