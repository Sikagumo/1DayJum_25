#include "Lane.h"

Lane::Lane(void)
{
}

Lane::~Lane(void)
{
}

void Lane::Init(const int _playerNum)
{
	BlockBase::Init();

	//自レーンの開始位置
	laneStartPos_ = { LANE_START_POS_X,LANE_START_POS_Y + (LANE_DIFF_Y * (_playerNum - 1)),0.0f };
	reachableLaneX_ = 0;

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
	int handle = -1;

	for (int x = 0; x < LANE_SIZE_X; ++x)
	{
		for (int y = 0; y < LANE_SIZE_Y; ++y)
		{
			handle = lavaImg_;
			//配置されていたら赤色に
			if (lane_[x][y])handle = blockImg_;
			
			//DrawGraph(posX, posY, blockGraph_, true);
			DrawRotaGraph(posX, posY, 1.0, 0.0, handle, true);
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

	int nextPlaceableX = reachableLaneX_ + 1;

	int addBlockCntX = 0;

	for (int x = nextPlaceableX; x < nextPlaceableX + ADD_BLOCK_SIZE_X; x++ ) {

		if (reachableLaneX_ >= LANE_SIZE_X)return false;

		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			//追加ブロックの配置情報格納
			//addblockはx,yの要素を反転して配置しないとlaneとかみ合わない
			lane_[x][y] = _addBlock.info[y][addBlockCntX];
		}

		//レーンが進んだか
		bool laneXAdvance = false;

		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			laneXAdvance = laneXAdvance || lane_[x][y];
		}

		//進んだなら
		if (laneXAdvance)reachableLaneX_++;

		addBlockCntX++;
	}

	return true;
}

const bool Lane::IsGoal(void)
{
	for (int y = 0; y < LANE_SIZE_Y; y++)
	{
		if (lane_[LANE_SIZE_X - 1][y])return true;
	}

	return false;
}

bool Lane::IsAdd(const AddBlock _addBlock)
{
	for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
		//同一の高さにブロックがある場合
		//addblockはx,yの要素を反転して配置しないとlaneとかみ合わない
		if (lane_[reachableLaneX_][y] && _addBlock.info[y][0]) {
			//通行可能なのでOKとする
			return true;
		}
	}

	return false;
}
