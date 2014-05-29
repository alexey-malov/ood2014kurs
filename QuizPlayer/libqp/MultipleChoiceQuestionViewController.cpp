#include "stdafx.h"
#include "MultipleChoiceQuestionViewController.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestionView.h"

namespace qp
{

CMultipleChoiceQuestionViewController::CMultipleChoiceQuestionViewController(CMultipleChoiceQuestionStatePtr const& questionState, CMultipleChoiceQuestionViewPtr const& view)
:CQuestionViewController(questionState, view)
{

}


CMultipleChoiceQuestionViewController::~CMultipleChoiceQuestionViewController()
{
}

}