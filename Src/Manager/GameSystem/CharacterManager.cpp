#include"../../Object/Character/Player/Player.h"
#include"../../Object/Character/CPU/Cpu.h"
#include "CharacterManager.h"

namespace {
	const int POSITION_Y_DIFF = 50.0f;	//プレイヤー初期位置Y方向差分（ステージの幅に合わせる。）
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

		//プレイヤーまたはCPUの生成
		if (i < _userNum) {
			characteres_[i] = std::make_unique<Player>();
		}
		else {
			characteres_[i] = std::make_unique<Cpu>();
		}

		//初期化
		characteres_[i]->Init(i);
		//差分増加
		posY += POSITION_Y_DIFF;
	}

	ChangeState(CHRACTER_STATE::NOMAL);
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

void CharacterManager::ChangeState(const CHRACTER_STATE _state)
{
	state_ = _state;

	//各種状態での更新完了判定処理
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

	//キャラクターの状態を変更
	for (auto& chara : characteres_) {
		chara->ChangeUpdateState(state_);
	}
}

void CharacterManager::NextState(void)
{
	//ゲームフローとしての次の状態に遷移する
	int stateInt = static_cast<int>(state_);
	int nextStateInt = (stateInt + 1) % static_cast<int>(CHRACTER_STATE::MAX);

	state_ = static_cast<CHRACTER_STATE>(nextStateInt);

	//状態遷移
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
	//関数のNextState()でのみ次にいく

	return false;
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
			selectPlayerNum_ = nextPlayer;

			if (nextPlayer < CHARACTER_NUM) {
				//次のプレイヤーの選択を可能に
				characteres_[nextPlayer]->ChangeSelectFlag(true);
			}
			else {
				//最後のプレイヤーだったら終了
				//次は反映の更新なので終了処理をそちらに写す

				isFinishUpdate_ = &CharacterManager::FinishUpdateEffect;
				return true;
			}
		}
	}
	return false;
}

bool CharacterManager::FinishUpdateEffect(const int _charaNum)
{
	//全キャラクターの反映が完了したかの判定

	return false;
}