#include<DxLib.h>
#include "Game.h"
#include "../Object/Block/BlockController.h"

Game::Game(void)
{
	blockController_ = new BlockController();
}

Game::~Game(void)
{
}

void Game::Init(void)
{
}

void Game::Update(void)
{
}

void Game::Draw(void)
{
	blockController_->Draw();
	DrawString(0, 0, "GameScene", 0xffffff, false);
}

void Game::Release(void)
{
	delete blockController_;
}
