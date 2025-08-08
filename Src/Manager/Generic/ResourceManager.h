#pragma once
#include <map>
#include <string>
#include "Resource.h"
#include"SceneManager.h"

class ResourceManager
{

public:

	//数字画像用定数
	static constexpr int NUMBERS_NUM_X = 5;
	static constexpr int NUMBERS_NUM_Y = 2;
	static constexpr int NUMBERS_SIZE = 128;

	// リソース名
	enum class SRC
	{
		//画像
		TITLE_LOGO,			//タイトルロゴ
		TITLE_BUTTON,		//タイトルボタン
		RETRY_BUTTON,		//リトライボタン
		SELECT_BUTTON,		//セレクトボタン
		ARROW_RIGHT,		//右矢印
		PLAYER_BUTTON_1,	//人数選択1人
		PLAYER_BUTTON_2,	//人数選択2人
		PLAYER_BUTTON_3,	//人数選択3人
		PLAYER_BUTTON_4,	//人数選択4人
		TIMER_BACK,			//タイマー背景
		NUMBERS,			//数字
		PASS_CONTROLLER,	//コントローラー渡し
		RANK_FIRST,			//1位
		RANK_SECOND,		//2位
		RANK_THIRD,			//3位
		RANK_FOURTH,		//4位
		START_IMG,			//スタート画像
		FINISH_IMG,			//終了画像
		WIN_IMG,			//勝利画像
		START_BLOCK,		//スタートブロック
		LAVA_BLOCK,			//溶岩ブロック
		STONE_BLOCK,		//石ブロック
		BUTTON_UP,			//上ボタン
		BUTTON_RIGHT,		//右ボタン
		BUTTON_DOWN,		//下ボタン
		BUTTON_LEFT,		//左ボタン
		BACK_LAVA,			//溶岩背景
		BACK_SKY,			//空背景

		PLAYER_ONE,
		PLAYER_TWO,
		PLAYER_THREE,
		PLAYER_FOUR,


		//モデル
		STAGE_MDL,

		//音

		//BGM
		TITLE_BGM,

		//SE
		TIMER_SE,

		//エフェクト
	};

	// 明示的にインステンスを生成する
	static void CreateInstance(void);

	// 静的インスタンスの取得
	static ResourceManager& GetInstance(void);

	// 初期化
	void Init(SceneManager::SCENE_ID _scene= SceneManager::SCENE_ID::NONE);

	
private:
	//シーンごとにデータを読み込むことにする
	void InitTitle(void);
	void InitGame(void);
	void InitClear(void);
	void InitSelect(void);

public:
	// 解放(シーン切替時に一旦解放)
	void Release(void);

	// リソースの完全破棄
	void Destroy(void);

	// リソースのロード
	Resource Load(SRC src);

	// リソースの複製ロード(モデル用)
	int LoadModelDuplicate(SRC src);

private:

	// 静的インスタンス
	static ResourceManager* instance_;

	// リソース管理の対象
	std::map<SRC, Resource> resourcesMap_;

	// 読み込み済みリソース
	std::map<SRC, Resource*> loadedMap_;

	// デフォルトコンストラクタをprivateにして、
	// 外部から生成できない様にする
	ResourceManager(void);

	// デストラクタも同様
	~ResourceManager(void) = default;

	// 内部ロード
	Resource* _Load(SRC src);

};

