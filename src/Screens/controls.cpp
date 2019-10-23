#include "controls.h"

#include "raylib.h"

#include "menu.h"

namespace Arkanoid
{
	bool controls = false;

	void DrawControls()
	{
		DrawText("Select color using <- Or -> arrows", 230, 90, 20, RAYWHITE);
		DrawText("Contorls: Pause: \"P\" ", 295, 120, 20, RAYWHITE);
		DrawText("Movement: <- Or -> arrows ", 270, 150, 20, RAYWHITE);
		if (IsKeyPressed(KEY_ENTER))
		{
			menu = !menu;
			controls = !controls;
		}
	}
	

}
