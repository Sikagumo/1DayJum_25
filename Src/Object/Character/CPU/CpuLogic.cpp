#include<DxLib.h>
#include "CpuLogic.h"

void CpuLogic::UpdateLogic(void)
{
	//�I�����������Ă��Ȃ��Ƃ�
	if (!isSelect_) {
		isSelect_ = true;

		//�S�ʂ肩�烉���_��
		selectNum_ = static_cast<int>(GetRand(static_cast<int>(SELECT_TYPE::DOWN)));
	}
}
