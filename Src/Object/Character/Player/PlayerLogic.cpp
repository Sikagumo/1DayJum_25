#include"../../../Manager/Generic/InputManager.h"
#include "PlayerLogic.h"

void PlayerLogic::UpdateLogic(void)
{
	//選択が完了していないとき
	if (!isSelect_) {
		//プレイヤーの入力を受け付ける
		UserInput();
	}
}

void PlayerLogic::UserInput(void)
{
	InputManager& inpM = InputManager::GetInstance();

	//ボタン四種の受付
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
