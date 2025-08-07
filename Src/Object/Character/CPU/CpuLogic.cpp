#include "CpuLogic.h"

void CpuLogic::UpdateLogic(void)
{
	isSelect_ = true;
	selectNum_ = static_cast<int>(SELECT_TYPE::TOP);
}
