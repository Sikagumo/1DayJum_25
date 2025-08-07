#pragma once
#include<DxLib.h>
#include<memory>

class CharacterBase;
class SelectLogicBase;

class UnitBase
{
public:
	UnitBase(void);
	virtual ~UnitBase(void);

	virtual void Init(const VECTOR _pos) = 0;
	void Update(void);
	void Draw(void);
	void Release(void);

	const bool IsSelect(void)const;
	const int GetSelectNum(void)const;

	void SetGoalPos(const VECTOR _pos);
	void ResetSelect(void);

	void ChangeSelectFlag(const bool _flag);

protected:
	std::unique_ptr<CharacterBase>character_;	//キャラクター
	std::unique_ptr<SelectLogicBase>logic_;		//ブロック選択ロジック

	//自身の足場レーン(中川原制作中)

	bool canSelect_;	//選択が可能な状態か
};

