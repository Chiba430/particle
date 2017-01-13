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

	v[0].x = 100.0f;
	v[0].y = 100.0f;
	v[0].color = Color(0, 0, 255);

	x_add = 10.0f;
	y_add = 5.0f;

	date_x = 0;
	date_y = 0;

	GraphicsDevice.SetRenderStateF(PointSize, 10.0f);
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
	if (date_x == 0){
		v[0].x += x_add;
	}
	if (date_x == 1){
		v[0].x -= x_add;
	}
	if (date_y == 0){
		v[0].y += y_add;
	}
	if (date_y == 1){
		v[0].y -= y_add;
	}
	
	
	if (v[0].x >= 1280){
		date_x = 1;
	}
	if (v[0].x <= 0){
		date_x = 0;
	}
	if (v[0].y >= 720){
		date_y = 1;
	}
	if (v[0].y <= 0){
		date_y = 0;
	}
	
	return 0;
}

/// <summary>
/// This is called when the game should draw itself.
/// </summary>
void GameMain::Draw()
{
	// TODO: Add your drawing code here
	GraphicsDevice.Clear(Color_Black);

	GraphicsDevice.BeginScene();

	GraphicsDevice.DrawUserPrimitives(PrimitiveType_PointList, v, 1, v[0].FVF());

	SpriteBatch.Begin();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
