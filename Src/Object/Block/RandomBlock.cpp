#include<DxLib.h>
#include "RandomBlock.h"


void RandomBlock::Init(void)
{
	CreateShape();
	drawStartPos_ = { 800.0f,80.0f,0.0f };
}

void RandomBlock::Draw(void)
{
	int posX = drawStartPos_.x, posY = drawStartPos_.y;
	int diffY = BLOCK_SIZE_X * (ADD_BLOCK_SIZE_Y + 1);
	int cnt = 0;

	int color= 0xffffff;

	for (auto& select : useBlocks_) {
		for (int x = 0; x < ADD_BLOCK_SIZE_X; x++) {
			for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
				//ƒuƒƒbƒN‚ª‚ ‚é‚È‚çÔ‚É
				color = 0xffffff;
				if (select.info[y][x] == true)color = 0xff0000;

				DrawCircle(posX, posY, 4, color);
				posY += BLOCK_SIZE_Y;
			}
			posY = drawStartPos_.y + diffY * cnt;
			posX += BLOCK_SIZE_X;
		}
		cnt++;
		posX = drawStartPos_.x;
		posY = drawStartPos_.y + diffY * cnt;
	}
}

BlockBase::AddBlock RandomBlock::GetRandomShape(void)
{
	SELECT_TYPE createType = static_cast<SELECT_TYPE>(GetRand(static_cast<int>(SELECT_TYPE::MAX)));
	return blockShapes_[createType];
}

void RandomBlock::CreateSelect(void)
{
	for (int i = 0; i < SELECT_NUM; i++) {
		useBlocks_[i] = GetRandomShape();
	}
}

void RandomBlock::CreateShape(void)
{
	/*@ƒuƒƒbƒN‚ÌŒ`óŠ„‚è“–‚Ä@*/

	AddBlock addShape;
	

	// ŽlŠpã
	for (int x = 0; x < ADD_BLOCK_SIZE_X; ++x)
	{
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; ++y)
		{
			addShape.info[x][y] = SQUARE_TOP[x][y];
		}
	}

	blockShapes_.emplace(SELECT_TYPE::SQUARE_TOP, addShape);

	// ŽlŠp‰º
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
