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
	std::unique_ptr<CharacterBase>character_;	//�L�����N�^�[
	std::unique_ptr<SelectLogicBase>logic_;		//�u���b�N�I�����W�b�N

	//���g�̑��ꃌ�[��(���쌴���쒆)

	bool canSelect_;	//�I�����\�ȏ�Ԃ�
};

