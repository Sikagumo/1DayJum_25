#pragma once
#include <map>
#include <string>
#include "Resource.h"
#include"SceneManager.h"

class ResourceManager
{

public:

	// ���\�[�X��
	enum class SRC
	{
		//�摜
		TITLE_LOGO,
		TITLE_BUTTON,
		RETRY_BUTTON,
		SELECT_BUTTON,
		ARROW_RIGHT,
		PLAYER_BUTTON_1,
		PLAYER_BUTTON_2,
		PLAYER_BUTTON_3,
		PLAYER_BUTTON_4,

		//���f��
		STAGE_MDL,

		//��
		TITLE_BGM,

		//�G�t�F�N�g
	};

	// �����I�ɃC���X�e���X�𐶐�����
	static void CreateInstance(void);

	// �ÓI�C���X�^���X�̎擾
	static ResourceManager& GetInstance(void);

	// ������
	void Init(SceneManager::SCENE_ID _scene= SceneManager::SCENE_ID::NONE);

	
private:
	//�V�[�����ƂɃf�[�^��ǂݍ��ނ��Ƃɂ���
	void InitTitle(void);
	void InitGame(void);
	void InitClear(void);
	void InitSelect();

public:
	// ���(�V�[���ؑ֎��Ɉ�U���)
	void Release(void);

	// ���\�[�X�̊��S�j��
	void Destroy(void);

	// ���\�[�X�̃��[�h
	Resource Load(SRC src);

	// ���\�[�X�̕������[�h(���f���p)
	int LoadModelDuplicate(SRC src);

private:

	// �ÓI�C���X�^���X
	static ResourceManager* instance_;

	// ���\�[�X�Ǘ��̑Ώ�
	std::map<SRC, Resource> resourcesMap_;

	// �ǂݍ��ݍς݃��\�[�X
	std::map<SRC, Resource*> loadedMap_;

	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	ResourceManager(void);

	// �f�X�g���N�^�����l
	~ResourceManager(void) = default;

	// �������[�h
	Resource* _Load(SRC src);

};

