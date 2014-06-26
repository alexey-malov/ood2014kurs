#pragma once
#include "QuizSession_fwd.h"
namespace qp
{ 
class CSessionController : public boost::noncopyable
{
public:
	CSessionController(CQuizSessionPtr const& session);
	~CSessionController();

	void Run();
private:
	CQuizSessionPtr m_session;
};

}