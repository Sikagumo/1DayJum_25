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
	//�V�[�����Ƃ̃��\�[�X�Ɛ�������\��������ǉ��V�[���̃��\�[�X
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

	// �^�C�g��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Title2.png");
	resourcesMap_.emplace(SRC::TITLE_LOGO, res);

	// �X�e�[�W�摜
	//res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "StageImage.png");
	//resourcesMap_.emplace(SRC::STAGE_IMG, res);
}

void ResourceManager::InitGame(void)
{
	Resource res;

	//�^�C�}�[�w�i
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Ui/Timer.png");
	resourcesMap_.emplace(SRC::TIMER_BACK, res);
	
	//�����摜
	res = Resource(Resource::TYPE::IMGS, Application::PATH_IMAGE + "Numbers2.png", NUMBERS_NUM_X, NUMBERS_NUM_Y, NUMBERS_SIZE, NUMBERS_SIZE);
	resourcesMap_.emplace(SRC::NUMBERS, res);

	//�^�C�}�[��
	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "Timer.mp3");
	resourcesMap_.emplace(SRC::TIMER_SE, res);

	//�R���g���[���[�n��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "PassControler.png");
	resourcesMap_.emplace(SRC::PASS_CONTROLLER, res);

	//��{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button1.png");
	resourcesMap_.emplace(SRC::BUTTON_UP, res);

	//�E�{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button3.png");
	resourcesMap_.emplace(SRC::BUTTON_RIGHT, res);

	//���{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Button4.png");
	resourcesMap_.emplace(SRC::BUTTON_DOWN, res);

	//���{�^��
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

	//�X�^�[�g�u���b�N
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StartBlock.png");
	resourcesMap_.emplace(SRC::START_BLOCK, res);

	//�n��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/LavaBlock.png");
	resourcesMap_.emplace(SRC::LAVA_BLOCK, res);

	//�΃u���b�N
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StoneBlock.png");
	resourcesMap_.emplace(SRC::STONE_BLOCK, res);

	//�n��w�i
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Lava.png");
	resourcesMap_.emplace(SRC::BACK_LAVA, res);
	
	//��w�i
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Sky.png");
	resourcesMap_.emplace(SRC::BACK_SKY, res);
}

void ResourceManager::InitClear(void)
{
	Resource res;

	//�^�C�g���J�ڃ{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "TitleButton.png");
	resourcesMap_.emplace(SRC::TITLE_BUTTON, res);

	//���g���C�{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "RetryButton.png");
	resourcesMap_.emplace(SRC::RETRY_BUTTON, res);

	//�Z���N�g�J�ڃ{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "SelectButton.png");
	resourcesMap_.emplace(SRC::SELECT_BUTTON, res);

	//�E���
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "ArrowRight.png");
	resourcesMap_.emplace(SRC::ARROW_RIGHT, res);

	//1��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "1stImage.png");
	resourcesMap_.emplace(SRC::RANK_FIRST, res);

	//2��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "2ndImage.png");
	resourcesMap_.emplace(SRC::RANK_SECOND, res);

	//3��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "3rdImage.png");
	resourcesMap_.emplace(SRC::RANK_THIRD, res);

	//4��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "4thImage.png");
	resourcesMap_.emplace(SRC::RANK_FOURTH, res);

	//WIN
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Wins.png");
	resourcesMap_.emplace(SRC::WIN_IMG, res);

	//1��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player1.png");
	resourcesMap_.emplace(SRC::PLAYER_ONE, res);

	//2��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player2.png");
	resourcesMap_.emplace(SRC::PLAYER_TWO, res);

	//3��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player3.png");
	resourcesMap_.emplace(SRC::PLAYER_THREE, res);

	//4��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "UI/Player4.png");
	resourcesMap_.emplace(SRC::PLAYER_FOUR, res);
}

void ResourceManager::InitSelect()
{
	Resource res;

	//�v���C���[1�{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_1p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_1, res);

	//�v���C���[2�{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_2p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_2, res);

	//�v���C���[3�{�^��
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "player_button_3p.png");
	resourcesMap_.emplace(SRC::PLAYER_BUTTON_3, res);

	//�v���C���[4�{�^��
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
		// �o�^����Ă��Ȃ�
		return nullptr;
	}

	rPair->second.Load();

	// �O�̂��߃R�s�[�R���X�g���N�^
	Resource* ret = new Resource(rPair->second);
	loadedMap_.emplace(src, ret);

	return ret;
}
