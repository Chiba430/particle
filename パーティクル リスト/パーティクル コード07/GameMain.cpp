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

	angle = 0.0f; //�p�x
	r = 255; //red
	g = 0; //grean
	b = 0; //bule
	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			v[j][i].x = 0.0f;
			v[j][i].y = 0.0f;
			v[j][i].color = Color(r, g, b);
			r -= 10;
			g += 10;
			b += 10;

			date_x[j][i] = 0;
			date_y[j][i] = 1;
			x_add[j][i] = 5.0f * MathHelper_Cos(angle); //�R�T�C��
			y_add[j][i] = 5.0f * MathHelper_Sin(angle); //�T�C��
			angle += 7.2f; //�p�x�̈ړ���
			flag[j][i] = false;

		}
	}
	
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






	//�ړ�//
	for (int j = 0; j < kazu; j++){
		for (int i = 0; i < max; i++){
			if (flag[j][i] == true){

				v[j][i].x += x_add[j][i]; //�ړ���

				v[j][i].y += y_add[j][i]; //�ړ���

				if (v[j][i].x >= 1280.0f || v[j][i].x <= 0.0f || v[j][i].y <= 0.0f || v[j][i].y >= 720.0f){
					flag[j][i] = false;
				}
			}
		}
	}


	//���S//
	if (key_b.IsPressed(Keys_Space)){
		int   count = 0;
		for (int j = 0; j < kazu; j++){
			for (int i = 0; i < max; i++){
				if (flag[j][i] == false){
					flag[j][i] = true;

					v[j][i].x = 640.0f; //���W
					v[j][i].y = 360.0f; //���W

					count++;
					if (count >= max) {
						j = kazu;
						i = max;
					}

					if (angle >= 360.0f){
						angle -= 360.0f;
					}
				}
			}
		}
	}

/*
	if (key_b.IsPressed(Keys_Space)){
		for (int j = 0; j < kazu; j++){
			for (int i = 0; i < max; i++){
				if (flag[j][i] != false){
					flag[j + 1][i] = false;
				}
			}
		}
	}
*/
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
