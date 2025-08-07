#pragma once
#include "SceneBase.h"
class Title :
    public SceneBase
{
public:
    Title(void);
    ~Title(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;
};

