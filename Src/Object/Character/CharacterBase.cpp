#include "CharacterBase.h"

CharacterBase::CharacterBase(void)
{
}

CharacterBase::~CharacterBase(void)
{
}

void CharacterBase::Init(void)
{
}

void CharacterBase::Draw(void)
{
	//�L�����N�^�[�`��
	//DrawRotaGraph(pos_.x, pos_.y, 1.0f, 0.0f, characterImgs_[animIdx_], true);

	//�f�o�b�O�p
	DrawCircle(pos_.x, pos_.y, 5, 0x55ff55);
}

void CharacterBase::Release(void)
{
}

void CharacterBase::Anim(void)
{
}

void CharacterBase::SetPos(const VECTOR _pos)
{
	pos_ = _pos;
}

void CharacterBase::SetGoalPos(const VECTOR _pos)
{
	goalPos_ = _pos;
}