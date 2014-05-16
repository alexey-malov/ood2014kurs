#include "stdafx.h"
#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MatchingQuestionView.h"

using namespace qp;
using namespace std;

CMatchingQuestionView::CMatchingQuestionView(const CMatchingQuestionStatePtr & questionState, std::ostream & outputStream)
:CQuestionView(questionState, outputStream)
{
}

CMatchingQuestionView::~CMatchingQuestionView()
{
}
