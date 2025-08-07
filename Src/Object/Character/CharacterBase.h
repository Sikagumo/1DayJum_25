#pragma once
#include<DxLib.h>

class CharacterBase
{
public:
	CharacterBase(void);
	virtual ~CharacterBase(void);

	virtual void Init(void);
	virtual void Update(void) = 0;
	void Draw(void);
	virtual void Release(void);

	void SetPos(const VECTOR _pos);		//位置設定(初期化時のみ使用)
	void SetGoalPos(const VECTOR _pos);	//目標位置の設定

protected:
	virtual void SetPram(void) = 0;
	void Anim(void);		//アニメーション

	int* characterImgs_;	//キャラクター画像
	int animIdx_;			//キャラクターアニメーション指定数

	VECTOR pos_;			//描画位置（中央座標）
	VECTOR goalPos_;		//目標位置(ブロック配置後の移動時に使用)
};

