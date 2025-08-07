#include "../../Application.h"
#include "SceneManager.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "Timer.h"

static Timer* instance_ = nullptr;

void Timer::CreateInstance(void)
{
    //インスタンスの初期生成
    if (instance_ == nullptr)
    {
        instance_ = new Timer();
    }
}

Timer& Timer::GetInstance(void)
{
    return *instance_;
}

void Timer::Update(void)
{
    //インスタンス
    auto& scnMng = SceneManager::GetInstance();

    //カウンタ
    cnt_ += scnMng.GetDeltaTime();
}

void Timer::Draw(void)
{
    //背景の描画
    DrawRotaGraph(Application::SCREEN_SIZE_X / 2, TIMER_BACK_SIZE_Y, TIMER_BACK_RATE, 0.0, timerBackImg_, true);

    //数字の描画
    //DrawRotaGraph(Application::SCREEN_SIZE_X / 2,)
}

void Timer::Destroy(void)
{
    //インスタンスの破棄
    delete instance_;
    instance_ = nullptr;
}

Timer::Timer(void)
{
    //インスタンス
    auto& res = ResourceManager::GetInstance();

    //変数初期化
    time_ = { 0,0 };
    cnt_ = 0.0f;

    //タイマー背景
    timerBackImg_ = res.Load(ResourceManager::SRC::TIMER_BACK).handleId_;
    
    //数字画像
    numImgs_ = res.Load(ResourceManager::SRC::NUMBERS).handleIds_;
}

Timer::~Timer(void)
{
}
