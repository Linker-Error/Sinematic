#include <math.h>
#include <stdlib.h>
#include "raylib.h"
#include "wave_functions.h"
#include <string.h>
#include <stdio.h>


#include "icon.h"
#include "IntroFont.h"

void intro(Texture2D iconTexture)
{
	Font introFont = LoadFont_IntroFont();
	bool introOver = false;
	Vector2 ImagePos = { 350, 175 };
	int introTicks = 0;
	Color GreenFaded = { 0, 0, 255, 85 };
	Color RedFaded = { 0, 255, 0, 85 };
	Color BlueFaded = { 255, 0, 0, 85 };
	Color PurpleAgain = PURPLE;
	Color BackGroundColor = BLACK;
	Color IconTint = WHITE;
	PurpleAgain.a = 0;
	while (!introOver)
	{
		BeginDrawing();
		ClearBackground(BackGroundColor);
		if (introTicks < 200)
		{
			DrawTextureEx(iconTexture, ImagePos, 0, 0.1, GreenFaded);
			ImagePos.x = 250 + introTicks / 2;
			DrawTextureEx(iconTexture, ImagePos, 0, 0.1, RedFaded);
			ImagePos.x = 450 - introTicks / 2;
			DrawTextureEx(iconTexture, ImagePos, 0, 0.1, BlueFaded);
			ImagePos.x = 350;
		}
		else
		{
			DrawTextureEx(iconTexture, ImagePos, 0, 0.1, IconTint);
		}

		if (introTicks >= 250)
		{
			
			if (PurpleAgain.a < 255) { PurpleAgain.a = introTicks - 250; }

			ImagePos.y = 290;
			ImagePos.x = 340;
			DrawTextEx(introFont, "Sinematic", ImagePos, 24, 1, PurpleAgain);
			ImagePos.x = 350;
			ImagePos.y = 175;
			
		}

		if (introTicks >= 600)
		{
			BackGroundColor.r += 1;
			BackGroundColor.g += 1;
			BackGroundColor.b += 1;
			IconTint.a -= 1;
			PurpleAgain.a -= 1;
		}

		if (introTicks == 855)
		{
			introOver = true;
		}

		EndDrawing();
		introTicks += 1;
	}
}

int main(void)
{
	
	char ModeText[50] = "Current Mode = Default";
	int WavePosition = 225;
	int Mode = 0;
	bool panic_quit = false;
	
	Image icon = { 0 };

	struct WAVE CurrentWave = {50, 0.1, 0};
	struct PILEDWAVE CurrentPiledWave;
	struct WAVE *PanicWaveBuffer;


	CurrentPiledWave.NR_Waves = 0;
	CurrentPiledWave.waves = malloc(sizeof(CurrentWave));



	InitWindow(800, 450, "Sinematic");

	


	icon.format = ICON_FORMAT;
	icon.height = ICON_HEIGHT;
	icon.width = ICON_WIDTH;
	icon.data = ICON_DATA;
	icon.mipmaps = 1;

	SetWindowIcon(icon);
	bool userinput = true;
	SetTargetFPS(300);
	Texture2D iconTexture = LoadTextureFromImage(icon);

	intro(iconTexture);


	while (!(WindowShouldClose() && GetKeyPressed() != KEY_ESCAPE) && panic_quit == false)
	{
		
		//User Input Code
		if (userinput)
		{
			CurrentWave.amplitude = (WavePosition - GetMouseY());
			CurrentWave.offset = ((GetMouseX()) / 10);
			CurrentWave.frequency -= GetMouseWheelMove() / 10;
			//Code to change the editing mode
			switch (GetKeyPressed())
			{
			case 'D':
				Mode = 0;
				strcpy(ModeText, "Current Mode = Default");
				WavePosition = 225;
				CurrentPiledWave.NR_Waves = 0;
				break;
			case 'P':
				Mode = 1;
				strcpy(ModeText, "Current Mode = Piled Wave");
				WavePosition = 150;
				break;
			default:
				break;
			}
			//Code for Piled Wave mode
			if (Mode == 1)
			{
				if (IsMouseButtonPressed(0) || IsMouseButtonDown(1))
				{
					CurrentPiledWave.NR_Waves += 1;
					PanicWaveBuffer = realloc(CurrentPiledWave.waves, CurrentPiledWave.NR_Waves * sizeof(CurrentWave));
					if (PanicWaveBuffer == NULL)
					{
						printf("Panicked");
						panic_quit = true;
					}

					CurrentPiledWave.waves = PanicWaveBuffer;
					PanicWaveBuffer = NULL;
					CurrentPiledWave.waves[CurrentPiledWave.NR_Waves - 1] = CurrentWave;
				}
			}

		}
		//Drawing Process 
		BeginDrawing();
			HideCursor();
			ClearBackground(RAYWHITE);
			DrawWave(CurrentWave, WavePosition);
			DrawText(ModeText, 10, 10, 24, LIGHTGRAY);
			if (Mode == 1) {DrawPiledWave(CurrentPiledWave, 300);}
			DrawFPS(715, 0);
		EndDrawing();

	}

	//Wrap Up
	free(CurrentPiledWave.waves);
	CloseWindow();
	return 0;
}
