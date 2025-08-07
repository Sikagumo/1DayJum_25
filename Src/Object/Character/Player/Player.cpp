#include"../../Block/Lane.h"
#include"PlayerCharacter.h"
#include"PlayerLogic.h"
#include "Player.h"

void Player::Init(const int _playerNum)
{
	//�L�����N�^�[�̐���
	character_ = std::make_unique<PlayerCharacter>();
	character_->Init();

	blockLane_ = std::make_unique<Lane>();
	blockLane_->Init(_playerNum);	//��P��

	if (_playerNum == 0)canSelect_ = true;

	VECTOR setCharaPos = blockLane_->GetStartPos();
	setCharaPos.x -= 32;

	//�����ʒu�ݒ�
	character_->SetPos(setCharaPos);

	//���W�b�N�̐���
	logic_ = std::make_unique<PlayerLogic>();
}
