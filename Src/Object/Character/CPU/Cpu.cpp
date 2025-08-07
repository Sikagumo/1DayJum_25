#include"CpuCharacter.h"
#include"CpuLogic.h"
#include "Cpu.h"

void Cpu::Init(const VECTOR& _pos)
{
	//キャラクターの生成
	character_ = std::make_unique<CpuCharacter>();
	character_->Init();
	//初期位置設定
	character_->SetPos(_pos);

	//ロジックの生成
	logic_ = std::make_unique<CpuLogic>();
}
