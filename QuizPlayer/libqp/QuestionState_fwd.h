#pragma once

namespace qp
{

class IQuestionState;
typedef std::shared_ptr<IQuestionState> IQuestionStatePtr;
typedef std::shared_ptr<const IQuestionState> IConstQuestionStatePtr;

template <typename Base>
class CQuestionStateImpl;

typedef CQuestionStateImpl<IQuestionState> CQuestionState;

typedef std::shared_ptr<CQuestionState> CQuestionStatePtr;

}