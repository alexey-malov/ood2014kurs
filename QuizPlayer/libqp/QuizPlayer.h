#pragma once

#include "Quiz_fwd.h"

namespace qp
{

class IQuizView;

class CQuizPlayer : boost::noncopyable
{
public:
	CQuizPlayer(CConstQuizPtr const& quiz, IQuizView & view);

	// Запуск теста
	void Start();
	~CQuizPlayer(void);
private:
};

}
