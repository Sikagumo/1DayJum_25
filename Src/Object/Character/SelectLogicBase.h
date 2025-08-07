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

	//��Ԏ擾
	const bool IsSelect(void)const;		//�I��������������
	const int GetSelectNum(void)const;	//�I�������ԍ�

	//�󋵂̃��Z�b�g
	void ResetSelect(void);

protected:
	bool isSelect_; //�I��������������
	int selectNum_; //�I�������ԍ�
};

