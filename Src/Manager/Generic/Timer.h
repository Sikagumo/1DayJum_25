#pragma once
class Timer
{
public:

	//����
	struct Time
	{
		int minute;		//��
		int second;		//�b
	};

	//��������
	static constexpr Time TIME_LIMIT = { 0,10 };

	//�^�C�}�[�w�i�T�C�Y
	static constexpr float TIMER_BACK_RATE = 0.8f;
	static constexpr int TIMER_BACK_SIZE_X = static_cast<int>(298 * TIMER_BACK_RATE);
	static constexpr int TIMER_BACK_SIZE_Y = static_cast <int>(168 * TIMER_BACK_RATE);

	//�����`�搔
	static constexpr int NUM_CNT = 2;

	//�C���X�^���X�̐���
	static void CreateInstance(void);
	
	//�C���X�^���X�̎擾
	static Timer& GetInstance(void);

	//�X�V
	void Update(void);
	
	//�`��
	void Draw(void);

	//�C���X�^���X�̍폜
	void Destroy(void);

private:

	//�R���X�g���N�^
	Timer(void);

	//�f�X�g���N�^
	~Timer(void);

	//�R�s�[�̋֎~
	Timer(Timer& _copy) = delete;
	Timer& operator=(Timer& _copy) = delete;

	//���g�̃C���X�^���X
	static Timer* instance_;

	//����
	Time time_;

	//�J�E���^
	float cnt_;

	//�^�C�}�[�w�i
	int timerBackImg_;

	//�����摜
	int* numImgs_;
};

