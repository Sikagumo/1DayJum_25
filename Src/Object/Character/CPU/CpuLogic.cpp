#include<DxLib.h>
#include "CpuLogic.h"

void CpuLogic::UpdateLogic(void)
{
	//‘I‘ð‚ªŠ®—¹‚µ‚Ä‚¢‚È‚¢‚Æ‚«
	if (!isSelect_) {
		isSelect_ = true;

		//‘S’Ê‚è‚©‚çƒ‰ƒ“ƒ_ƒ€
		selectNum_ = static_cast<int>(GetRand(static_cast<int>(SELECT_TYPE::DOWN)));
	}
}
