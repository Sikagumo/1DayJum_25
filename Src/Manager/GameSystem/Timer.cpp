#include "../../Application.h"
#include "../Generic/SceneManager.h"
#include "../Generic/Resource.h"
#include "../Generic/ResourceManager.h"
#include "Timer.h"

Timer* Timer::instance_ = nullptr;

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

    if (TIME_LIMIT.second - static_cast<int>(cnt_) > 0)
    {
        //カウンタ
        cnt_ += scnMng.GetDeltaTime();
    }
}

void Timer::Draw(void)const
{
    //背景の描画
    DrawRotaGraph(Application::SCREEN_SIZE_X / 2, TIMER_BACK_SIZE_Y, TIMER_BACK_RATE, 0.0, timerBackImg_, true);

    //数字の描画
    DrawRotaGraph(
        Application::SCREEN_SIZE_X / 2 + ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE
        , TIMER_BACK_SIZE_Y
        , NUMBERS_RATE
        , 0.0
        , numImgs_[(TIME_LIMIT.second - static_cast<int>(cnt_)) % 10]
        , true);

    DrawRotaGraph(
        Application::SCREEN_SIZE_X / 2 - ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE
        , TIMER_BACK_SIZE_Y
        , NUMBERS_RATE
        , 0.0
        , numImgs_[(TIME_LIMIT.second - static_cast<int>(cnt_)) / 10]
        , true);
}

void Timer::Destroy(void)
{
    //インスタンスの破棄
    delete instance_;
    instance_ = nullptr;
}

const bool Timer::IsOverLimit(void) const
{
    return TIME_LIMIT.second - static_cast<int>(cnt_) <= 0;
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
