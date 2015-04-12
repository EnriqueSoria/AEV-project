/*
	Salvador Llobet, Ignacio
*/

#include <nds.h>
#include <stdio.h>

int teclaA = 0;
int teclaB = 0;
int teclaX = 0;
int teclaY = 0;
int teclaL = 0;
int teclaR = 0;
int teclaStart = 0;
int teclaSelect = 0;
int teclaUp = 0;
int teclaDown = 0;
int teclaLeft = 0;
int teclaRight = 0;
int pantallaC = 0;
int pantallaA = 0;

void logica()
{
	scanKeys();
	
	if(keysHeld())
		iprintf("\x1b[3;1HAlgun boton esta pulsado	\n");
	else
		iprintf("\x1b[3;1HNingun boton esta pulsado\n");
		
	if(KEY_A & keysDownRepeat()) teclaA++;
	if(KEY_B & keysDownRepeat()) teclaB++;
	if(KEY_X & keysDownRepeat()) teclaX++;
	if(KEY_Y & keysDownRepeat()) teclaY++;
	
	if(KEY_UP & keysDownRepeat()) teclaUp++;
	if(KEY_DOWN & keysDownRepeat()) teclaDown++;
	if(KEY_LEFT & keysDownRepeat()) teclaLeft++;
	if(KEY_RIGHT & keysDownRepeat()) teclaRight++;
	
	if(KEY_START & keysDownRepeat()) teclaStart++;
	if(KEY_SELECT & keysDownRepeat()) teclaSelect++;
	
	if(KEY_LID & keysDown()) pantallaC++;
	if(KEY_LID & keysUp()) pantallaA++;
	
	if(KEY_L & keysUp()) teclaL++;
	if(KEY_R & keysUp()) teclaR++;
	
	if(KEY_TOUCH & keysHeld())
	{
		touchPosition touch = touchReadXY();
		iprintf("\x1b[1;1HTactil X %d, Y %d\n ",touch.px, touch.py);
	}
	
	iprintf("\x1b[4;1HEl boton A se ha pulsado %d\n",teclaA);
	iprintf("\x1b[5;1HEl boton B se ha pulsado %d\n",teclaB);
	iprintf("\x1b[6;1HEl boton X se ha pulsado %d\n",teclaX);
	iprintf("\x1b[7;1HEl boton Y se ha pulsado %d\n",teclaY);
	
	iprintf("\x1b[8;1HEl boton Up se ha pulsado %d\n",teclaUp);
	iprintf("\x1b[9;1HEl boton Down se ha pulsado %d\n",teclaDown);
	iprintf("\x1b[10;1HEl boton Left se ha pulsado %d\n",teclaLeft);
	iprintf("\x1b[11;1HEl boton Right se ha pulsado %d\n",teclaRight);
	
	iprintf("\x1b[12;1HEl boton Start se ha pulsado %d\n",teclaStart);
	iprintf("\x1b[13;1HEl boton Select se ha pulsado %d\n",teclaSelect);
	
	iprintf("\x1b[14;1HEl boton L se ha levantado %d\n",teclaL);
	iprintf("\x1b[15;1HEl boton R se ha levantado %d\n",teclaR);
	
	iprintf("\x1b[16;1HPantalla cerrada %d\n",pantallaC);
	iprintf("\x1b[17;1HPantalla abierta %d\n",pantallaA);
}

int main()
{
	int held;
	
	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);

	PrintConsole topScreen;
	PrintConsole bottomScreen;
	
	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	
	consoleDemoInit();
	
	while(1)
	{
		scanKeys();
		held = keysHeld();
		
		if( held & KEY_A)
			printf("Key A is pressed\n");
		else
			printf("Key A is released\n");
			
		if( held & KEY_B)
			printf("Key B is pressed\n");
		else
			printf("Key B is released\n");
			
		if( held & KEY_X)
			printf("Key X is pressed\n");
		else
			printf("Key X is released\n");
			
		if( held & KEY_Y)
			printf("Key Y is pressed\n");
		else
			printf("Key Y is released\n");
			
		if( held & KEY_UP)
			printf("Key UP is pressed\n");
		else
			printf("Key UP is released\n");
			
		if( held & KEY_DOWN)
			printf("Key DOWN is pressed\n");
		else
			printf("Key DOWN is released\n");
			
		if( held & KEY_LEFT)
			printf("Key LEFT is pressed\n");
		else
			printf("Key LEFT is released\n");
			
		if( held & KEY_RIGHT)
			printf("Key RIGHT is pressed\n");
		else
			printf("Key RIGHT is released\n");
		
		if( held & KEY_L)
			printf("Key L is pressed\n");
		else
			printf("Key L is released\n");
			
		if( held & KEY_R)
			printf("Key R is pressed\n");
		else
			printf("Key R is released\n");
			
		if( held & KEY_START)
			printf("Key START is pressed\n");
		else
			printf("Key START is released\n");
			
		if( held & KEY_SELECT)
			printf("Key SELECT is pressed\n");
		else
			printf("Key SELECT is released\n");
			
		if( held & KEY_TOUCH)
			printf("Touch pad is touched\n");
		else
			printf("Touch pad is not touched\n");
			
		swiWaitForVBlank();
		consoleClear();

		consoleSelect(&topScreen);
		
		logica();
		
		consoleSelect(&bottomScreen);
	}
	return 0;
}