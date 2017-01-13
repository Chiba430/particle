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

	for (int i = 0; i < max; i++){

		v[i].x = 100.0f;
		v[i].y = 100.0f;
		v[i].color = Color(0, 0, 255);
		date_x[i] = 0;
		date_y[i] = 0;
		x_add[i] = 10.0f;
		y_add[i] = 5.0f;
	}

	GraphicsDevice.SetRenderStateF(PointSize, 5.0f);

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
	
	for (int i = 0; i < max; i++){

		if (date_x[i] == 0){
			v[i].x += x_add[i] * i;
		}
		if (date_x[i] == 1){
			v[i].x -= x_add[i] * i;
		}
		if (date_y[i] == 0){
			v[i].y += y_add[i] * i;
		}
		if (date_y[i] == 1){
			v[i].y -= y_add[i] * i;
		}

		if (v[i].x >= 1280){
			date_x[i] = 1;
		}
		if (v[i].x <= 0){
			date_x[i] = 0;
		}
		if (v[i].y >= 720){
			date_y[i] = 1;
		}
		if (v[i].y <= 0){
			date_y[i] = 0;
		}

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

	for (int i = 0; i < max; i++){
	GraphicsDevice.DrawUserPrimitives(PrimitiveType_PointList, v, 100, v[i].FVF());
	}

	SpriteBatch.Begin();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
