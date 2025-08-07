#include "Block.h"
#include "./BlockController.h"
#include <DxLib.h>

Block::Block(void)
{
	for (int x = 0; x < LANE_MAX_X; ++x)
	{
		for (int y = 0; y < LANE_MAX_Y; ++y)
		{
			lane_[x][y] = false;
		}
	}

}


void Block::Init(void)
{
	lanePos_ = { 0,((LANE_MAX_Y - 1) / 2) };
}

void Block::Update(void)
{

}


void Block::SetBlock(bool _blocks[BlockController::BLOCK_X][BlockController::BLOCK_Y], int type)
{
	int laneX = 0;
	//int block[BlockController::BLOCK_X][BlockController::BLOCK_Y]

	for (int x = 0; x < BlockController::BLOCK_X; ++x)
	{
		// プレイヤー位置の１つ先の位置
		laneX = (lanePos_.x + BlockController::BLOCK_X + 1);

		// レーンを超えた時
		if (laneX >= LANE_MAX_X) break;

		for (int y = 0; y < LANE_MAX_Y; y++)
		{
			// ブロックが埋められていないときはスキップ
			if (_blocks[x][y] == false) continue;

			lane_[laneX][y] = _blocks[x][y];
		}
	}
}

bool Block::GetLane(int x, int y)
{
	return lane_[x][y];
}

bool* Block::GetLanePointer(void)
{
	return *lane_;
}

void Block::SetLanePos(Vector2& pos)
{
	lanePos_ = pos;
}

void Block::SetLanePos(int posX, int posY)
{
	lanePos_.x = posX;
	lanePos_.y = posY;
}

Vector2& Block::GetLanePos(void)
{
	return lanePos_;
}
