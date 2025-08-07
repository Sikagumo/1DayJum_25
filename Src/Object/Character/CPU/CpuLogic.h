#pragma once
#include "../SelectLogicBase.h"
class CpuLogic :
    public SelectLogicBase
{
public:
    void UpdateLogic(void)override;
};

