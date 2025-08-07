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
	void UpdateNomal(void);	//�ʏ�
	void UpdateSelect(void);//�I��
	void UpdateEffect(void);//���f

	void UpdateEffectOfBlock(void);	//���ꔽ�f
	void UpdateEffectOfMove(void);	//�ړ����f

	using Update_f = void(UnitBase::*)(void);
	Update_f update_;		//�֐��|�C���^(�ʏ�E�I���E���f)
	Update_f updateEffect_;	//�i���ꔽ�f�E�ړ����f�j

	std::unique_ptr<CharacterBase>character_;	//�L�����N�^�[
	std::unique_ptr<SelectLogicBase>logic_;		//�u���b�N�I�����W�b�N
	std::unique_ptr<Lane>blockLane_;		//�u���b�N�I�����W�b�N

	//���g�̑��ꃌ�[��(���쌴���쒆)

	bool canSelect_;	//�I�����\�ȏ�Ԃ�
};

