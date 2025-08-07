#include"PlayerCharacter.h"
#include"PlayerLogic.h"
#include "Player.h"

void Player::Init(const VECTOR& _pos)
{
	//キャラクターの生成
	character_ = std::make_unique<PlayerCharacter>();
	character_->Init();
	//初期位置設定
	character_->SetPos(_pos);

	//ロジックの生成
	logic_ = std::make_unique<PlayerLogic>();
}
