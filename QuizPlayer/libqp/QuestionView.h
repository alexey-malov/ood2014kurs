#pragma once
#include "IQuestionView.h"

#include "QuestionState_fwd.h"
#include "Question_fwd.h"

namespace qp
{

class CQuestionView : public IQuestionView
{
public:
	CQuestionView(const CQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream);
	~CQuestionView();

	virtual void Show() override final;
protected:
	virtual void ShowDetails() = 0;
	std::ostream & GetOutputStream() { return m_outputStream; };
private:
	void ShowDescription()const;
	const CQuestion & GetQuestion()const;
private:
	std::ostream & m_outputStream;
	std::istream & m_inputStream;
	CQuestionStatePtr m_questionState;
};

}