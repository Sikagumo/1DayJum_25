#include<DxLib.h>

#include"../Application.h"

#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"
#include"../Manager/Generic/ResourceManager.h"

#include"Game.h"
#include "Select.h"

Select::Select(void)
{
	playerNum_ = -1;

	numImg1_ = -1;
	numImg2_ = -1;
	numImg3_ = -1;
	numImg4_ = -1;
}

Select::~Select(void)
{
}

void Select::Init(void)
{
	auto& resM = ResourceManager::GetInstance();
	resM.Init(SceneManager::SCENE_ID::SELECT);

	numImg1_ = resM.Load(ResourceManager::SRC::PLAYER_BUTTON_1).handleId_;
	numImg2_ = resM.Load(ResourceManager::SRC::PLAYER_BUTTON_2).handleId_;
	numImg3_ = resM.Load(ResourceManager::SRC::PLAYER_BUTTON_3).handleId_;
	numImg4_ = resM.Load(ResourceManager::SRC::PLAYER_BUTTON_4).handleId_;

	playerNum_ = 1;
}

void Select::Update(void)
{
	ChangePlayerNum();

	//ÉVÅ[ÉìëJà⁄
	if (InputManager::GetInstance().IsTrigerrDown("action")) {
		SceneManager::GetInstance().JumpScene(std::make_shared<Game>());
	}
}

void Select::Draw(void)
{
	DrawString(0, 0, "Select", 0xffffff, false);

	DrawFormatString(100, 100, 0xffffff, "playerNum = %d", playerNum_);

	DrawBox(0, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, 0xffffff,1);

	int boxPosX;
	int boxPosY;
	if (playerNum_ % 2 == 0)boxPosX = POS_X_RIGHT;
	else boxPosX = POS_X_LEFT;

	if (playerNum_ < 3)boxPosY = POS_Y_UP;
	else boxPosY = POS_Y_DOWN;

	DrawRotaGraph(POS_X_LEFT, POS_Y_UP, 0.4, 0, numImg1_, 1);
	DrawRotaGraph(POS_X_RIGHT, POS_Y_UP, 0.4, 0, numImg2_, 1);
	DrawRotaGraph(POS_X_LEFT, POS_Y_DOWN, 0.4, 0, numImg3_, 1);
	DrawRotaGraph(POS_X_RIGHT, POS_Y_DOWN, 0.4, 0, numImg4_, 1);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(boxPosX - 150, boxPosY - 100, boxPosX + 150, boxPosY + 100, 0xaaaa55, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void Select::Release(void)
{
}


void Select::ChangePlayerNum()
{
	auto& inpM = InputManager::GetInstance();

	if (inpM.IsTrigerrDown("up"))
		++playerNum_;
	else if (inpM.IsTrigerrDown("down"))
		--playerNum_;

	//playerNum_ = std::clamp(playerNum_, 1, 4);

	if (playerNum_ < 1)playerNum_ = 1;
	if (playerNum_ > 4)playerNum_ = 4;

	SceneManager::GetInstance().SetPlayerNum(playerNum_);
}
