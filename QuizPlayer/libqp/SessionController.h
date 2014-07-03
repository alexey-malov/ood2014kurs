#pragma once
#include "QuizSession_fwd.h"
#include "QuestionState_fwd.h"
#include "MultipleChoiceQuestionViewController_fwd.h"

namespace qp
{ 
class CSessionController : public boost::noncopyable
{
public:
	CSessionController(CQuizSessionPtr const& session);
	~CSessionController();

	void Run();
private:
	CMultipleChoiceQuestionViewControllerPtr CreateMultipleChoiceQuestionViewController(IQuestionStatePtr state);
	CQuizSessionPtr m_session;
};

}