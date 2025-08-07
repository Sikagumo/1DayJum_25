#include"../../../Manager/Generic/InputManager.h"
#include "PlayerLogic.h"

void PlayerLogic::UpdateLogic(void)
{
	//�I�����������Ă��Ȃ��Ƃ�
	if (!isSelect_) {
		//�v���C���[�̓��͂��󂯕t����
		UserInput();
	}
}

void PlayerLogic::UserInput(void)
{
	InputManager& inpM = InputManager::GetInstance();

	//�{�^���l��̎�t
	if (inpM.IsTrigerrDown("up")) {
		isSelect_ = true;
		selectNum_ = static_cast<int>(SELECT_TYPE::TOP);
	}

	else if (inpM.IsTrigerrDown("right")) {
		isSelect_ = true;
		selectNum_ = static_cast<int>(SELECT_TYPE::RIGHT);
	}

	else if (inpM.IsTrigerrDown("left")) {
		isSelect_ = true;
		selectNum_ = static_cast<int>(SELECT_TYPE::LEFT);
	}

	else if (inpM.IsTrigerrDown("down")) {
		isSelect_ = true;
		selectNum_ = static_cast<int>(SELECT_TYPE::DOWN);
	}
}
