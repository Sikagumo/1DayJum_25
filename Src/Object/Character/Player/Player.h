#pragma once
#include "../UnitBase.h"
class Player :
    public UnitBase
{
public:
    void Init(const VECTOR& _pos)override;
};

