#pragma once
#include <map>
#include <array>
class Block;
#include "../../Common/Vector2.h"

/// <summary>
/// ブロック管理クラス
/// </summary>
class BlockController
{
public:

	enum class SELECT_TYPE
	{
		NONE = -1,

		SQUARE_UP,   // 2x2四角上
		SQUARE_DOWN, // 2×2四角下
		WID_UP,   // 横長上
		WID_MID,  // 横長中
		WID_DOWN, // 横長下

		L, // L型
		L_MIN_UP, // L型小上
		L_MIN_DOWN, // L型小下

		CONCAVE,// 凹型

		MAX, // 要素数
	};


	// 縦調整値
	static constexpr int OFFSET_X = 100;

	// 横調整値
	static constexpr int OFFSET_Y = 200;

	static constexpr int IMAGE_SIZE_X = 100;
	static constexpr int IMAGE_SIZE_Y = 100;
	
	// レーンの間隔
	static constexpr int SPACE_Y = 75;

	// 選択数
	static constexpr int SELECT_NUM = 4;


	static constexpr int BLOCK_X = 3;
	static constexpr int BLOCK_Y = 3;


	BlockController(void);

	~BlockController(void) = default;


	void Init(void);

	void Update(void);

	void Draw(void);

	/// <summary>
	/// 再抽選処理
	/// </summary>
	void ChoiceBlocks(void);

	/// <summary>
	/// ブロックがつながっているか判定
	/// </summary>
	/// <param name="_selectNum">選択した番号</param>
	/// <param name="_laneY">レーン縦位置</param>
	bool IsSelect(int _selectNum, int _laneY);

	/// <summary>
	/// 選択肢のブロックを割り当て
	/// </summary>
	/// <param name="_x"></param>
	/// <param name="_y"></param>
	/// <param name="selectNum"></param>
	/// <returns></returns>
	bool SelectBlocks(int _x, int _y, int selectNum);

private:

	int blockGraph_;

	std::map<SELECT_TYPE, std::array<std::array<bool, BLOCK_X>,BLOCK_Y>> blockShapes_;
	
	// 選択肢
	int select_[SELECT_NUM];

	/// <summary>
	/// ブロックを取得
	/// </summary>
	/// <param name="_x">X</param>
	/// <param name="_y">Y</param>
	/// <param name="_type">ブロックの形の種類</param>
	bool GetBlocks(int _x, int _y, SELECT_TYPE _type);


	void SetBlockShape(void);
};