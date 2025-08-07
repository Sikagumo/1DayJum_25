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
	//�L�����N�^�[����
	charaMng_ = std::make_unique<CharacterManager>();
	charaMng_->Init(1);	//������SceneManager��胆�[�U�l�����擾(�}�[�W��)

	update_ = &Game::UpdateStartTurnFaze;
}

void Game::Update(void)
{
	//�X�V����
	(this->*update_)();
}

void Game::Draw(void)
{
	DrawString(0, 0, "GameScene", 0xffffff, false);

	//�L�����N�^�[
	charaMng_->Draw();
}

void Game::Release(void)
{
}

void Game::UpdateStartTurnFaze(void)
{
	//�^�[���J�n�̐錾

	//�I�����̕\��

	//�I��������I�����t�F�[�Y��
	update_ = &Game::UpdateSelectFaze;
}

void Game::UpdateSelectFaze(void)
{
	//�v���C���[�����̓��͎�t
	if (charaMng_->Update()) {
		//�I�������甽�f�t�F�[�Y��
		update_ = &Game::UpdateMoveFaze;
	}
}

void Game::UpdateMoveFaze(void)
{
	//���͂��󂯂Č��ʂ𔽉f����B
	//����𔽉f

	//�L�����N�^�[�̈ړ�

	//�I��������^�[���J�n�t�F�[�Y��
	update_ = &Game::UpdateStartTurnFaze;
}
