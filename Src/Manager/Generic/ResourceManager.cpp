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
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "TitleLogo.png");
	resourcesMap_.emplace(SRC::TITLE_LOGO, res);

	// �X�e�[�W�摜
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "StageImage.png");
	resourcesMap_.emplace(SRC::STAGE_IMG, res);

	//�X�e�[�W�摜�i�X�^�[�g�n�_�j
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/StartBlocks.png");
	resourcesMap_.emplace(SRC::START_BLOCKS, res);

	//�w�i�u���b�N�x�[�X
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Block/BlockBases.png");
	resourcesMap_.emplace(SRC::BLOCK_BASES, res);

	//�w�i
	res = Resource(Resource::TYPE::IMG, Application::PATH_IMAGE + "Sky.png");
	resourcesMap_.emplace(SRC::SKY, res);
	
	//�^�C�g��BGM
	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "Stanby.mp3");
	resourcesMap_.emplace(SRC::TITLE_BGM, res);

	res = Resource(Resource::TYPE::SOUND, Application::PATH_SOUND + "����.mp3");
	resourcesMap_.emplace(SRC::SELECT_SE, res);
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
