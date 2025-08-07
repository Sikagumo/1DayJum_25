#pragma once
#include "../CharacterBase.h"
class PlayerCharacter :
    public CharacterBase
{
public:
    void SetPram(void)override;
    void Update(void)override;

private:
};

