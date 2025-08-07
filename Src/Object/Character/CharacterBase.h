#pragma once
#include<DxLib.h>

class CharacterBase
{
public:
	CharacterBase(void);
	virtual ~CharacterBase(void);

	virtual void Init(void);
	virtual void Update(void) = 0;
	void Draw(void);
	virtual void Release(void);

	void SetPos(const VECTOR _pos);		//�ʒu�ݒ�(���������̂ݎg�p)
	void SetGoalPos(const VECTOR _pos);	//�ڕW�ʒu�̐ݒ�

protected:
	virtual void SetPram(void) = 0;
	void Anim(void);		//�A�j���[�V����

	int* characterImgs_;	//�L�����N�^�[�摜
	int animIdx_;			//�L�����N�^�[�A�j���[�V�����w�萔

	VECTOR pos_;			//�`��ʒu�i�������W�j
	VECTOR goalPos_;		//�ڕW�ʒu(�u���b�N�z�u��̈ړ����Ɏg�p)
};

