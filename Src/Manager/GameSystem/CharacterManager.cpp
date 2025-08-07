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

void CharacterManager::Update(void)
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		characteres_[i]->Update();


		//���ݓ��͂��󂯕t���Ă���L�����N�^�[�̏ꍇ
		if (i == selectPlayerNum_) {
			//�I�����I��������
			if (characteres_[i]->IsSelect()) {
				//���g��I���\��Ԃ�����
				characteres_[i]->ChangeSelectFlag(false);

				//���̃v���C���[�̑I�����\��
				int nextPlayer = i + 1;
				if (nextPlayer < CHARACTER_NUM) {
					characteres_[nextPlayer]->ChangeSelectFlag(true);
				}
				else {
					selectTurnEnd_ = true;
				}
			}
		}
	}
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
