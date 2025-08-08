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

	//�����[���̊J�n�ʒu
	laneStartPos_ = { LANE_START_POS_X,LANE_START_POS_Y + (LANE_DIFF_Y * (_playerNum - 1)),0.0f };
	reachableLaneX_ = 0;

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
	int handle = -1;

	for (int x = 0; x < LANE_SIZE_X; ++x)
	{
		for (int y = 0; y < LANE_SIZE_Y; ++y)
		{
			handle = lavaImg_;
			//�z�u����Ă�����ԐF��
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
	//�ǉ��\�ȃu���b�N����Ȃ��Ȃ�s�\�ƕԂ��B
	if (!IsAdd(_addBlock))return false;

	int nextPlaceableX = reachableLaneX_ + 1;

	int addBlockCntX = 0;

	for (int x = nextPlaceableX; x < nextPlaceableX + ADD_BLOCK_SIZE_X; x++ ) {

		if (reachableLaneX_ >= LANE_SIZE_X)return false;

		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			//�ǉ��u���b�N�̔z�u���i�[
			//addblock��x,y�̗v�f�𔽓]���Ĕz�u���Ȃ���lane�Ƃ��ݍ���Ȃ�
			lane_[x][y] = _addBlock.info[y][addBlockCntX];
		}

		//���[�����i�񂾂�
		bool laneXAdvance = false;

		for (int y = 0; y < ADD_BLOCK_SIZE_Y; y++) {
			laneXAdvance = laneXAdvance || lane_[x][y];
		}

		//�i�񂾂Ȃ�
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
		//����̍����Ƀu���b�N������ꍇ
		//addblock��x,y�̗v�f�𔽓]���Ĕz�u���Ȃ���lane�Ƃ��ݍ���Ȃ�
		if (lane_[reachableLaneX_][y] && _addBlock.info[y][0]) {
			//�ʍs�\�Ȃ̂�OK�Ƃ���
			return true;
		}
	}

	return false;
}
