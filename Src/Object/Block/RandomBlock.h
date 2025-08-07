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

		SQUARE_UP,   // 2x2�l�p��
		SQUARE_DOWN, // 2�~2�l�p��
		WID_UP,   // ������
		WID_MID,  // ������
		WID_DOWN, // ������

		L, // L�^
		L_MIN_UP, // L�^����
		L_MIN_DOWN, // L�^����

		CONCAVE,// ���^

		MAX, // �v�f��
	};

	// �I��
	static constexpr int SELECT_NUM = 4;

	void Init(void);

private:
	std::map<SELECT_TYPE, AddBlock> blockShapes_;
};

