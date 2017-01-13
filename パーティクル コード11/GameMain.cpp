// #include "Extension\DirectX11\DXGraphics11.hpp"
#include "StdAfx.h"
#include "GameMain.h"

/// <summary>
/// Allows the game to perform any initialization it needs to before starting to run.
/// This is where it can query for any required services and load all of your content.
/// Initialize will enumerate through any components and initialize them as well.
/// </summary>
bool GameMain::Initialize()
{
	// TODO: Add your initialization logic here
	WindowTitle(_T("ES Game Library"));

	v[0].x = 0.0f;
	v[0].y = 0.0f;
	v[0].z = 0.0f;
	v[0].color = Color(255, 0, 0);

	Viewport view = GraphicsDevice.GetViewport();

	//カメラ設定
	camera_->SetLookAt(Vector3(0.0, 0.0, -5.0),	//座標
					   Vector3(0.0, 0.0, 0.0),	//注視点
					   Vector3_Up);				//上方ベクトル

	camera_->SetPerspectiveFieldOfView(45.0f, (float)view.Width, (float)view.Height, 1.0f, 1000.0f);
	GraphicsDevice.SetCamera(camera_);

	return true;
}

/// <summary>
/// Finalize will be called once per game and is the place to release
/// all resource.
/// </summary>
void GameMain::Finalize()
{
	// TODO: Add your finalization logic here

}

/// <summary>
/// Allows the game to run logic such as updating the world,
/// checking for collisions, gathering input, and playing audio.
/// </summary>
/// <returns>
/// Scene continued value.
/// </returns>
int GameMain::Update()
{
	// TODO: Add your update logic here


	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_Blue);

	GraphicsDevice.BeginScene();

	GraphicsDevice.SetRenderState(Lighting_Disable);
	GraphicsDevice.DrawUserPrimitives(PrimitiveType_PointList, v, 1, v[0].FVF());
	GraphicsDevice.SetRenderState(Lighting_Enable);

	SpriteBatch.Begin();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
