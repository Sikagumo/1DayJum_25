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
	//�e���Ԃł̍X�V�����̔��菈��
	bool FinishUpdateSelect(void);
	bool FinishUpdateMove(void);

	using FinishUpdate_f = bool(CharacterManager::*)(void);
	FinishUpdate_f isFinishUpdate_;

	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];	//�L�����N�^�[����

	int selectPlayerNum_;	//0~3
};

