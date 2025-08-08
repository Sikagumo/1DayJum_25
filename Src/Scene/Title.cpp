#include<DxLib.h>

#include"../Application.h"
#include"../Manager/Generic/SceneManager.h"
#include"../Manager/Generic/InputManager.h"
#include"../Manager/Generic/ResourceManager.h"
#include"../Manager/Decoration/UIManager2d.h"

#include"Select.h"
#include "Title.h"

Title::Title(void)
{
}

Title::~Title(void)
{
}

void Title::Init(void)
{
	auto& uiM = UIManager2d::GetInstance();

	auto& resM = ResourceManager::GetInstance();
	resM.Init(SceneManager::SCENE_ID::TITLE);

	//画像のロード
	startBlockImg_ = resM.Load(ResourceManager::SRC::START_BLOCKS).handleId_;
	backImg_ = resM.Load(ResourceManager::SRC::SKY).handleId_;
	titleLogo_ = resM.Load(ResourceManager::SRC::TITLE_LOGO).handleId_;
	blockBaseImg_ = resM.Load(ResourceManager::SRC::BLOCK_BASES).handleId_;

	uiM.Add("タイトルロゴ", titleLogo_, UIManager2d::UI_DIRECTION_2D::ZOOM_INOUT, 
		UIManager2d::UI_DRAW_DIMENSION::DIMENSION_2);
	uiM.SetPos("タイトルロゴ", { Application::SCREEN_SIZE_X / 2,Application::SCREEN_SIZE_Y / 2,0 });
	uiM.SetUIDirectionPram("タイトルロゴ", UIManager2d::UI_DIRECTION_GROUP::ZOOM, 0.01, 1.2, 0.3);


	backDrawPos_[0] = { 0,0 };
	backDrawPos_[1] = { Application::SCREEN_SIZE_X,0 };
}

void Title::Update(void)
{
	auto& uiM = UIManager2d::GetInstance();
	uiM.Update("タイトルロゴ");

	//for (int i = 0; i < 2; i++)
	//{
	//	backDrawPos_[i].x -= 1;
	//	if (backDrawPos_[i].x < -Application::SCREEN_SIZE_X) {
	//		backDrawPos_[i].x = Application::SCREEN_SIZE_X;
	//	}
	//}

	//シーン遷移
	if (InputManager::GetInstance().IsTrigerrDown("action")) {
		SceneManager::GetInstance().JumpScene(std::make_shared<Select>());
	}
}

void Title::Draw(void)
{
	auto& uiM = UIManager2d::GetInstance();
	static int centerPosY = Application::SCREEN_SIZE_Y / 2;
	static int centerPosX = Application::SCREEN_SIZE_X / 2;

	DrawGraph(backDrawPos_[0].x, backDrawPos_[0].y, backImg_, true);
	DrawGraph(backDrawPos_[1].x, backDrawPos_[1].y, backImg_, true);
	drawPos_[0] = { 0,centerPosY - Application::SCREEN_SIZE_Y / 3 };
	drawPos_[1] = { 0,centerPosY };
	drawPos_[2] = { 0,centerPosY + Application::SCREEN_SIZE_Y / 3 };


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			DrawRotaGraph(j * 96, drawPos_[i].y, 1, 0, blockBaseImg_, true);
		}
	DrawRotaGraph(0, drawPos_[i].y, 1, 0, startBlockImg_, true);
	DrawRotaGraph(Application::SCREEN_SIZE_X, drawPos_[i].y, 1, 0, startBlockImg_, true);
	}




	uiM.Draw("タイトルロゴ");
	//DrawRotaGraph(centerPosX, centerPosY, 0.7, 0, titleLogo_, true);

	DrawString(0, 0, "TitleScene", 0xffffff, false);

}

void Title::Release(void)
{
}
