#pragma once
#include<DxLib.h>
#include<memory>
#include"../../Manager/GameSystem/CharacterManager.h"

class CharacterBase;
class SelectLogicBase;
class Lane;

class UnitBase
{
public:
	UnitBase(void);
	virtual ~UnitBase(void);

	virtual void Init(const int _playerNum) = 0;
	void Update(void);
	void Draw(void);
	void Release(void);

	const bool IsSelect(void)const;
	const int GetSelectNum(void)const;

	void SetGoalPos(const VECTOR _pos);
	void ResetSelect(void);

	void ChangeSelectFlag(const bool _flag);
	void ChangeUpdateState(const CharacterManager::CHRACTER_STATE& _state);

protected:
	void UpdateNomal(void);	//通常
	void UpdateSelect(void);//選択
	void UpdateEffect(void);//反映

	void UpdateEffectOfBlock(void);	//足場反映
	void UpdateEffectOfMove(void);	//移動反映

	using Update_f = void(UnitBase::*)(void);
	Update_f update_;		//関数ポインタ(通常・選択・反映)
	Update_f updateEffect_;	//（足場反映・移動反映）

	std::unique_ptr<CharacterBase>character_;	//キャラクター
	std::unique_ptr<SelectLogicBase>logic_;		//ブロック選択ロジック
	std::unique_ptr<Lane>blockLane_;		//ブロック選択ロジック

	//自身の足場レーン(中川原制作中)

	bool canSelect_;	//選択が可能な状態か
};

