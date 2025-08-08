#pragma once
#include "SceneBase.h"
#include"../Common/Vector2.h"

class Title :
    public SceneBase
{
public:
    static constexpr int LEN = 3;

    Title(void);
    ~Title(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;

private:
    int startBlockImg_;
    int backImg_;
    int blockBaseImg_;

    Vector2 drawPos_[LEN];
    Vector2 backDrawPos_[2];

    int titleLogo_;
    

};

