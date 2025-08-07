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

	// 横レーン数
	static constexpr int LANE_MAX_X = 12;

	// 縦レーン数
	static constexpr int LANE_MAX_Y = 3;


	Block(void);

	~Block(void) = default;

	void Init(void);

	void Update(void);


	/// <summary>
	/// ブロック割り当て処理
	/// </summary>
	/// <param name="x">X位置</param>
	/// <param name="y">Y位置</param>
	/// <param name="type">ブロックの種類</param>
	void SetBlock(bool _blocks[BlockController::BLOCK_X][BlockController::BLOCK_Y], int _type = 1);

	/// <summary>
	/// レーン内の状態を取得
	/// </summary>
	bool GetLane(int x, int y);

	/// <summary>
	/// レーンのポインタを取得
	/// </summary>
	bool* GetLanePointer(void);

	// レーン位置を更新
	void SetLanePos(Vector2& pos);
	void SetLanePos(int posX, int posY);

	/// <summary>
	/// プレイヤーのレーン位置を取得
	/// </summary>
	Vector2& GetLanePos(void);

	

private:

	// レーン状態
	bool lane_[LANE_MAX_X][LANE_MAX_Y];

	// 現在位置
	Vector2 lanePos_;

};