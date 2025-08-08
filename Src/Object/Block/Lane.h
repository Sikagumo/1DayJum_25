#pragma once
#include"BlockBase.h"

#include<DxLib.h>

class Lane
	: public BlockBase
{
public:
	static constexpr int LANE_SIZE_X = 12;
	static constexpr int LANE_SIZE_Y = 3;

	static constexpr int LANE_DIFF_Y = BLOCK_SIZE_Y * (LANE_SIZE_Y + 1);

	static constexpr float LANE_START_POS_X = 150.0f;
	static constexpr float LANE_START_POS_Y = 200.0f;

	Lane(void);
	~Lane(void);

	void Init(const int _playerNum);
	void Draw(void);

	//足場の追加
	bool AddBlockToLane(const AddBlock _addBlock);

	VECTOR GetStartPos(void)const { return laneStartPos_; }

	//ゴールの判定
	const bool IsGoal(void);

	//横のレーン数を取得
	int GetReachableLaneX(void) { return reachableLaneX_; }

private:
	bool IsAdd(const AddBlock _addBlock);

	bool lane_[LANE_SIZE_X][LANE_SIZE_Y];	//レーン全体
	int reachableLaneX_;	//現在の横方向最大値

	VECTOR laneStartPos_;	//レーン開始位置
};

