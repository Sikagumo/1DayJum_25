#include<DxLib.h>
#include"../Manager/GameSystem/CharacterManager.h"
#include "Game.h"

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::Init(void)
{
	//キャラクター生成
	charaMng_ = std::make_unique<CharacterManager>();
	charaMng_->Init(1);	//引数はSceneManagerよりユーザ人数を取得(マージ後)

	update_ = &Game::UpdateStartTurnFaze;
}

void Game::Update(void)
{
	//更新処理
	(this->*update_)();
}

void Game::Draw(void)
{
	DrawString(0, 0, "GameScene", 0xffffff, false);

	//キャラクター
	charaMng_->Draw();
}

void Game::Release(void)
{
}

void Game::UpdateStartTurnFaze(void)
{
	//ターン開始の宣言

	//選択肢の表示

	//終了したら選択肢フェーズへ
	update_ = &Game::UpdateSelectFaze;
}

void Game::UpdateSelectFaze(void)
{
	//プレイヤーたちの入力受付
	if (charaMng_->Update()) {
		//終了したら反映フェーズへ
		update_ = &Game::UpdateMoveFaze;
	}
}

void Game::UpdateMoveFaze(void)
{
	//入力を受けて結果を反映する。
	//足場を反映

	//キャラクターの移動

	//終了したらターン開始フェーズへ
	update_ = &Game::UpdateStartTurnFaze;
}
