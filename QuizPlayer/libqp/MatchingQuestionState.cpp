#include "stdafx.h"
#include "MatchingQuestionState.h"
#include "MatchingQuestion.h"
#include <random>

using namespace qp;
using namespace std;

void GenerateIndexes(vector<size_t> & arr, size_t size)
{
	arr.resize(size);
	int index(0);
	generate(arr.begin(), arr.end(), [&]{ return ++index; });
	random_device rd;
	mt19937 mt(rd());
	shuffle(arr.begin(), arr.end(), mt);
}

CMatchingQuestionState::CMatchingQuestionState(CConstMatchingQuestionPtr & question)
:CQuestionState(question)
,m_question(question)
,m_responses(question->GetLeftMatchingItemsCount())
{
	GenerateIndexes(m_leftItemIndexes, question->GetLeftMatchingItemsCount());
	GenerateIndexes(m_rightItemIndexes, question->GetRightMatchingItemsCount());
}

CMatchingQuestionState::~CMatchingQuestionState()
{
}

CQuestionReview const CMatchingQuestionState::GetReview()const
{
	if (!m_review)
	{
		throw logic_error("Matching question has not been submitted");
	}
	return *m_review;
}

void CMatchingQuestionState::DoSubmit()
{
	//all left items should have matched items
	if (m_responses.empty() || !all_of(m_responses.begin(), m_responses.end(), [](optional_size_t response){ return response; }))
	{
		throw logic_error("Every item in left column should be matched with item in right column");
	}
	//check responses
	for (size_t index = 0; index < m_responses.size(); ++index)
	{
		auto rightIndex = find(m_rightItemIndexes.begin(), m_rightItemIndexes.end(), m_leftItemIndexes[index]);
		if (rightIndex == m_rightItemIndexes.end())
		{
			throw runtime_error("Undefined error. Matched item is not found.");
		}
		size_t correctIndex = (size_t)(rightIndex - m_rightItemIndexes.begin());
		if (*m_responses[index] != correctIndex) 
		{
			m_review = make_unique<CQuestionReview>(); //mistake found
			return;
		}
	}
	m_review = make_unique<CQuestionReview>(m_question->GetScore(), true);
}

void CMatchingQuestionState::SelectResponse(size_t leftItem, size_t rightItem)
{
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}

	if (rightItem >= m_question->GetRightMatchingItemsCount())
	{
		throw out_of_range("Index of right item is out of range");
	}

	if (any_of(m_responses.begin(), m_responses.end(), [rightItem](optional_size_t item){ return (item) ? (*item == rightItem) : item; }))
	{
		throw logic_error("Right item is already selected");
	}
	m_responses.at(leftItem) = rightItem;
}

void CMatchingQuestionState::UnselectResponse(size_t index)
{
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}
	m_responses.at(index).reset();
}

vector<size_t> const& CMatchingQuestionState::GetLeftIndexes()const
{
	return m_leftItemIndexes;
}
vector<size_t> const& CMatchingQuestionState::GetRightIndexes()const
{
	return m_rightItemIndexes;
}

std::vector<optional_size_t> const& CMatchingQuestionState::GetResponses()const
{
	return m_responses;
}
