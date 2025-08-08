#pragma once
#include <map>
#include <string>
#include "Resource.h"
#include"SceneManager.h"

class ResourceManager
{

public:

	//�����摜�p�萔
	static constexpr int NUMBERS_NUM_X = 5;
	static constexpr int NUMBERS_NUM_Y = 2;
	static constexpr int NUMBERS_SIZE = 128;

	// ���\�[�X��
	enum class SRC
	{
		//�摜
		TITLE_LOGO,			//�^�C�g�����S
		TITLE_BUTTON,		//�^�C�g���{�^��
		RETRY_BUTTON,		//���g���C�{�^��
		SELECT_BUTTON,		//�Z���N�g�{�^��
		ARROW_RIGHT,		//�E���
		PLAYER_BUTTON_1,	//�l���I��1�l
		PLAYER_BUTTON_2,	//�l���I��2�l
		PLAYER_BUTTON_3,	//�l���I��3�l
		PLAYER_BUTTON_4,	//�l���I��4�l
		TIMER_BACK,			//�^�C�}�[�w�i
		NUMBERS,			//����
		PASS_CONTROLLER,	//�R���g���[���[�n��
		RANK_FIRST,			//1��
		RANK_SECOND,		//2��
		RANK_THIRD,			//3��
		RANK_FOURTH,		//4��
		START_IMG,			//�X�^�[�g�摜
		FINISH_IMG,			//�I���摜
		WIN_IMG,			//�����摜
		START_BLOCK,		//�X�^�[�g�u���b�N
		LAVA_BLOCK,			//�n��u���b�N
		STONE_BLOCK,		//�΃u���b�N
		BUTTON_UP,			//��{�^��
		BUTTON_RIGHT,		//�E�{�^��
		BUTTON_DOWN,		//���{�^��
		BUTTON_LEFT,		//���{�^��
		BACK_LAVA,			//�n��w�i
		BACK_SKY,			//��w�i

		PLAYER_ONE,
		PLAYER_TWO,
		PLAYER_THREE,
		PLAYER_FOUR,


		//���f��
		STAGE_MDL,

		//��

		//BGM
		TITLE_BGM,

		//SE
		TIMER_SE,

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
	void InitSelect(void);

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

