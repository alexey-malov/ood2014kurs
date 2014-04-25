#pragma once

#include "QuestionState_fwd.h"

namespace qp
{

class CQuestionStates : public boost::noncopyable
{
public:
	CQuestionStates();
	virtual ~CQuestionStates();

	size_t GetCount()const;
	void AddQuestionState(CQuestionStatePtr questionState);
	CQuestionStatePtr GetQuestionStateAtIndex(size_t index);

private:
	std::vector<CQuestionStatePtr> m_questionStates;
};

}