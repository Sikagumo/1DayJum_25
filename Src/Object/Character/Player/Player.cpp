#include"../../Block/Lane.h"
#include"PlayerCharacter.h"
#include"PlayerLogic.h"
#include "Player.h"

void Player::Init(const int _playerNum)
{
	//キャラクターの生成
	character_ = std::make_unique<PlayerCharacter>();
	character_->Init();

	blockLane_ = std::make_unique<Lane>();
	blockLane_->Init(_playerNum);	//何Pか

	if (_playerNum == 0)canSelect_ = true;

	VECTOR setCharaPos = blockLane_->GetStartPos();
	setCharaPos.x -= 32;

	//初期位置設定
	character_->SetPos(setCharaPos);

	//ロジックの生成
	logic_ = std::make_unique<PlayerLogic>();
}
