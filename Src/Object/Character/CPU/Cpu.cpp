#include"../../Block/Lane.h"
#include"CpuCharacter.h"
#include"CpuLogic.h"
#include "Cpu.h"

void Cpu::Init(const int _playerNum)
{
	//�L�����N�^�[�̐���
	character_ = std::make_unique<CpuCharacter>();
	character_->Init();
	

	blockLane_ = std::make_unique<Lane>();
	blockLane_->Init(_playerNum);	//��P��

	VECTOR setCharaPos = blockLane_->GetStartPos();
	setCharaPos.x -= 32;

	//�����ʒu�ݒ�
	character_->SetPos(setCharaPos);

	//���W�b�N�̐���
	logic_ = std::make_unique<CpuLogic>();
}
