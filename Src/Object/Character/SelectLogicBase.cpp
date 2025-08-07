#include "SelectLogicBase.h"

SelectLogicBase::SelectLogicBase(void)
{
	isSelect_ = false;
	selectNum_ = -1;
}

SelectLogicBase::~SelectLogicBase(void)
{
}

const bool SelectLogicBase::IsSelect(void) const
{
	return isSelect_;
}

const int SelectLogicBase::GetSelectNum(void) const
{
	return selectNum_;
}

void SelectLogicBase::ResetSelect(void)
{
	isSelect_ = false;
	selectNum_ = -1;
}
