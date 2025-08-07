#pragma once
#include "./BlockController.h"
#include "../../Common/Vector2.h"

class Block
{
public:

	enum class TYPE
	{
		NONE = 0,
		NORMAL,
	};

	// �����[����
	static constexpr int LANE_MAX_X = 12;

	// �c���[����
	static constexpr int LANE_MAX_Y = 3;


	Block(void);

	~Block(void) = default;

	void Init(void);

	void Update(void);


	/// <summary>
	/// �u���b�N���蓖�ď���
	/// </summary>
	/// <param name="x">X�ʒu</param>
	/// <param name="y">Y�ʒu</param>
	/// <param name="type">�u���b�N�̎��</param>
	void SetBlock(bool _blocks[BlockController::BLOCK_X][BlockController::BLOCK_Y], int _type = 1);

	/// <summary>
	/// ���[�����̏�Ԃ��擾
	/// </summary>
	bool GetLane(int x, int y);

	/// <summary>
	/// ���[���̃|�C���^���擾
	/// </summary>
	bool* GetLanePointer(void);

	// ���[���ʒu���X�V
	void SetLanePos(Vector2& pos);
	void SetLanePos(int posX, int posY);

	/// <summary>
	/// �v���C���[�̃��[���ʒu���擾
	/// </summary>
	Vector2& GetLanePos(void);

	

private:

	// ���[�����
	bool lane_[LANE_MAX_X][LANE_MAX_Y];

	// ���݈ʒu
	Vector2 lanePos_;

};