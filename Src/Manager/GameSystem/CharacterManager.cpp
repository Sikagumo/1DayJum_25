#include"../../Object/Character/Player/Player.h"
#include"../../Object/Character/CPU/Cpu.h"
#include "CharacterManager.h"

namespace {
	const int POSITION_Y_DIFF = 50.0f;	//�v���C���[�����ʒuY���������i�X�e�[�W�̕��ɍ��킹��B�j
}

CharacterManager::CharacterManager(void)
{
	selectPlayerNum_ = 0;
}

CharacterManager::~CharacterManager(void)
{
}

void CharacterManager::Init(const int _userNum)
{
	state_ = CHRACTER_STATE::NOMAL;

	float posY = 0.0f;

	for (int i = 0; i < CHARACTER_NUM; i++) {

		//�v���C���[�܂���CPU�̐���
		if (i < _userNum) {
			characteres_[i] = std::make_unique<Player>();
		}
		else {
			characteres_[i] = std::make_unique<Cpu>();
		}

		//������
		characteres_[i]->Init(i);
		//��������
		posY += POSITION_Y_DIFF;
	}

	ChangeState(CHRACTER_STATE::NOMAL);
}

bool CharacterManager::Update(void)
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		//�L�����N�^�[�X�V
		characteres_[i]->Update();

		//���݂̃t�F�[�Y�̍X�V���I�����Ă�����
		if ((this->*isFinishUpdate_)(i)) {
			return true;
		}
	}

	return false;
}

void CharacterManager::Draw(void)
{
	for (auto& chara : characteres_) {
		chara->Draw();
	}
}

void CharacterManager::Release(void)
{
}

void CharacterManager::ChangeState(const CHRACTER_STATE _state)
{
	state_ = _state;

	//�e���Ԃł̍X�V�������菈��
	switch (state_) {
	case CHRACTER_STATE::NOMAL:
		isFinishUpdate_ = &CharacterManager::FinishUpdateNomal;
		break;

	case CHRACTER_STATE::SELECT:
		isFinishUpdate_ = &CharacterManager::FinishUpdateSelect;
		break;

	case CHRACTER_STATE::EFFECT:
		isFinishUpdate_ = &CharacterManager::FinishUpdateEffect;
	}

	//�L�����N�^�[�̏�Ԃ�ύX
	for (auto& chara : characteres_) {
		chara->ChangeUpdateState(state_);
	}
}

void CharacterManager::NextState(void)
{
	//�Q�[���t���[�Ƃ��Ă̎��̏�ԂɑJ�ڂ���
	int stateInt = static_cast<int>(state_);
	int nextStateInt = (stateInt + 1) % static_cast<int>(CHRACTER_STATE::MAX);

	state_ = static_cast<CHRACTER_STATE>(nextStateInt);

	//��ԑJ��
	ChangeState(state_);
}

const int CharacterManager::GetSelectNum(const int _charaNum)const
{
	return characteres_[_charaNum]->GetSelectNum();
}

void CharacterManager::SelectLane(const int _charaNum, const BlockBase::AddBlock _addBlock)
{
	characteres_[_charaNum]->AddLane(_addBlock);
}

bool CharacterManager::FinishUpdateNomal(const int _charaNum) {
	//�֐���NextState()�ł̂ݎ��ɂ���

	return false;
}

bool CharacterManager::FinishUpdateSelect(const int _charaNum)
{
	//���ݓ��͂��󂯕t���Ă���L�����N�^�[�̏ꍇ
	if (_charaNum == selectPlayerNum_) {
		//�I�����I��������
		if (characteres_[_charaNum]->IsSelect()) {
			//���g��I���\��Ԃ�����
			characteres_[_charaNum]->ChangeSelectFlag(false);

			//���̃v���C���[�ԍ�
			int nextPlayer = _charaNum + 1;
			selectPlayerNum_ = nextPlayer;

			if (nextPlayer < CHARACTER_NUM) {
				//���̃v���C���[�̑I�����\��
				characteres_[nextPlayer]->ChangeSelectFlag(true);
			}
			else {
				//�Ō�̃v���C���[��������I��
				//���͔��f�̍X�V�Ȃ̂ŏI��������������Ɏʂ�

				isFinishUpdate_ = &CharacterManager::FinishUpdateEffect;
				return true;
			}
		}
	}
	return false;
}

bool CharacterManager::FinishUpdateEffect(const int _charaNum)
{
	//�S�L�����N�^�[�̔��f�������������̔���

	return false;
}