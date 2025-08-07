#pragma once
class Timer
{
public:

	//時間
	struct Time
	{
		int minute;		//分
		int second;		//秒
	};

	//制限時間
	static constexpr Time TIME_LIMIT = { 0,10 };

	//タイマー背景サイズ
	static constexpr float TIMER_BACK_RATE = 0.8f;
	static constexpr int TIMER_BACK_SIZE_X = static_cast<int>(298 * TIMER_BACK_RATE);
	static constexpr int TIMER_BACK_SIZE_Y = static_cast <int>(168 * TIMER_BACK_RATE);

	//数字描画数
	static constexpr int NUM_CNT = 2;

	//インスタンスの生成
	static void CreateInstance(void);
	
	//インスタンスの取得
	static Timer& GetInstance(void);

	//更新
	void Update(void);
	
	//描画
	void Draw(void);

	//インスタンスの削除
	void Destroy(void);

private:

	//コンストラクタ
	Timer(void);

	//デストラクタ
	~Timer(void);

	//コピーの禁止
	Timer(Timer& _copy) = delete;
	Timer& operator=(Timer& _copy) = delete;

	//自身のインスタンス
	static Timer* instance_;

	//時間
	Time time_;

	//カウンタ
	float cnt_;

	//タイマー背景
	int timerBackImg_;

	//数字画像
	int* numImgs_;
};

