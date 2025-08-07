#pragma once
#include <map>
#include <array>
class Block;
#include "../../Common/Vector2.h"

/// <summary>
/// �u���b�N�Ǘ��N���X
/// </summary>
class BlockController
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


	// �c�����l
	static constexpr int OFFSET_X = 100;

	// �������l
	static constexpr int OFFSET_Y = 200;

	static constexpr int IMAGE_SIZE_X = 100;
	static constexpr int IMAGE_SIZE_Y = 100;
	
	// ���[���̊Ԋu
	static constexpr int SPACE_Y = 75;

	// �I��
	static constexpr int SELECT_NUM = 4;


	static constexpr int BLOCK_X = 3;
	static constexpr int BLOCK_Y = 3;


	BlockController(void);

	~BlockController(void) = default;


	void Init(void);

	void Update(void);

	void Draw(void);

	/// <summary>
	/// �Ē��I����
	/// </summary>
	void ChoiceBlocks(void);

	/// <summary>
	/// �u���b�N���Ȃ����Ă��邩����
	/// </summary>
	/// <param name="_selectNum">�I�������ԍ�</param>
	/// <param name="_laneY">���[���c�ʒu</param>
	bool IsSelect(int _selectNum, int _laneY);

	/// <summary>
	/// �I�����̃u���b�N�����蓖��
	/// </summary>
	/// <param name="_x"></param>
	/// <param name="_y"></param>
	/// <param name="selectNum"></param>
	/// <returns></returns>
	bool SelectBlocks(int _x, int _y, int selectNum);

private:

	int blockGraph_;

	std::map<SELECT_TYPE, std::array<std::array<bool, BLOCK_X>,BLOCK_Y>> blockShapes_;
	
	// �I����
	int select_[SELECT_NUM];

	/// <summary>
	/// �u���b�N���擾
	/// </summary>
	/// <param name="_x">X</param>
	/// <param name="_y">Y</param>
	/// <param name="_type">�u���b�N�̌`�̎��</param>
	bool GetBlocks(int _x, int _y, SELECT_TYPE _type);


	void SetBlockShape(void);
};