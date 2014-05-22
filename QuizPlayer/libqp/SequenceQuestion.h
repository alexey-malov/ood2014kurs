#pragma once
#include "Question.h"
#include "types.h"
#include <loki/Visitor.h>

/*
SequenceQuestion
	������ � ���������� ������������������� �������

SequenceQuestionState
	������ ������� �������
	������/������ ��� ������� ������� (������ ��������)
	�����

SequenceQuestionView
	������/������ ������� ������ SequenceQuestionState (������ ��������)
	����� ������� ��� ������ ����� map () :)

	������:
	������� ������������������ 0, 1, 4, 2, 3
	�������������� � ������ [0] = a, [1] = b, [4] = c, [2] = d, [3] = e

	��������� ������������ �������: �� ������ ���� � ��������� 96 + answers.size()
	 
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