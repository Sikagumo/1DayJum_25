#pragma once
class Timer
{
public:

	struct Time
	{
		int second;
		int minute;
	};

	//�C���X�^���X�̐���
	static void CreateInstance(void);
	
	//�C���X�^���X�̎擾
	static Timer& GetInstance(void);

private:

	//�R���X�g���N�^
	Timer(void);

	//�f�X�g���N�^
	~Timer(void);

	//�R�s�[�̋֎~
	Timer(Timer& _copy) = delete;
	Timer& operator=(Timer& _copy) = delete;

	Time time_;
};

