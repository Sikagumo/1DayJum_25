#include<DxLib.h>

#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"
#include"Game.h"
#include "Title.h"

Title::Title(void)
{
}

Title::~Title(void)
{
}

void Title::Init(void)
{
}

void Title::Update(void)
{
	//ƒV[ƒ“‘JˆÚ
	if (InputManager::GetInstance().IsTrigerrDown("action")) {
		SceneManager::GetInstance().JumpScene(std::make_shared<Game>());
	}
}

void Title::Draw(void)
{
	DrawString(0, 0, "TitleScene", 0xffffff, false);
}

void Title::Release(void)
{
}
