#pragma once
#include "SceneBase.h"
class Select : public SceneBase
{
public:
    Select(void);
    ~Select(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;

private:
    int playerNum_;
    void ChangePlayerNum();
};

