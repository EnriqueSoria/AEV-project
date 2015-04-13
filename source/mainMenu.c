#include <nds.h>
#include <stdio.h>

// git outputs a nice header to reference data
#include "menu.h"
#include "portada.h"

/*
	Load the main menu and it will be loaded until the user press start
*/
void loadMenu(void) {
	
	touchPosition touch1;

	PrintConsole bottomScreen1;
	
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_5_2D);

	vramSetBankB(VRAM_B_MAIN_BG);
	vramSetBankH(VRAM_H_SUB_BG);

	consoleInit(&bottomScreen1, 3, BgType_Bmp16, BgSize_B16_256x256, 0, 0, false, false);

	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0,0);
	decompress(portadaBitmap, BG_GFX, LZ77Vram);
	
	consoleSelect(&bottomScreen1);
	decompress(menuBitmap, BG_GFX_SUB,  LZ77Vram);
	
	while(1) {
	
		swiWaitForVBlank();
		scanKeys();
		
		touchRead(&touch1);

		if((touch1.px >= 16 && touch1.px <= 240) && (touch1.py >= 72 && touch1.py <= 116))
			break;
	}
}