#include "raylib.h"
#include "wave_functions.h"
#include <math.h>
void PlanWave(struct WAVE wave, int *points)
{
	int i = 0;
	float j;
	for (i = 0; i < 800; ++i)
	{
		j = i;
		points[i] = (wave.amplitude) * sin(wave.frequency * j - wave.offset);
	}
}

void DrawPlannedWave(int *points, int posY)
{
	int i = 0;
	for (i = 0; i < 799; ++i)
	{
		DrawLine(i, points[i] + posY, i + 1, points[i + 1] + posY, BLACK);
	}
}
void DrawWave(struct WAVE wave, int posY)
{
	int points[800];
	PlanWave(wave, points);
	DrawPlannedWave(points, posY);
}

void DrawPiledWave(struct PILEDWAVE PiledWave, int posY)
{
	int planned_wave[800] = {0};
	int wave_buffer[800];
	int length = PiledWave.NR_Waves;
	int j = 0;
	for (int i = 0; i < length; ++i)
	{
		PlanWave(PiledWave.waves[i], wave_buffer);
		for (j = 0; j < 800; ++j)
		{
			planned_wave[j] += wave_buffer[j];
		}
	}
	for (j = 0; j < 800; ++j)
	{
		if (length == 0)
		{
			length += 1;
		}
		planned_wave[j] = planned_wave[j] / length;
	}

	DrawPlannedWave(planned_wave, posY);
}