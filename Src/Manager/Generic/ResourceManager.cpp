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
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "TitleLogo.png");
	resourcesMap_.emplace(SRC::TITLE_LOGO, res);

	// ステージ画像
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "StageImage.png");
	resourcesMap_.emplace(SRC::STAGE_IMG, res);

	//ステージ画像（スタート地点）
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StartBlocks.png");
	resourcesMap_.emplace(SRC::START_BLOCKS, res);

	//背景ブロックベース
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/BlockBases.png");
	resourcesMap_.emplace(SRC::BLOCK_BASES, res);

	//背景
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Sky.png");
	resourcesMap_.emplace(SRC::SKY, res);
	
	//タイトルBGM
	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "Stanby.mp3");
	resourcesMap_.emplace(SRC::TITLE_BGM, res);

	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "決定.mp3");
	resourcesMap_.emplace(SRC::SELECT_SE, res);
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
