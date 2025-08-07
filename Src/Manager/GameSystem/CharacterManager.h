#pragma once
#include<memory>

class UnitBase;

class CharacterManager
{
public:
	enum class CHRACTER_STATE {
		NOMAL
		,SELECT
		,MOVE
	};

	static constexpr int CHARACTER_NUM = 4;

	CharacterManager(void);
	~CharacterManager(void);

	void Init(const int _userNum);
	bool Update(void);
	void Draw(void);
	void Release(void);

private:
	//各種状態での更新完了の判定処理
	bool FinishUpdateSelect(const int _charaNum);	//選択フェーズでの終了処理
	bool FinishUpdateMove(const int _charaNum);		//反映の終了処理

	using FinishUpdate_f = bool(CharacterManager::*)(const int _charaNum);
	FinishUpdate_f isFinishUpdate_;

	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];	//キャラクターたち

	int selectPlayerNum_;	//0~3
};

