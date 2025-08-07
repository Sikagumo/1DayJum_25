#pragma once
#include "SceneBase.h"
class Game :
    public SceneBase
{
public:
    Game(void);
    ~Game(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;
};

