#include"../Block/Lane.h"
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

void UnitBase::ChangeUpdateState(const CharacterManager::CHRACTER_STATE& _state)
{
	//各種状態に合わせた更新に変更

	using C_STATE = CharacterManager::CHRACTER_STATE;
	switch (_state) {
	case C_STATE::NOMAL:
		update_ = &UnitBase::UpdateNomal;
		break;

	case C_STATE::SELECT:
		update_ = &UnitBase::UpdateSelect;
		break;

	case C_STATE::EFFECT:
		//最初は足場の反映から
		updateEffect_ = &UnitBase::UpdateEffectOfBlock;
		update_ = &UnitBase::UpdateEffect;
	}
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
	//足場反映処理

	//終わったら移動の反映へ
	updateEffect_ = &UnitBase::UpdateEffectOfMove;
}

void UnitBase::UpdateEffectOfMove(void)
{
	//足場を確認し先端へ移動
}
