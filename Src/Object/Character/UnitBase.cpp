#include"SelectLogicBase.h"
#include"CharacterBase.h"
#include "UnitBase.h"

UnitBase::UnitBase(void)
{
	canSelect_ = false;
	update_ = &UnitBase::UpdateNomal;
	updateEffect_ = &UnitBase::UpdateEffectOfBlock;
}

UnitBase::~UnitBase(void)
{
}

void UnitBase::Update(void)
{
	(this->*update_)();
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

void UnitBase::UpdateNomal(void)
{
	character_->Update();
}

void UnitBase::UpdateSelect(void)
{
	character_->Update();
	//選択ロジックの更新
	if (canSelect_) {
		logic_->UpdateLogic();
	}
}

void UnitBase::UpdateEffect(void)
{
	character_->Update();
	//反映の更新
	(this->*updateEffect_)();
}

void UnitBase::UpdateEffectOfBlock(void)
{
}

void UnitBase::UpdateEffectOfMove(void)
{
}
