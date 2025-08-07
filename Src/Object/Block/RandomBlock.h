#pragma once
#include "BlockBase.h"
#include<map>

class RandomBlock :
    public BlockBase
{
public:
	enum class SELECT_TYPE
	{
		NONE = -1,

		SQUARE_TOP,   // 2x2éläpè„
		SQUARE_BTM, // 2Å~2éläpâ∫
		WID_TOP,   // â°í∑è„
		WID_MID,  // â°í∑íÜ
		WID_BTM, // â°í∑â∫

		L_BIG, // Lå^
		L_SML_TOP, // Lå^è¨è„
		L_SML_BTM, // Lå^è¨â∫

		CONCAVE,// âöå^

		MAX, // óvëfêî
	};

	// ëIëêî
	static constexpr int SELECT_NUM = 4;

	void Init(void);

	void Draw(void);

	AddBlock GetRandomShape(void);

	void CreateSelect(void);

	AddBlock GetSelectBlock(const int _num)const { return useBlocks_[_num]; }

private:
	void CreateShape(void);

	std::map<SELECT_TYPE, AddBlock> blockShapes_;

	AddBlock useBlocks_[SELECT_NUM];
	VECTOR drawStartPos_;

public:
	static constexpr bool SQUARE_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,0},
			{1,1,0},
			{0,0,0}
	};

	static constexpr bool SQUARE_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,1,0},
			{1,1,0}
	};

	static constexpr bool WID_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,1},
			{0,0,0},
			{0,0,0}
	};

	static constexpr bool WID_MID[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,1,1},
			{0,0,0}
	};

	static constexpr bool WID_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{0,0,0},
			{1,1,1}
	};

	static constexpr bool L_BIG[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,0,0},
			{1,0,0},
			{1,1,0}
	};

	static constexpr bool L_SML_TOP[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,0,0},
			{1,1,0},
			{0,0,0}
	};

	static constexpr bool L_SML_BTM[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{0,0,0},
			{1,0,0},
			{1,1,0}
	};

	static constexpr bool CONCAVE[ADD_BLOCK_SIZE_X][ADD_BLOCK_SIZE_Y] = {
			{1,1,0},
			{1,0,0},
			{1,1,0}
	};
};

