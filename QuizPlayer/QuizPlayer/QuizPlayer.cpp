// QuizPlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "libqp/Quiz.h"
#include "libqp/QuizPlayer.h"
#include "libqp/QuizView.h"

using namespace qp;
using namespace std;

int _tmain()
{
	std::cout << "Welcome to QuizPlayer\n";
	auto quiz = make_shared<CQuiz>();
	CQuizView view;
	CQuizPlayer qp(quiz, view);
	qp.Start();
	return 0;
}

