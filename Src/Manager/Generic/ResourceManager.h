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
		TITLE_LOGO,
		TITLE_BUTTON,
		RETRY_BUTTON,
		SELECT_BUTTON,
		ARROW_RIGHT,
		PLAYER_BUTTON_1,
		PLAYER_BUTTON_2,
		PLAYER_BUTTON_3,
		PLAYER_BUTTON_4,
		STAGE_IMG,
		TIMER_BACK,
		NUMBERS,

		START_BLOCKS,
		BLOCK_BASES,
		SKY,

		//モデル
		STAGE_MDL,

		//音

		//BGM
		TITLE_BGM,

		//SE
		TIMER_SE,
		SELECT_SE,

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

