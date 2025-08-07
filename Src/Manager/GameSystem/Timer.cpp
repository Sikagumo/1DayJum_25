#include "../../Application.h"
#include "../Generic/SceneManager.h"
#include "../Generic/Resource.h"
#include "../Generic/ResourceManager.h"
#include "../Decoration/UIManager2d.h"
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
    //インスタンス
    auto& res = ResourceManager::GetInstance();
    auto& ui = UIManager2d::GetInstance();

    //背景の描画
    ui.Draw("TimerBack");

    //数字の設定
    ui.SetUIInfo("Numbers"
        , VGet(Application::SCREEN_SIZE_X / 2 + ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE, TIMER_BACK_SIZE_Y / 2,0.0f)
        , NUMBERS_RATE);
    ui.SetImage("Numbers", res.Load(ResourceManager::SRC::NUMBERS).handleIds_[(TIME_LIMIT.second - static_cast<int>(cnt_)) % (ResourceManager::NUMBERS_NUM_X * ResourceManager::NUMBERS_NUM_Y)]);

    //数字の描画
    ui.Draw("Numbers");

    //数字の設定
    ui.SetUIInfo("Numbers"
        , VGet(Application::SCREEN_SIZE_X / 2 - ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE, TIMER_BACK_SIZE_Y / 2,0.0f)
        , NUMBERS_RATE);
    ui.SetImage("Numbers", res.Load(ResourceManager::SRC::NUMBERS).handleIds_[(TIME_LIMIT.second - static_cast<int>(cnt_)) / (ResourceManager::NUMBERS_NUM_X * ResourceManager::NUMBERS_NUM_Y)]);

    //数字の描画
    ui.Draw("Numbers");

    //DrawRotaGraph(
    //    Application::SCREEN_SIZE_X / 2 - ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE
    //    , TIMER_BACK_SIZE_Y
    //    , NUMBERS_RATE
    //    , 0.0
    //    , numImgs_[(TIME_LIMIT.second - static_cast<int>(cnt_)) / ResourceManager::NUMBERS_NUM_X * ResourceManager::NUMBERS_NUM_Y]
    //    , true);
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
    auto& ui = UIManager2d::GetInstance();

    //変数初期化
    time_ = { 0,0 };
    cnt_ = 0.0f;

    //タイマー背景
    ui.Add("TimerBack"
        , res.Load(ResourceManager::SRC::TIMER_BACK).handleId_
        , UIManager2d::UI_DIRECTION_2D::NOMAL
        , UIManager2d::UI_DRAW_DIMENSION::DIMENSION_2);

    ui.SetUIInfo("TimerBack"
        , VGet(Application::SCREEN_SIZE_X / 2, TIMER_BACK_SIZE_Y / 2, 0.0f)
        , TIMER_BACK_RATE);
    
    //数字画像
    ui.Add("Numbers"
        , -1
        , UIManager2d::UI_DIRECTION_2D::NOMAL
        , UIManager2d::UI_DRAW_DIMENSION::DIMENSION_2);
}

Timer::~Timer(void)
{
}
