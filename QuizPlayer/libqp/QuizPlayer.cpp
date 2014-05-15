#include "stdafx.h"
#include "QuizPlayer.h"
#include "IQuizView.h"

namespace qp
{

CQuizPlayer::CQuizPlayer(CConstQuizPtr const& quiz, IQuizView & view)
{
	quiz;
	view;
}


CQuizPlayer::~CQuizPlayer(void)
{
}

void CQuizPlayer::Start()
{

}

}