#include"../../Object/Character/Player/Player.h"
#include"../../Object/Character/CPU/Cpu.h"
#include "CharacterManager.h"

namespace {
	const int POSITION_Y_DIFF = 50.0f;	//�v���C���[�����ʒuY���������i�X�e�[�W�̕��ɍ��킹��B�j
}

CharacterManager::CharacterManager(void)
{
}

CharacterManager::~CharacterManager(void)
{
}

void CharacterManager::Init(const int _userNum)
{
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
		characteres_[i]->Init(VECTOR{ 0,posY,0 });
		//��������
		posY += POSITION_Y_DIFF;
	}
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

			if (nextPlayer < CHARACTER_NUM) {
				//���̃v���C���[�̑I�����\��
				characteres_[nextPlayer]->ChangeSelectFlag(true);
			}
			else {
				//�Ō�̃v���C���[��������I��
				return true;
			}
		}
	}
	return false;
}

bool CharacterManager::FinishUpdateMove(const int _charaNum)
{
	//�S�L�����N�^�[�̈ړ��������������̔���
}