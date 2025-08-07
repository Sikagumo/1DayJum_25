#include<DxLib.h>
#include "RandomBlock.h"

namespace {
	const bool SQUARE_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,0},
			{1,1,0},
			{0,0,0}
	};

	const bool SQUARE_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,1,0},
			{1,1,0}
	};

	const bool WID_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,1},
			{0,0,0},
			{0,0,0}
	};

	const bool WID_MID[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,1,1},
			{0,0,0}
	};

	const bool WID_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{0,0,0},
			{1,1,1}
	};

	const bool L_BIG[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,0,0},
			{1,0,0},
			{1,1,0}
	};

	const bool L_SML_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,0,0},
			{1,1,0},
			{0,0,0}
	};

	const bool L_SML_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,0,0},
			{1,1,0}
	};

	const bool CONCAVE[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,0},
			{1,0,0},
			{1,1,0}
	};
}


void RandomBlock::Init(void)
{
	CreateShape();
}

BlockBase::AddBlock RandomBlock::GetRandomShape(void)
{
	SELECT_TYPE createType = static_cast<SELECT_TYPE>(GetRand(static_cast<int>(SELECT_TYPE::MAX)));
	return blockShapes_[createType];
}

void RandomBlock::CreateShape(void)
{
	/*Å@ÉuÉçÉbÉNÇÃå`èÛäÑÇËìñÇƒÅ@*/

	AddBlock addShape;
	

	// éläpè„
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = SQUARE_TOP[x][y];
		}
	}

	blockShapes_.emplace(SELECT_TYPE::SQUARE_TOP, addShape);

	// éläpâ∫
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = SQUARE_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::SQUARE_BTM, addShape);

	// â°í∑è„
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_TOP[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_TOP, addShape);

	// â°í∑íÜ
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_MID[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_MID, addShape);

	// â°í∑â∫
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_BTM, addShape);

	// Lå^
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_BIG[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_BIG, addShape);

	// Lè¨å^è„
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_SML_TOP[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_SML_TOP, addShape);

	// Lè¨å^â∫
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_SML_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_SML_BTM, addShape);

	// âöå^
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = CONCAVE[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::CONCAVE, addShape);
}
