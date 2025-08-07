#include"../../Object/Character/Player/Player.h"
#include"../../Object/Character/CPU/Cpu.h"
#include "CharacterManager.h"

namespace {
	const int POSITION_Y_DIFF = 50.0f;	//プレイヤー初期位置Y方向差分（ステージの幅に合わせる。）
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

		//プレイヤーまたはCPUの生成
		if (i < _userNum) {
			characteres_[i] = std::make_unique<Player>();
		}
		else {
			characteres_[i] = std::make_unique<Cpu>();
		}

		//初期化
		characteres_[i]->Init(VECTOR{ 0,posY,0 });
		//差分増加
		posY += POSITION_Y_DIFF;
	}
}

void CharacterManager::Update(void)
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		characteres_[i]->Update();


		//現在入力を受け付けているキャラクターの場合
		if (i == selectPlayerNum_) {
			//選択が終了したら
			if (characteres_[i]->IsSelect()) {
				//自身を選択可能状態を解除
				characteres_[i]->ChangeSelectFlag(false);

				//次のプレイヤーの選択を可能に
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
