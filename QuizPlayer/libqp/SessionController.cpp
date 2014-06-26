#include "stdafx.h"
#include "SessionController.h"
#include "QuizSession.h"

namespace qp
{
CSessionController::CSessionController(CQuizSessionPtr const& session)
:m_session(session)
{
}

CSessionController::~CSessionController()
{
}

void CSessionController::Run()
{

}

}