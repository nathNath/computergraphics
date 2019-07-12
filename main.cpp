#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	// Testing PutPixel
	
	// for(int i = 0; i < 64; i++) {
	// 	for(int j = 0; j < 64; j++){
	// 		PutPixel(4*i,4*j,255,0,0,255);
	// 	}
	// }

	// for(int i = 64; i < 127; i++) {
	// 	for(int j = 0; j < 64; j++){
	// 		PutPixel(4*i,4*j,0,255,0,255);
	// 	}
	// }

	// for(int i = 0; i < 64; i++) {
	// 	for(int j = 64; j < 127; j++){
	// 		PutPixel(4*i,4*j,0,0,255,255);
	// 	}
	// }

	// for(int i = 64; i < 127; i++) {
	// 	for(int j = 64; j < 127; j++){
	// 		PutPixel(4*i,4*j,255,255,255,255);
	// 	}
	// }

	//Testing DrawLine
	// DrawLine(0,0,511,511,255,0,0,255);
	// DrawLine(511,0,0,511,255,0,0,255);
	// DrawLine(0,254,511,255,255,0,0,255);
	// DrawLine(254,0,255,511,255,0,0,255);

	//Testing DrawTriangle
	DrawTriangle(0,255,255,0,255,0,511,255,511,255,0,255,255,0,0,255);
	DrawTriangle(0,511,511,0,511,0,511,511,511,511,0,511,255,0,255,255);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

