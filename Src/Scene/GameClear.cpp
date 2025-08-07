#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"

#include"../Application.h"

#include "GameClear.h"
#include "Game.h"
#include "Title.h"
#include "Select.h"

GameClear::GameClear(void)
{
	next_ = (int)NEXT_SCENE::NONE;
}

GameClear::~GameClear(void)
{
}

void GameClear::Init(void)
{
	next_ = (int)NEXT_SCENE::TITLE;
}

void GameClear::Update(void)
{
	ChangeNext();

	ChangeScene();
}

void GameClear::Draw(void)
{
	DrawString(0, 0, "GameClear", 0xffffff, false);
	DrawFormatString(100, 100, 0xffffff, "%d", next_);
}

void GameClear::Release(void)
{
}

void GameClear::ChangeNext()
{
	auto& inpM=InputManager::GetInstance();

	//次のシーン切り替え
	if (inpM.IsTrigerrDown("up"))
		--next_;
	else if (inpM.IsTrigerrDown("down"))
		++next_;

	next_=std::clamp(next_, 1, 3);
}

void GameClear::ChangeScene()
{
	//シーン遷移
	if (InputManager::GetInstance().IsTrigerrDown("action")) {
		switch (next_)
		{
		case 1:
			SceneManager::GetInstance().JumpScene(std::make_shared<Game>());
			break;
		case 2:
			SceneManager::GetInstance().JumpScene(std::make_shared<Select>());
			break;
		case 3:
			SceneManager::GetInstance().JumpScene(std::make_shared<Title>());
			break;
		};
	}
}
