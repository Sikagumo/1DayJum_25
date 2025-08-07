#pragma once
#include <chrono>
#include<vector>
#include<memory>
#include <DxLib.h>
class SceneBase;
class Fader;
class Camera;

//定義
//シーン遷移::メインシーンの切り換え
//シーン移動::サブシーンとの移動のやり取り

class SceneManager
{

public:
	static constexpr VECTOR LIGHT_DIR = { 0.00f, -1.00f, 1.00f };
	static constexpr float STICK_START_POW = 0.5f;	//コントローラーのスティック閾値

	static constexpr int POP_SCENE_TYPE_NUM = 1;	//ポップ可能なシーンの種類数

	// シーン管理用
	enum class SCENE_ID
	{
		NONE,
		TITLE,
		GAME,
		CLEAR,

		//ポップ可能シーン
		PAUSE,
	};

	enum class CNTL
	{
		NONE,
		KEY,
		PAD,
	};
	
	// インスタンスの生成
	static void CreateInstance(void);

	// インスタンスの取得
	static SceneManager& GetInstance(void);

	void Init(void);
	void Init3D(void);
	void Update(void);
	void Draw(void);

	// リソースの破棄
	void Destroy(void);

	void ChangeScene(std::shared_ptr<SceneBase>_scene);
	void PushScene(std::shared_ptr<SceneBase>_scene);
	void PopScene(void);
	void JumpScene(std::shared_ptr<SceneBase>_scene);

	// シーンIDの取得
	SCENE_ID GetSceneID(void);

	// デルタタイムの取得
	float GetDeltaTime(void) const;


	// カメラの取得
	Camera& GetCamera(void) const;

	//操作種別の取得・設定
	const CNTL GetController(void)const;
	void SetController(const CNTL _cntl);
	void SwitchController(void);	//切り換え


	int GetMainScreen(void)const { return mainScreen_; }
	const float GetTotalTime(void)const { return totalTime_; }

	//プレイヤー数
	void SetPlayerNum(int _num);
private:

	// 静的インスタンス
	static SceneManager* instance_;

	SCENE_ID sceneId_;
	SCENE_ID subSceneList_[POP_SCENE_TYPE_NUM];
	SCENE_ID waitSceneId_;
	CNTL cntl_;

	std::shared_ptr<Camera> camera_;

	// メインスクリーン
	int mainScreen_;

	// フェード
	Fader* fader_;

	// 各種シーン
	std::vector<std::shared_ptr<SceneBase>> scenes_;	//シーン格納

	// シーン遷移中判定
	bool isSceneChanging_;

	// デルタタイム
	std::chrono::system_clock::time_point preTime_;
	float deltaTime_;
	float totalTime_;

	//更新カウンターの倍率
	float updateSpeedRate_;

	//プレイヤー数
	int playerNum_;
	
	// デフォルトコンストラクタをprivateにして、
	// 外部から生成できない様にする
	SceneManager(void);
	// コピーコンストラクタも同様
	SceneManager(const SceneManager&);
	// デストラクタも同様
	~SceneManager(void) = default;

	// デルタタイムをリセットする
	void ResetDeltaTime(void);

	// フェード
	void Fade(void);
};