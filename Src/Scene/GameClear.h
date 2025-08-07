#pragma once
#include "SceneBase.h"
class GameClear :
    public SceneBase
{
public:

    enum class NEXT_SCENE
    {
        NONE,
        GAME,
        SELECT,
        TITLE,
    };
    GameClear(void);
    ~GameClear(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;

private:
    int next_;

    void ChangeNext();
    void ChangeScene();
};


//èáà 