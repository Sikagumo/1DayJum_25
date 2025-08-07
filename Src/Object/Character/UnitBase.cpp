#include"SelectLogicBase.h"
#include"CharacterBase.h"
#include "UnitBase.h"

UnitBase::UnitBase(void)
{
	canSelect_ = false;
}

UnitBase::~UnitBase(void)
{
}

void UnitBase::Update(void)
{
	character_->Update();
	if (canSelect_) {
		logic_->UpdateLogic();
	}
}

void UnitBase::Draw(void)
{
	character_->Draw();
}

void UnitBase::Release(void)
{
}

const bool UnitBase::IsSelect(void) const
{
	return logic_->IsSelect();
}

const int UnitBase::GetSelectNum(void) const
{
	return logic_->GetSelectNum();
}

void UnitBase::SetGoalPos(const VECTOR _pos)
{
	character_->SetGoalPos(_pos);
}

void UnitBase::ResetSelect(void)
{
	logic_->ResetSelect();
}

void UnitBase::ChangeSelectFlag(const bool _flag)
{
	canSelect_ = _flag;
}
