#include<DxLib.h>
#include "RandomBlock.h"


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
	/*@ƒuƒƒbƒN‚ÌŒ`óŠ„‚è“–‚Ä@*/

	AddBlock addShape;
	

	// lŠpã
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = SQUARE_TOP[x][y];
		}
	}

	blockShapes_.emplace(SELECT_TYPE::SQUARE_TOP, addShape);

	// lŠp‰º
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = SQUARE_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::SQUARE_BTM, addShape);

	// ‰¡’·ã
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_TOP[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_TOP, addShape);

	// ‰¡’·’†
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_MID[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_MID, addShape);

	// ‰¡’·‰º
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = WID_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::WID_BTM, addShape);

	// LŒ^
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_BIG[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_BIG, addShape);

	// L¬Œ^ã
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_SML_TOP[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_SML_TOP, addShape);

	// L¬Œ^‰º
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = L_SML_BTM[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::L_SML_BTM, addShape);

	// ‰šŒ^
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = CONCAVE[x][y];
		}
	}
	blockShapes_.emplace(SELECT_TYPE::CONCAVE, addShape);
}
