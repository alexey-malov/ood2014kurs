#include "stdafx.h"
#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MatchingQuestionView.h"

using namespace qp;
using namespace std;

CMatchingQuestionView::CMatchingQuestionView(const CMatchingQuestionStatePtr & questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}

CMatchingQuestionView::~CMatchingQuestionView()
{
}

void CMatchingQuestionView::ShowDetails()
{
	auto & outputStream = GetOutputStream();
	
	CConstMatchingQuestionPtr question = m_questionState->GetQuestion();
	auto const& leftItems = question->GetLeftMatchingItems();
	auto const& rightItems = question->GetRightMatchingItems();
	
	auto const& leftIndexes = m_questionState->GetLeftIndexes();
	auto const& rightIndexes = m_questionState->GetRightIndexes();

	size_t leftColumnLength = max_element(leftItems.begin(), leftItems.end(), [](string const& it1, string const& it2){ return it1.size() < it2.size(); })->size() + 5;
	unsigned char indent = (leftItems.size() < 10) ? 3 : 4;
	
	for (unsigned char i = 0; i < rightItems.size(); ++i)
	{
		if (i < leftItems.size()) //print left item
		{
			outputStream << i + 1 << ". " << leftItems[leftIndexes[i]] << string(leftColumnLength - leftItems[leftIndexes[i]].size(), ' ');
		}
		else
		{
			outputStream << string(leftColumnLength + indent, ' ');
		}
		outputStream << string(1, 'A' + i) << ". " << rightItems[rightIndexes[i]] << endl;
	}
}
