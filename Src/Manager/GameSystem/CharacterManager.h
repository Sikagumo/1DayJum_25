#pragma once
#include<memory>

class UnitBase;

class CharacterManager
{
public:
	enum class CHRACTER_STATE {
		NOMAL
		,SELECT
		,MOVE
	};

	static constexpr int CHARACTER_NUM = 4;

	CharacterManager(void);
	~CharacterManager(void);

	void Init(const int _userNum);
	bool Update(void);
	void Draw(void);
	void Release(void);

private:
	//�e���Ԃł̍X�V�����̔��菈��
	bool FinishUpdateSelect(const int _charaNum);	//�I���t�F�[�Y�ł̏I������
	bool FinishUpdateMove(const int _charaNum);		//���f�̏I������

	using FinishUpdate_f = bool(CharacterManager::*)(const int _charaNum);
	FinishUpdate_f isFinishUpdate_;

	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];	//�L�����N�^�[����

	int selectPlayerNum_;	//0~3
};

