#pragma once
#include "Question.h"
#include "types.h"
#include <loki/Visitor.h>

/*
SequenceQuestion
	вектор с правильной последовательностью ответов

SequenceQuestionState
	хранит текущую выборку
	геттер/сеттер для текущей выборки (вектор индексов)
	ревью

SequenceQuestionView
	геттер/сеттер обертка вокруг SequenceQuestionState (вектор символов)
	думаю сделать это лениво через map () :)

	пример:
	получаю последовательность 0, 1, 4, 2, 3
	конвертируется в вектор [0] = a, [1] = b, [4] = c, [2] = d, [3] = e

	проверять корректность символа: он должен быть в диапазоне 96 + answers.size()
	 
*/

namespace qp
{

class CSequenceQuestion : public CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE();

	typedef std::vector<std::string> MatchedItems;

	CSequenceQuestion(const std::string & description, double score = 0.0, const MatchedItems & matchedItems = MatchedItems());

	const MatchedItems & GetMatchedItems()const;
	size_t GetMatchedItemsCount()const;

private:
	MatchedItems m_matchedItems;
};

}