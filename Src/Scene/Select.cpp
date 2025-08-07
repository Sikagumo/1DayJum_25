#include<DxLib.h>

#include"../Application.h"

#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"

#include"Game.h"
#include "Select.h"

Select::Select(void)
{
	playerNum_ = -1;
}

Select::~Select(void)
{
}

void Select::Init(void)
{
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

	playerNum_ = std::clamp(playerNum_, 1, 4);

	SceneManager::GetInstance().SetPlayerNum(playerNum_);
}
