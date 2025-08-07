#pragma once
#include "../CharacterBase.h"
class CpuCharacter :
    public CharacterBase
{
public:
    void SetPram(void)override;
    void Update(void)override;
};

