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

bool CharacterManager::Update(void)
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		//キャラクター更新
		characteres_[i]->Update();

		//現在のフェーズの更新が終了していたら
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
	//現在入力を受け付けているキャラクターの場合
	if (_charaNum == selectPlayerNum_) {
		//選択が終了したら
		if (characteres_[_charaNum]->IsSelect()) {
			//自身を選択可能状態を解除
			characteres_[_charaNum]->ChangeSelectFlag(false);

			//次のプレイヤー番号
			int nextPlayer = _charaNum + 1;

			if (nextPlayer < CHARACTER_NUM) {
				//次のプレイヤーの選択を可能に
				characteres_[nextPlayer]->ChangeSelectFlag(true);
			}
			else {
				//最後のプレイヤーだったら終了
				return true;
			}
		}
	}
	return false;
}

bool CharacterManager::FinishUpdateMove(const int _charaNum)
{
	//全キャラクターの移動が完了したかの判定
}