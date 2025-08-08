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
	//�e���Ԃł̍X�V�����̔��菈��
	bool FinishUpdateNomal(const int _charaNum);	//�I���t�F�[�Y�ł̏I������
	bool FinishUpdateSelect(const int _charaNum);	//�I���t�F�[�Y�ł̏I������
	bool FinishUpdateEffect(const int _charaNum);		//���f�̏I������

	using FinishUpdate_f = bool(CharacterManager::*)(const int _charaNum);
	FinishUpdate_f isFinishUpdate_;

	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];	//�L�����N�^�[����
	CHRACTER_STATE state_;

	int selectPlayerNum_;	//0~3
};

