#pragma once
#include <chrono>
#include<vector>
#include<memory>
#include <DxLib.h>
class SceneBase;
class Fader;
class Camera;

//��`
//�V�[���J��::���C���V�[���̐؂芷��
//�V�[���ړ�::�T�u�V�[���Ƃ̈ړ��̂����

class SceneManager
{

public:
	static constexpr VECTOR LIGHT_DIR = { 0.00f, -1.00f, 1.00f };
	static constexpr float STICK_START_POW = 0.5f;	//�R���g���[���[�̃X�e�B�b�N臒l

	static constexpr int POP_SCENE_TYPE_NUM = 1;	//�|�b�v�\�ȃV�[���̎�ސ�

	// �V�[���Ǘ��p
	enum class SCENE_ID
	{
		NONE,
		TITLE,
		GAME,
		CLEAR,

		//�|�b�v�\�V�[��
		PAUSE,
	};

	enum class CNTL
	{
		NONE,
		KEY,
		PAD,
	};
	
	// �C���X�^���X�̐���
	static void CreateInstance(void);

	// �C���X�^���X�̎擾
	static SceneManager& GetInstance(void);

	void Init(void);
	void Init3D(void);
	void Update(void);
	void Draw(void);

	// ���\�[�X�̔j��
	void Destroy(void);

	void ChangeScene(std::shared_ptr<SceneBase>_scene);
	void PushScene(std::shared_ptr<SceneBase>_scene);
	void PopScene(void);
	void JumpScene(std::shared_ptr<SceneBase>_scene);

	// �V�[��ID�̎擾
	SCENE_ID GetSceneID(void);

	// �f���^�^�C���̎擾
	float GetDeltaTime(void) const;


	// �J�����̎擾
	Camera& GetCamera(void) const;

	//�����ʂ̎擾�E�ݒ�
	const CNTL GetController(void)const;
	void SetController(const CNTL _cntl);
	void SwitchController(void);	//�؂芷��


	int GetMainScreen(void)const { return mainScreen_; }
	const float GetTotalTime(void)const { return totalTime_; }

	//�v���C���[��
	void SetPlayerNum(int _num);
private:

	// �ÓI�C���X�^���X
	static SceneManager* instance_;

	SCENE_ID sceneId_;
	SCENE_ID subSceneList_[POP_SCENE_TYPE_NUM];
	SCENE_ID waitSceneId_;
	CNTL cntl_;

	std::shared_ptr<Camera> camera_;

	// ���C���X�N���[��
	int mainScreen_;

	// �t�F�[�h
	Fader* fader_;

	// �e��V�[��
	std::vector<std::shared_ptr<SceneBase>> scenes_;	//�V�[���i�[

	// �V�[���J�ڒ�����
	bool isSceneChanging_;

	// �f���^�^�C��
	std::chrono::system_clock::time_point preTime_;
	float deltaTime_;
	float totalTime_;

	//�X�V�J�E���^�[�̔{��
	float updateSpeedRate_;

	//�v���C���[��
	int playerNum_;
	
	// �f�t�H���g�R���X�g���N�^��private�ɂ��āA
	// �O�����琶���ł��Ȃ��l�ɂ���
	SceneManager(void);
	// �R�s�[�R���X�g���N�^�����l
	SceneManager(const SceneManager&);
	// �f�X�g���N�^�����l
	~SceneManager(void) = default;

	// �f���^�^�C�������Z�b�g����
	void ResetDeltaTime(void);

	// �t�F�[�h
	void Fade(void);
};