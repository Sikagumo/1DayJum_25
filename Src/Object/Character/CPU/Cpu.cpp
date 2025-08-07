#include"../../Block/Lane.h"
#include"CpuCharacter.h"
#include"CpuLogic.h"
#include "Cpu.h"

void Cpu::Init(const VECTOR _pos)
{
	//�L�����N�^�[�̐���
	character_ = std::make_unique<CpuCharacter>();
	character_->Init();
	//�����ʒu�ݒ�
	character_->SetPos(_pos);

	blockLane_ = std::make_unique<Lane>();
	blockLane_->Init(1);	//��P��

	//���W�b�N�̐���
	logic_ = std::make_unique<CpuLogic>();
}
