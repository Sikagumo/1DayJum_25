#include "../../Application.h"
#include "SceneManager.h"
#include "Resource.h"
#include "ResourceManager.h"
#include "Timer.h"

static Timer* instance_ = nullptr;

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

    //�J�E���^
    cnt_ += scnMng.GetDeltaTime();
}

void Timer::Draw(void)
{
    //�w�i�̕`��
    DrawRotaGraph(Application::SCREEN_SIZE_X / 2, TIMER_BACK_SIZE_Y, TIMER_BACK_RATE, 0.0, timerBackImg_, true);

    //�����̕`��
    //DrawRotaGraph(Application::SCREEN_SIZE_X / 2,)
}

void Timer::Destroy(void)
{
    //�C���X�^���X�̔j��
    delete instance_;
    instance_ = nullptr;
}

Timer::Timer(void)
{
    //�C���X�^���X
    auto& res = ResourceManager::GetInstance();

    //�ϐ�������
    time_ = { 0,0 };
    cnt_ = 0.0f;

    //�^�C�}�[�w�i
    timerBackImg_ = res.Load(ResourceManager::SRC::TIMER_BACK).handleId_;
    
    //�����摜
    numImgs_ = res.Load(ResourceManager::SRC::NUMBERS).handleIds_;
}

Timer::~Timer(void)
{
}
