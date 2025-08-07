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
	static constexpr float TIMER_BACK_RATE = 1.5f;
	static constexpr int TIMER_BACK_SIZE_X = static_cast<int>(128 * TIMER_BACK_RATE);
	static constexpr int TIMER_BACK_SIZE_Y = static_cast <int>(64 * TIMER_BACK_RATE);

	//数字描画数
	static constexpr int NUM_CNT = 2;

	//数字のサイズ
	static constexpr float NUMBERS_RATE = 0.4f;

	static constexpr int NUMBERS_LOCAL_POS_X = 30;

	//インスタンスの生成
	static void CreateInstance(void);
	
	//インスタンスの取得
	static Timer& GetInstance(void);

	//更新
	void Update(void);
	
	//描画
	void Draw(void)const;

	//インスタンスの削除
	void Destroy(void);

	//制限時間を超えたか
	const bool IsOverLimit(void)const;

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
};

