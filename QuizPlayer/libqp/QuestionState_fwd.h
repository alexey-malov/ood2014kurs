#pragma once

namespace qp
{

class IQuestionState;
typedef std::shared_ptr<IQuestionState> IQuestionStatePtr;

class IMultipleChoiceQuestionState;
typedef std::shared_ptr<IMultipleChoiceQuestionState> IMultipleChoiceQuestionStatePtr;

template <typename Base>
class CQuestionStateImpl;

typedef CQuestionStateImpl<IQuestionState> CQuestionState;

typedef std::shared_ptr<CQuestionState> CQuestionStatePtr;

}