#ifndef WAVE_FUNCTIONS
#define WAVE_FUNCTIONS
#include "raylib.h"
#include <math.h>
struct WAVE
{
	double amplitude;
	double frequency;
	double offset;
};

struct PILEDWAVE
{
	struct WAVE *waves;
	int NR_Waves;
};

void DrawWave(struct WAVE wave, int posY);
void DrawPlannedWave(int *points, int posY);
void PlanWave(struct WAVE wave, int *points);
void DrawPiledWave(struct PILEDWAVE PiledWave, int posY);
#endif