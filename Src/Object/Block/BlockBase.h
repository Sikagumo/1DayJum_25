#pragma once
class BlockBase
{
public:
	static constexpr int ADD_BLOCK_SIZE_X = 3;
	static constexpr int ADD_BLOCK_SIZE_Y = 3;

	static constexpr int BLOCK_SIZE_X = 32;
	static constexpr int BLOCK_SIZE_Y = 32;

	struct AddBlock
	{
		bool info[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y];	//í«â¡Ç∑ÇÈÉuÉçÉbÉNÇÃèÓïÒÇÕ3Åñ3
	};

	void Init(void);

protected:
	int blockImg_;
	int lavaImg_;
};

