#pragma once

namespace qp
{

class IQuestionState;
typedef std::shared_ptr<IQuestionState> IQuestionStatePtr;

class IMultipleChoiceQuestionState;
typedef std::shared_ptr<IMultipleChoiceQuestionState> IMultipleChoiceQuestionStatePtr;

class IMultipleResponseQuestionState;
typedef std::shared_ptr<IMultipleResponseQuestionState> IMultipleResponseQuestionStatePtr;

class IMatchingQuestionState;
typedef std::shared_ptr<IMatchingQuestionState> IMatchingQuestionStatePtr;

class ITypeInQuestionState;
typedef std::shared_ptr<ITypeInQuestionState> ITypeInQuestionStatePtr;

template <typename Base>
class CQuestionStateImpl;

typedef CQuestionStateImpl<IQuestionState> CQuestionState;
typedef std::shared_ptr<CQuestionState> CQuestionStatePtr;
typedef std::shared_ptr<IQuestionState> IQuestionStatePtr;

}