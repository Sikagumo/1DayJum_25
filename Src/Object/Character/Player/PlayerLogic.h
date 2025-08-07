#pragma once
#include "../SelectLogicBase.h"
class PlayerLogic :
    public SelectLogicBase
{
public:
    void UpdateLogic(void)override;

private:
    void UserInput(void);
};

