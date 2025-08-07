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
    void UpdateStartTurnFaze(void); //�^�[���J�n���̍X�V
    void UpdateSelectFaze(void);    //�I�𒆂̍X�V
    void UpdateMoveFaze(void);      //�I���𔽉f����X�V

    using Update_f = void(Game::*)(void);

    Update_f update_;                                   //�X�V���Ǘ�����֐��|�C���^
    std::unique_ptr<CharacterManager>charaMng_;         //�L�����N�^�[�̃}�l�[�W��
    std::unique_ptr<BlockController> blockController_;  //�u���b�N
};

