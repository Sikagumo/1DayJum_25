#include"PlayerCharacter.h"
#include"PlayerLogic.h"
#include "Player.h"

void Player::Init(const VECTOR& _pos)
{
	//�L�����N�^�[�̐���
	character_ = std::make_unique<PlayerCharacter>();
	character_->Init();
	//�����ʒu�ݒ�
	character_->SetPos(_pos);

	//���W�b�N�̐���
	logic_ = std::make_unique<PlayerLogic>();
}
