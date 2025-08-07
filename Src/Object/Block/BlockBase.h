#pragma once
class BlockBase
{
public:
	static constexpr int ADD_BLOCK_SIZE_X = 3;
	static constexpr int ADD_BLOCK_SIZE_Y = 3;

	static constexpr int BLOCK_SIZE_X = 64;
	static constexpr int BLOCK_SIZE_Y = 64;

	struct AddBlock
	{
		bool info[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y];	//�ǉ�����u���b�N�̏���3��3
	};

	void Init(void);

private:
	int blockImg_;
};

