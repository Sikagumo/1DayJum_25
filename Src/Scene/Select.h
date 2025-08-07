#pragma once
#include "SceneBase.h"
class Select : public SceneBase
{
public:
    static constexpr int POS_X_LEFT = Application::SCREEN_SIZE_X / 3;
    static constexpr int POS_X_RIGHT = Application::SCREEN_SIZE_X / 3*2;
    static constexpr int POS_Y_UP = Application::SCREEN_SIZE_Y / 3;
    static constexpr int POS_Y_DOWN = Application::SCREEN_SIZE_Y / 3*2;

    Select(void);
    ~Select(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;

private:
    int playerNum_;

    int numImg1_;
    int numImg2_;
    int numImg3_;
    int numImg4_;

    void ChangePlayerNum();
};

