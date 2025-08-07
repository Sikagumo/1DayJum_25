#include "Lane.h"

Lane::Lane(void)
{
}

Lane::~Lane(void)
{
}

void Lane::Init(const int _playerNum)
{
	//�����[���̊J�n�ʒu
	laneStartPos_ = { LANE_START_POS_X,LANE_START_POS_Y + (LANE_DIFF_Y * (_playerNum - 1)),0.0f };
	reachableLaneX = 0;

	//�z�u������
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
			//�z�u����Ă�����ԐF��
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
	//�ǉ��\�ȃu���b�N����Ȃ��Ȃ�s�\�ƕԂ��B
	if (!IsAdd(_addBlock))return false;

	int nextPlaceableX = reachableLaneX + 1;

	int addBlockCntX = 0;

	for (int x = nextPlaceableX; x < nextPlaceableX + ADD_BLOCK_SIZE_X; x++ ) {
		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			//�ǉ��u���b�N�̔z�u���i�[
			lane_[x][y] = _addBlock.info[addBlockCntX][y];
		}
		addBlockCntX++;
	}

	return true;
}

bool Lane::IsAdd(const AddBlock _addBlock)
{
	for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
		//����̍����Ƀu���b�N������ꍇ
		if (lane_[reachableLaneX][y] && _addBlock.info[0][y]) {
			//�ʍs�\�Ȃ̂�OK�Ƃ���
			return true;
		}
	}

	return false;
}
