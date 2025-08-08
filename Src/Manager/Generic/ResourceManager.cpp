#include <DxLib.h>
#include<memory>
#include "../../Application.h"
#include "Resource.h"
#include "ResourceManager.h"

ResourceManager* ResourceManager::instance_ = nullptr;

void ResourceManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new ResourceManager();
	}
	instance_->Init();
}

ResourceManager& ResourceManager::GetInstance(void)
{
	return *instance_;
}

void ResourceManager::Init(SceneManager::SCENE_ID _scene)
{
	//シーンごとのリソースと生成する可能性がある追加シーンのリソース
	switch (_scene)
	{
	case SceneManager::SCENE_ID::TITLE:
		InitTitle();
		break;
	case SceneManager::SCENE_ID::GAME:
		InitGame();
		break;
	case SceneManager::SCENE_ID::CLEAR:
		InitClear();
		break;
	case SceneManager::SCENE_ID::SELECT:
		InitSelect();
		break;
	default:
		break;
	}
}


void ResourceManager::InitTitle(void)
{
	Resource res;

	// タイトル
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Title2.png");
	resourcesMap_.emplace(SRC::TITLE_LOGO, res);

	// ステージ画像
	//res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "StageImage.png");
	//resourcesMap_.emplace(SRC::STAGE_IMG, res);
}

void ResourceManager::InitGame(void)
{
	Resource res;

	//タイマー背景
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Ui/Timer.png");
	resourcesMap_.emplace(SRC::TIMER_BACK, res);
	
	//数字画像
	res = Resource(Resource::TYPE::IMGS, Application::PATH_IMAGE + "Numbers2.png", NUMBERS_NUM_X, NUMBERS_NUM_Y, NUMBERS_SIZE, NUMBERS_SIZE);
	resourcesMap_.emplace(SRC::NUMBERS, res);

	//タイマー音
	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "Timer.mp3");
	resourcesMap_.emplace(SRC::TIMER_SE, res);

	//コントローラー渡し
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "PassControler.png");
	resourcesMap_.emplace(SRC::PASS_CONTROLLER, res);

	//上ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button1.png");
	resourcesMap_.emplace(SRC::BUTTON_UP, res);

	//右ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button3.png");
	resourcesMap_.emplace(SRC::BUTTON_RIGHT, res);

	//下ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button4.png");
	resourcesMap_.emplace(SRC::BUTTON_DOWN, res);

	//左ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button2.png");
	resourcesMap_.emplace(SRC::BUTTON_LEFT, res);

	//START
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Start.png");
	resourcesMap_.emplace(SRC::START_IMG, res);

	//FINISH
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Finish.png");
	resourcesMap_.emplace(SRC::FINISH_IMG, res);

	//WIN
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/WINS.png");
	resourcesMap_.emplace(SRC::WIN_IMG, res);

	//スタートブロック
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StartBlock.png");
	resourcesMap_.emplace(SRC::START_BLOCK, res);

	//溶岩
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/LavaBlock.png");
	resourcesMap_.emplace(SRC::LAVA_BLOCK, res);

	//石ブロック
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StoneBlock.png");
	resourcesMap_.emplace(SRC::STONE_BLOCK, res);

	//溶岩背景
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Lava.png");
	resourcesMap_.emplace(SRC::BACK_LAVA, res);
	
	//空背景
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Sky.png");
	resourcesMap_.emplace(SRC::BACK_SKY, res);
}

void ResourceManager::InitClear(void)
{
	Resource res;

	//タイトル遷移ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "TitleButton.png");
	resourcesMap_.emplace(SRC::TITLE_BUTTON, res);

	//リトライボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "RetryButton.png");
	resourcesMap_.emplace(SRC::RETRY_BUTTON, res);

	//セレクト遷移ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "SelectButton.png");
	resourcesMap_.emplace(SRC::SELECT_BUTTON, res);

	//右矢印
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "ArrowRight.png");
	resourcesMap_.emplace(SRC::ARROW_RIGHT, res);

	//1位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "1stImage.png");
	resourcesMap_.emplace(SRC::RANK_FIRST, res);

	//2位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "2ndImage.png");
	resourcesMap_.emplace(SRC::RANK_SECOND, res);

	//3位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "3rdImage.png");
	resourcesMap_.emplace(SRC::RANK_THIRD, res);

	//4位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "4thImage.png");
	resourcesMap_.emplace(SRC::RANK_FOURTH, res);

	//WIN
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Wins.png");
	resourcesMap_.emplace(SRC::WIN_IMG, res);

	//1位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player1.png");
	resourcesMap_.emplace(SRC::PLAYER_ONE, res);

	//2位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player2.png");
	resourcesMap_.emplace(SRC::PLAYER_TWO, res);

	//3位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player3.png");
	resourcesMap_.emplace(SRC::PLAYER_THREE, res);

	//4位
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player4.png");
	resourcesMap_.emplace(SRC::PLAYER_FOUR, res);
}

void ResourceManager::InitSelect()
{
	Resource res;

	//プレイヤー1ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_1p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_1, res);

	//プレイヤー2ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_2p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_2, res);

	//プレイヤー3ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_3p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_3, res);

	//プレイヤー4ボタン
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_4p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_4, res);
}


void ResourceManager::Release(void)
{
	for (auto& p : loadedMap_)
	{
		p.second->Release();
		delete p.second;
	}

	loadedMap_.clear();
	resourcesMap_.clear();
}

void ResourceManager::Destroy(void)
{
	Release();
	resourcesMap_.clear();
	delete instance_;
}

Resource ResourceManager::Load(SRC src)
{
	Resource* res = _Load(src);
	if (res == nullptr)
	{
		return Resource();
	}
	Resource ret = *res;
	return *res;
}

int ResourceManager::LoadModelDuplicate(SRC src)
{
	Resource* res = _Load(src);
	if (res == nullptr)
	{
		return -1;
	}

	int duId = MV1DuplicateModel(res->handleId_);
	res->duplicateModelIds_.push_back(duId);

	return duId;
}

ResourceManager::ResourceManager(void)
{
}

Resource* ResourceManager::_Load(SRC src)
{
	const auto& lPair = loadedMap_.find(src);
	if (lPair != loadedMap_.end())
	{
		return lPair->second;
	}

	const auto& rPair = resourcesMap_.find(src);
	if (rPair == resourcesMap_.end())
	{
		// 登録されていない
		return nullptr;
	}

	rPair->second.Load();

	// 念のためコピーコンストラクタ
	Resource* ret = new Resource(rPair->second);
	loadedMap_.emplace(src, ret);

	return ret;
}
