#pragma once
#include<memory>
#include"../../Object/Block/BlockBase.h"

class UnitBase;

class CharacterManager
{
public:
	enum class CHRACTER_STATE {
		NOMAL
		,SELECT
		,EFFECT
		,MAX
	};

	static constexpr int CHARACTER_NUM = 4;

	CharacterManager(void);
	~CharacterManager(void);

	void Init(const int _userNum);
	bool Update(void);
	void Draw(void);
	void Release(void);
	void ChangeState(const CHRACTER_STATE _state);
	void NextState(void);

	const int GetSelectNum(const int _charaNum)const;
	void SelectLane(const int _charaNum, const BlockBase::AddBlock _addBlock);
	const bool IsGoal(const int _charaNum);
	int GetReachableLaneX(const int _charaNum);

private:
	//各種状態での更新完了の判定処理
	bool FinishUpdateNomal(const int _charaNum);	//選択フェーズでの終了処理
	bool FinishUpdateSelect(const int _charaNum);	//選択フェーズでの終了処理
	bool FinishUpdateEffect(const int _charaNum);		//反映の終了処理

	using FinishUpdate_f = bool(CharacterManager::*)(const int _charaNum);
	FinishUpdate_f isFinishUpdate_;

	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];	//キャラクターたち
	CHRACTER_STATE state_;

	int selectPlayerNum_;	//0~3
};

