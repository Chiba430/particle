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

	angle = 0.0f; //角度
	r = 0; //red
	g = 255; //grean
	b = 255; //bule
	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			v[j][i].x = 0.0f;
			v[j][i].y = 0.0f;
			v[j][i].color = Color(r, g, b);
			/*r -= 10;
			g += 10;
			b += 10;*/



			x_add[j][i] = 0.0f;
			y_add[j][i] = 0.0f;
			date_x[j][i] = 0;
			date_y[j][i] = 1;
			flag[j][i] = false;
			}
	}
	mood = 0;
	point = false;
	
	GraphicsDevice.SetRenderStateF(PointSize, 1.0f);

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

	KeyboardBuffer key_b = Keyboard->GetBuffer();

	//移動//

	int start = 0;
	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			if (flag[j][i] == true){
					v[j][i].x += x_add[j][i]; //移動量
					v[j][i].y += y_add[j][i]; //移動量

					if (v[j][i].x >= 1280.0f || v[j][i].x <= 0.0f || v[j][i].y <= 0.0f || v[j][i].y >= 720.0f){
						flag[j][i] = false;
					}

				}
			}
		}
	


	//中心//
	//if (key_b.IsPressed(Keys_Space)){
if (point == false){
	int   count = 0;
	//angle = 0.0f;
	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			if (flag[j][i] == false){
				flag[j][i] = true;

				v[j][i].x = 640.0f; //座標
				v[j][i].y = 360.0f; //座標

				x_add[j][i] = 5.0f * MathHelper_Cos(angle); //コサイン
				y_add[j][i] = 5.0f * MathHelper_Sin(angle); //サイン
				if (mood == 0){
					angle += 1.0f;
				}
				if (mood == 1){
					angle -= 1.0f;
				}
				count++;
				if (count >= 1) {
					j = kazu;
					i = max;
					point = true;
				}
				
					if (angle >= 1.0f){
						point = false;
						angle -= 0.5f;
					}
				
				

				if (angle >= 50.0f){
					mood = 1;
				}
				if (angle <= 0.0f){
					mood = 0;
				}

			}
		}
	}
}
	//}
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

	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			GraphicsDevice.DrawUserPrimitives(PrimitiveType_PointList, v, kazu*max, v[j][i].FVF());
		}
	}

	SpriteBatch.Begin();


	SpriteBatch.End();

	GraphicsDevice.EndScene();
}
