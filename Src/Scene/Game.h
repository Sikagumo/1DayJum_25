#pragma once
#include "SceneBase.h"
#include<memory>

class CharacterManager;
class BlockController;

class Game :
    public SceneBase
{
public:
    Game(void);
    ~Game(void)override;

    void Init(void)override;
    void Update(void)override;
    void Draw(void)override;
    void Release(void)override;

private:
    void UpdateStartTurnFaze(void); //ターン開始時の更新
    void UpdateSelectFaze(void);    //選択中の更新
    void UpdateMoveFaze(void);      //選択を反映する更新

    using Update_f = void(Game::*)(void);

    Update_f update_;                                   //更新を管理する関数ポインタ
    std::unique_ptr<CharacterManager>charaMng_;         //キャラクターのマネージャ
    std::unique_ptr<BlockController> blockController_;  //ブロック
};

