#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"
#include"../Manager/Generic/ResourceManager.h"

#include"../Application.h"

#include "Game.h"
#include "Title.h"
#include "Select.h"

#include "GameClear.h"
GameClear::GameClear(void)
{
	next_ = (int)NEXT_SCENE::NONE;

	titleImg_ = -1;
	selectImg_ = -1;
	retryImg_ = -1;
	arrowImg_ = -1;

	arrowPosX_ = 0;
	arrowPosY_ = 0;
}

GameClear::~GameClear(void)
{
}

void GameClear::Init(void)
{
	auto& resM = ResourceManager::GetInstance();
	resM.Init(SceneManager::SCENE_ID::CLEAR);
	next_ = (int)NEXT_SCENE::GAME;

	titleImg_ = resM.Load(ResourceManager::SRC::TITLE_BUTTON).handleId_;
	selectImg_ = resM.Load(ResourceManager::SRC::SELECT_BUTTON).handleId_;
	retryImg_ = resM.Load(ResourceManager::SRC::RETRY_BUTTON).handleId_;
	arrowImg_ = resM.Load(ResourceManager::SRC::ARROW_RIGHT).handleId_;
	winImg_ = resM.Load(ResourceManager::SRC::WIN_IMG).handleId_;

	playerNumImg_.emplace_back(resM.Load(ResourceManager::SRC::PLAYER_ONE).handleId_);
	playerNumImg_.emplace_back(resM.Load(ResourceManager::SRC::PLAYER_TWO).handleId_);
	playerNumImg_.emplace_back(resM.Load(ResourceManager::SRC::PLAYER_THREE).handleId_);
	playerNumImg_.emplace_back(resM.Load(ResourceManager::SRC::PLAYER_FOUR).handleId_);

	arrowPosX_ = Application::SCREEN_SIZE_X / 2 - 100;
	arrowPosY_ = 200 + next_ * 100;
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

	//DrawBox(0, 0, Application::SCREEN_SIZE_X, Application::SCREEN_SIZE_Y, 0xffffff, 1);

	DrawRotaGraph(Application::SCREEN_SIZE_X/2, 300, 0.2, 0, retryImg_, 1);
	DrawRotaGraph(Application::SCREEN_SIZE_X/2, 400, 0.2, 0, selectImg_, 1);
	DrawRotaGraph(Application::SCREEN_SIZE_X/2, 500, 0.2, 0, titleImg_, 1);

	DrawRotaGraph(Application::SCREEN_SIZE_X / 2 - 200, 100, 5.0, 0.0, playerNumImg_[SceneManager::GetInstance().GetWinnerNum() - 1],true);
	DrawRotaGraph(Application::SCREEN_SIZE_X / 2 + 200, 100, 2.5, 0.0, winImg_,true);

	DrawRotaGraph(arrowPosX_, arrowPosY_, 0.1, 0, arrowImg_, 1);
}

void GameClear::Release(void)
{
}

void GameClear::DrawRank(int _1st, int _2nd_, int _3rd, int _4th)
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

	//next_=std::clamp(next_, 1, 3);

	if (next_ < 1)next_ = 1;
	if (next_ > 3)next_ = 3;

	arrowPosY_ = 200 + next_ * 100;
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
