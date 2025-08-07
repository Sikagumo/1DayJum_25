#include "../../Application.h"
#include "../Generic/SceneManager.h"
#include "../Generic/Resource.h"
#include "../Generic/ResourceManager.h"
#include "../Decoration/UIManager2d.h"
#include "Timer.h"

Timer* Timer::instance_ = nullptr;

void Timer::CreateInstance(void)
{
    //�C���X�^���X�̏�������
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
    //�C���X�^���X
    auto& scnMng = SceneManager::GetInstance();

    if (TIME_LIMIT.second - static_cast<int>(cnt_) > 0)
    {
        //�J�E���^
        cnt_ += scnMng.GetDeltaTime();
    }
}

void Timer::Draw(void)const
{
    //�C���X�^���X
    auto& res = ResourceManager::GetInstance();
    auto& ui = UIManager2d::GetInstance();

    //�w�i�̕`��
    ui.Draw("TimerBack");

    //�����̐ݒ�
    ui.SetUIInfo("Numbers"
        , VGet(Application::SCREEN_SIZE_X / 2 + ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE, TIMER_BACK_SIZE_Y / 2,0.0f)
        , NUMBERS_RATE);
    ui.SetImage("Numbers", res.Load(ResourceManager::SRC::NUMBERS).handleIds_[(TIME_LIMIT.second - static_cast<int>(cnt_)) % (ResourceManager::NUMBERS_NUM_X * ResourceManager::NUMBERS_NUM_Y)]);

    //�����̕`��
    ui.Draw("Numbers");

    //�����̐ݒ�
    ui.SetUIInfo("Numbers"
        , VGet(Application::SCREEN_SIZE_X / 2 - ResourceManager::NUMBERS_SIZE / 2 * NUMBERS_RATE, TIMER_BACK_SIZE_Y / 2,0.0f)
        , NUMBERS_RATE);
    ui.SetImage("Numbers", res.Load(ResourceManager::SRC::NUMBERS).handleIds_[(TIME_LIMIT.second - static_cast<int>(cnt_)) / (ResourceManager::NUMBERS_NUM_X * ResourceManager::NUMBERS_NUM_Y)]);

    //�����̕`��
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
    //�C���X�^���X�̔j��
    delete instance_;
    instance_ = nullptr;
}

const bool Timer::IsOverLimit(void) const
{
    return TIME_LIMIT.second - static_cast<int>(cnt_) <= 0;
}

Timer::Timer(void)
{
    //�C���X�^���X
    auto& res = ResourceManager::GetInstance();
    auto& ui = UIManager2d::GetInstance();

    //�ϐ�������
    time_ = { 0,0 };
    cnt_ = 0.0f;

    //�^�C�}�[�w�i
    ui.Add("TimerBack"
        , res.Load(ResourceManager::SRC::TIMER_BACK).handleId_
        , UIManager2d::UI_DIRECTION_2D::NOMAL
        , UIManager2d::UI_DRAW_DIMENSION::DIMENSION_2);

    ui.SetUIInfo("TimerBack"
        , VGet(Application::SCREEN_SIZE_X / 2, TIMER_BACK_SIZE_Y / 2, 0.0f)
        , TIMER_BACK_RATE);
    
    //�����摜
    ui.Add("Numbers"
        , -1
        , UIManager2d::UI_DIRECTION_2D::NOMAL
        , UIManager2d::UI_DRAW_DIMENSION::DIMENSION_2);
}

Timer::~Timer(void)
{
}
