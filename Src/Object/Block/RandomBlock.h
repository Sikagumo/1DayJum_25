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

	AddBlock GetRandomShape(void);

private:
	void CreateShape(void);

	std::map<SELECT_TYPE, AddBlock> blockShapes_;
};

