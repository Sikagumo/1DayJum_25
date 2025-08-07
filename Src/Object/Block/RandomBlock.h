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

		SQUARE_TOP,   // 2x2�l�p��
		SQUARE_BTM, // 2�~2�l�p��
		WID_TOP,   // ������
		WID_MID,  // ������
		WID_BTM, // ������

		L_BIG, // L�^
		L_SML_TOP, // L�^����
		L_SML_BTM, // L�^����

		CONCAVE,// ���^

		MAX, // �v�f��
	};

	// �I��
	static constexpr int SELECT_NUM = 4;

	void Init(void);

	AddBlock GetRandomShape(void);

private:
	void CreateShape(void);

	std::map<SELECT_TYPE, AddBlock> blockShapes_;
};

