#pragma once
class Timer
{
public:

	struct Time
	{
		int second;
		int minute;
	};

	//インスタンスの生成
	static void CreateInstance(void);
	
	//インスタンスの取得
	static Timer& GetInstance(void);

private:

	//コンストラクタ
	Timer(void);

	//デストラクタ
	~Timer(void);

	//コピーの禁止
	Timer(Timer& _copy) = delete;
	Timer& operator=(Timer& _copy) = delete;

	Time time_;
};

