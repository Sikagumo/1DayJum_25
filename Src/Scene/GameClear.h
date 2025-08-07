#pragma once
#include "SceneBase.h"
class GameClear :
    public SceneBase
{
public:
    GameClear(void);
    ~GameClear(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;
};

