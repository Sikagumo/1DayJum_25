#pragma once
class SelectLogicBase
{
public:
	enum class SELECT_TYPE {
		TOP
		, RIGHT
		, LEFT
		, DOWN
	};

	SelectLogicBase(void);
	virtual ~SelectLogicBase(void);

	virtual void UpdateLogic(void) = 0;

	//状態取得
	const bool IsSelect(void)const;		//選択が完了したか
	const int GetSelectNum(void)const;	//選択した番号

	//状況のリセット
	void ResetSelect(void);

protected:
	bool isSelect_; //選択が完了したか
	int selectNum_; //選択した番号
};

