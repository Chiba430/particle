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

	v_x = 100.0f;
	v_y = 100.0f;
	i = 255;
	j = 0;
	a = 0;
	color = 0;
	WindowTitle(_T("ES Game Library"));
	
	v[0].x = 100.0f;
	v[0].y = 100.0f;
	v[0].color = Color(i, j, a);
	
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

	KeyboardState key_state;
	KeyboardBuffer key_buffer;

	key_buffer = Keyboard->GetBuffer();
	key_state = Keyboard->GetState();
	
//F•ÏX
	if (key_buffer.IsPressed(Keys_Enter)){
		if (color == 0){
			color = 1;
		}
		else if (color == 1){
			color = 2;
		}
		else if (color == 2){
			color = 0;
		}

	}

	if (color == 0){
		if (key_state.IsKeyDown(Keys_E)){

			v[0].color = Color(i, j, a);
			i += 1;
			if (i >= 255){
				i = 255;
			}
		}
		if (key_state.IsKeyDown(Keys_D)){

			v[0].color = Color(i, j, a);
			i -= 1;
			if (i <= 1){
				i = 1;
			}
		}
	}

	if (color == 1){
		if (key_state.IsKeyDown(Keys_E)){

			v[0].color = Color(i, j, a);
			j += 1;
			if (j >= 255){
				j = 255;
			}
		}
		if (key_state.IsKeyDown(Keys_D)){

			v[0].color = Color(i, j, a);
			j -= 1;
			if (j <= 1){
				j = 1;
			}
		}
	}
	
	if (color == 2){
		if (key_state.IsKeyDown(Keys_E)){

			v[0].color = Color(i, j, a);
			a += 1;
			if (a >= 255){
				a = 255;
			}
		}
		if (key_state.IsKeyDown(Keys_D)){

			v[0].color = Color(i, j, a);
			a -= 1;
			if (a <= 1){
				a = 1;
			}
		}
	}
	
//ˆÚ“®
	if (key_state.IsKeyDown(Keys_Right)){

		v[0].x += 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Left)){

		v[0].x -= 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Up)){

		v[0].y -= 1.0f;
	}
	if (key_state.IsKeyDown(Keys_Down)){

		v[0].y += 1.0f;
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
