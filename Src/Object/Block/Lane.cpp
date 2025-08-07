#include "Lane.h"

Lane::Lane(void)
{
}

Lane::~Lane(void)
{
}

void Lane::Init(const int _playerNum)
{
	//自レーンの開始位置
	laneStartPos_ = { LANE_START_POS_X,LANE_START_POS_Y + (LANE_DIFF_Y * (_playerNum - 1)),0.0f };
	reachableLaneX = 0;

	//配置初期化
	for (int x = 1; x < LANE_SIZE_X; ++x)
	{
		for (int y = 0; y < LANE_SIZE_Y; ++y)
		{
			lane_[0][y] = true;
			lane_[x][y] = false;
		}
	}
}

void Lane::Draw(void)
{
	int posX = laneStartPos_.x, posY = laneStartPos_.y;
	int color = 0xffffff;

	for (int x = 0; x < LANE_SIZE_X; ++x)
	{
		for (int y = 0; y < LANE_SIZE_Y; ++y)
		{
			color = 0xffffff;
			//配置されていたら赤色に
			if (lane_[x][y])color = 0xff0000;
			
			//DrawGraph(posX, posY, blockGraph_, true);
			DrawCircle(posX, posY, 4, color);
			posY += BLOCK_SIZE_Y;
		}

		posY = laneStartPos_.y;
		posX += BLOCK_SIZE_X;
	}
}

bool Lane::AddBlockToLane(const AddBlock _addBlock)
{
	//追加可能なブロックじゃないなら不可能と返す。
	if (!IsAdd(_addBlock))return false;

	int nextPlaceableX = reachableLaneX + 1;

	int addBlockCntX = 0;

	for (int x = nextPlaceableX; x < nextPlaceableX + ADD_BLOCK_SIZE_X; x++ ) {
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			//追加ブロックの配置情報格納
			lane_[x][y] = _addBlock.info[addBlockCntX][y];
		}
		addBlockCntX++;
	}

	return true;
}

bool Lane::IsAdd(const AddBlock _addBlock)
{
	for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
		//同一の高さにブロックがある場合
		if (lane_[reachableLaneX][y] && _addBlock.info[0][y]) {
			//通行可能なのでOKとする
			return true;
		}
	}

	return false;
}
