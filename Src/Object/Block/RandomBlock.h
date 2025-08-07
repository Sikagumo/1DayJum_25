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

		SQUARE_UP,   // 2x2éläpè„
		SQUARE_DOWN, // 2Å~2éläpâ∫
		WID_UP,   // â°í∑è„
		WID_MID,  // â°í∑íÜ
		WID_DOWN, // â°í∑â∫

		L, // Lå^
		L_MIN_UP, // Lå^è¨è„
		L_MIN_DOWN, // Lå^è¨â∫

		CONCAVE,// âöå^

		MAX, // óvëfêî
	};

	// ëIëêî
	static constexpr int SELECT_NUM = 4;

	void Init(void);

private:
	std::map<SELECT_TYPE, AddBlock> blockShapes_;
};

