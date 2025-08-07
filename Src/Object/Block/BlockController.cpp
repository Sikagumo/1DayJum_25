#include "BlockController.h"
#include <DxLib.h>
#include <map>
#include <array>
#include "./Block.h"
#include "../../Manager/Generic/ResourceManager.h"
#include "../../Manager/Generic/Resource.h"


BlockController::BlockController(void)
{
	Init();
}

void BlockController::Init(void)
{
	blockGraph_ = ResourceManager::GetInstance().Load(ResourceManager::SRC::STAGE_IMG).handleId_;

	SetBlockShape();

	ChoiceBlocks();
}

void BlockController::Draw(void)
{
	int posX, posY = 0;
	posX = OFFSET_X;
	posY = OFFSET_Y;

	for (int i = 0; i < 4; ++i)
	{
		for (int x = 0; x < Block::LANE_MAX_X; ++x)
		{
			for (int y = 0; y < Block::LANE_MAX_Y; ++y)
			{
				DrawGraph(posX, posY, blockGraph_, true);
				posX += IMAGE_SIZE_Y;
			}

			posX = OFFSET_X;
			posY += IMAGE_SIZE_Y;
		}
	}
}


void BlockController::SetBlockShape(void)
{
	/*　ブロックの形状割り当て　*/

	std::array<std::array<int, BLOCK_X>, BLOCK_Y> arrayInit = {};
	for (int y = 0; y < BLOCK_Y; ++y)
	{
		for (int x = 0; x < BLOCK_X; ++x)
		{
			arrayInit[x][y] = false;
		}
	}
	auto array = arrayInit;

	// 四角上
	array = { { {{1,1,0}},
			    {{1,1,0}},
			    {{0,0,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::SQUARE_UP, array);

	// 四角下
	array = { { {{0,0,0}},
			    {{1,1,0}},
			    {{1,1,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::SQUARE_DOWN, array);

	// 横長上
	array = { { {{1,1,1}},
			    {{0,0,0}},
			    {{0,0,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::WID_UP, array);

	// 横長中
	array = { { {{0,0,0}},
			    {{1,1,1}},
			    {{0,0,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::WID_MID, array);

	// 横長下
	array = { { {{0,0,0}},
			    {{0,0,0}},
			    {{1,1,1}}  } };
	blockShapes_.emplace(SELECT_TYPE::WID_DOWN, array);

	// L型
	array = { { {{1,0,0}},
			    {{1,0,0}},
			    {{1,1,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::L, array);

	// L小型上
	array = { { {{1,0,0}},
			    {{1,1,0}},
			    {{0,0,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::L_MIN_UP, array);

	// L小型下
	array = { { {{0,0,0}},
			    {{1,0,0}},
			    {{1,1,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::L_MIN_DOWN, array);

	// 凹型
	array = { { {{1,1,0}},
			    {{1,0,0}},
			    {{1,1,0}}  } };
	blockShapes_.emplace(SELECT_TYPE::CONCAVE, array);


}


bool BlockController::IsSelect(int _selectNum, int _laneY)
{
	// 選択した番号の形状
	SELECT_TYPE select = static_cast<SELECT_TYPE>(select_[_selectNum]);

	// つながっているときtrue
	return (blockShapes_[select][0][_laneY] == true);
}

void BlockController::ChoiceBlocks(void)
{
	for (int i = 0; i < SELECT_NUM; ++i)
	{
		// 抽選
		select_[i] = GetRand(static_cast<int>(SELECT_TYPE::MAX));
	}
}

bool BlockController::SelectBlocks(int _x, int _y, int _selectNum)
{
	SELECT_TYPE select = static_cast<SELECT_TYPE>(_selectNum);

	return GetBlocks(_x, _y, select);
}

bool BlockController::GetBlocks(int x, int y, BlockController::SELECT_TYPE type)
{
	// 無効状態時、false
	if (type == SELECT_TYPE::NONE) return false;

	return blockShapes_[type][x][y];
}
