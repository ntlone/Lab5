﻿// LAB5_Zadanie_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include "glext.h"
#ifndef WIN32
#define GLX_GLXEXT_LEGACY
#include <GL/glx.h>
#define wglGetProcAddress glXGetProcAddressARB
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "colors.h"
#include "materials.h"
#include <math.h>

int opcje;


/*
(c) Janusz Ganczarski
http://www.januszg.hg.pl
JanuszG@enter.net.pl
*/

#include <GL/glut.h>
#include "glext.h"
#ifndef WIN32
#define GLX_GLXEXT_LEGACY
#include <GL/glx.h>
#define wglGetProcAddress glXGetProcAddressARB
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "colors.h"
#include "materials.h"

//// wskaźnik na funkcję glWindowPos2i
//
//PFNGLWINDOWPOS2IPROC glWindowPos2i = NULL;
//
//// stałe do obsługi menu podręcznego
//
//enum
//{
//	// obiekty
//	SPHERE,               // kula
//	TEAPOT,               // czajnik
//	CONE,                 // stożek
//	TORUS,                // torus
//	CUBE,                 // sześcian
//	DODECAHEDRON,         // dwunastościan
//	OCTAHEDRON,           // ośmiościan
//	TETRAHEDRON,          // czworościan
//	ICOSAHEDRON,          // dwudziestościan
//
//						  // materiały
//	BRASS,                // mosiądz
//	BRONZE,               // brąz
//	POLISHED_BRONZE,      // polerowany brąz
//	CHROME,               // chrom
//	COPPER,               // miedź
//	POLISHED_COPPER,      // polerowana miedź
//	GOLD,                 // złoto
//	POLISHED_GOLD,        // polerowane złoto
//	PEWTER,               // grafit (cyna z ołowiem)
//	SILVER,               // srebro
//	POLISHED_SILVER,      // polerowane srebro
//	EMERALD,              // szmaragd
//	JADE,                 // jadeit
//	OBSIDIAN,             // obsydian
//	PEARL,                // perła
//	RUBY,                 // rubin
//	TURQUOISE,            // turkus
//	BLACK_PLASTIC,        // czarny plastik
//	BLACK_RUBBER,         // czarna guma
//
//						  // obszar renderingu
//	FULL_WINDOW,          // aspekt obrazu - całe okno
//	ASPECT_1_1,           // aspekt obrazu 1:1
//	EXIT                  // wyjście
//};
//
//// aspekt obrazu
//
//int aspect = FULL_WINDOW;
//
//// usunięcie definicji makr near i far
//
//#ifdef near
//#undef near
//#endif
//#ifdef far
//#undef far
//#endif
//
//// rozmiary bryły obcinania
//
//const GLdouble left = -2.0;
//const GLdouble right = 2.0;
//const GLdouble bottom = -2.0;
//const GLdouble top = 2.0;
//const GLdouble near = 3.0;
//const GLdouble far = 7.0;
//
//// kąty obrotu obiektu
//
//GLfloat rotatex = 0.0;
//GLfloat rotatey = 0.0;
//
//// wskaźnik naciśnięcia lewego przycisku myszki
//
//int button_state = GLUT_UP;
//
//// położenie kursora myszki
//
//int button_x, button_y;
//
//// współczynnik skalowania
//
//GLfloat scale = 1.0;
//
//// właściwości materiału - domyślnie mosiądz
//
//const GLfloat *ambient = BrassAmbient;
//const GLfloat *diffuse = BrassDiffuse;
//const GLfloat *specular = BrassSpecular;
//GLfloat shininess = BrassShininess;
//
//// wyświetlany obiekt 3D
//
//int object = SPHERE;
//
//// kierunek źródła światła
//
//GLfloat light_position[4] =
//{
//	0.0,0.0,2.0,0.0
//};
//
//// kąty obrotu kierunku źródła światła
//
//GLfloat light_rotatex = 0.0;
//GLfloat light_rotatey = 0.0;
//
//// funkcja rysująca napis w wybranym miejscu
//// (wersja korzystająca z funkcji glWindowPos2i)
//
//void DrawString(GLint x, GLint y, char *string)
//{
//	// położenie napisu
//	glWindowPos2i(x, y);
//
//	// wyświetlenie napisu
//	int len = strlen(string);
//	for (int i = 0; i < len; i++)
//		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
//}
//// funkcja generująca scenę 3D
//
//void DisplayScene()
//{
//	// kolor tła - zawartośæ bufora koloru
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	// czyszczenie bufora koloru i bufora głębokości
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// wybór macierzy modelowania
//	glMatrixMode(GL_MODELVIEW);
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// włączenie testu bufora głębokości
//	glEnable(GL_DEPTH_TEST);
//
//	// włączenie oświetlenia
//	glEnable(GL_LIGHTING);
//
//	// włączenie światła GL_LIGHT0
//	glEnable(GL_LIGHT0);
//
//	// włączenie automatycznej normalizacji wektorów normalnych
//	glEnable(GL_NORMALIZE);
//
//	// przesunięcie układu współrzędnych obiektu do środka bryły odcinania
//	glTranslatef(0, 0, -(near + far) / 2);
//
//	// obroty obiektu
//	glRotatef(rotatex, 1.0, 0, 0);
//	glRotatef(rotatey, 0, 1.0, 0);
//
//	// skalowanie obiektu - klawisze "+" i "-"
//	glScalef(scale, scale, scale);
//
//	// właściwości materiału
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
//
//	// zmiana kierunku źródła światła jest wykonywana niezależnie
//	// od obrotów obiektu, stąd odłożenie na stos macierzy modelowania
//	glPushMatrix();
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// obroty kierunku źródła światła - klawisze kursora
//	glRotatef(light_rotatex, 1.0, 0, 0);
//	glRotatef(light_rotatey, 0, 1.0, 0);
//
//	// ustalenie kierunku źródła światła
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	// przywrócenie pierwotnej macierzy modelowania
//	glPopMatrix();
//
//	// rysowanie wybranego obiektu 3D
//	switch (object)
//	{
//		// kula
//	case SPHERE:
//		glutSolidSphere(1.0, 50, 40);
//		break;
//
//		// czajnik
//	case TEAPOT:
//		glutSolidTeapot(1);
//		break;
//
//		// stożek
//	case CONE:
//		glutSolidCone(1, 1, 50, 40);
//		break;
//
//		// torus
//	case TORUS:
//		glutSolidTorus(0.3, 1, 40, 50);
//		break;
//
//		// sześcian
//	case CUBE:
//		glutSolidCube(1);
//		break;
//
//		// dwunastościan
//	case DODECAHEDRON:
//		glutSolidDodecahedron();
//		break;
//
//		// ośmiościan
//	case OCTAHEDRON:
//		glutSolidOctahedron();
//		break;
//
//		// czworościan
//	case TETRAHEDRON:
//		glutSolidTetrahedron();
//		break;
//
//		// dwudziestościan
//	case ICOSAHEDRON:
//		glutSolidIcosahedron();
//		break;
//	}
//
//	// informacje o modyfikowanych wartościach
//	// parametrów źródła światała GL_LIGHT0
//	char string[200];
//	GLfloat vec[4];
//	glColor3fv(Black);
//
//	// kierunek źródła światła
//	glGetLightfv(GL_LIGHT0, GL_POSITION, vec);
//	sprintf(string, "GL_POSITION = (%f,%f,%f,%f)", vec[0], vec[1], vec[2], vec[3]);
//	DrawString(2, 2, string);
//
//	// kąty obrotu kierunku źródła światła
//	sprintf(string, "light_rotatex = %f", light_rotatex);
//	DrawString(2, 16, string);
//	sprintf(string, "light_rotatey = %f", light_rotatey);
//	DrawString(2, 30, string);
//
//	// skierowanie poleceń do wykonania
//	glFlush();
//
//	// zamiana buforów koloru
//	glutSwapBuffers();
//}
//
//// zmiana wielkości okna
//
//void Reshape(int width, int height)
//{
//	// obszar renderingu - całe okno
//	glViewport(0, 0, width, height);
//
//	// wybór macierzy rzutowania
//	glMatrixMode(GL_PROJECTION);
//
//	// macierz rzutowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// parametry bryły obcinania
//	if (aspect == ASPECT_1_1)
//	{
//		// wysokośæ okna większa od wysokości okna
//		if (width < height && width > 0)
//			glFrustum(left, right, bottom*height / width, top*height / width, near, far);
//		else
//
//			// szerokośæ okna większa lub równa wysokości okna
//			if (width >= height && height > 0)
//				glFrustum(left*width / height, right*width / height, bottom, top, near, far);
//	}
//	else
//		glFrustum(left, right, bottom, top, near, far);
//
//	// generowanie sceny 3D
//	DisplayScene();
//}
//
//// obsługa klawiatury
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//		// klawisz "+" - powiększenie obiektu
//	case '+':
//		scale += 0.05;
//		break;
//
//		// klawisz "-" - zmniejszenie obiektu
//	case '-':
//		if (scale > 0.05)
//			scale -= 0.05;
//		break;
//	}
//
//	// narysowanie sceny
//	DisplayScene();
//}
//
//// obsługa przycisków myszki
//
//void MouseButton(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		// zapamiętanie stanu lewego przycisku myszki
//		button_state = state;
//
//		// zapamiętanie położenia kursora myszki
//		if (state == GLUT_DOWN)
//		{
//			button_x = x;
//			button_y = y;
//		}
//	}
//}
//
//// obsługa ruchu kursora myszki
//
//void MouseMotion(int x, int y)
//{
//	if (button_state == GLUT_DOWN)
//	{
//		rotatey += 30 * (right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
//		button_x = x;
//		rotatex -= 30 * (top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
//		button_y = y;
//		glutPostRedisplay();
//	}
//}
//
//// obsługa klawiszy funkcyjnych i klawiszy kursora
//
//void SpecialKeys(int key, int x, int y)
//{
//	switch (key)
//	{
//		// kursor w lewo
//	case GLUT_KEY_LEFT:
//		light_rotatey -= 5;
//		break;
//
//		// kursor w prawo
//	case GLUT_KEY_RIGHT:
//		light_rotatey += 5;
//		break;
//
//		// kursor w dół
//	case GLUT_KEY_DOWN:
//		light_rotatex += 5;
//		break;
//
//		// kursor w górę
//	case GLUT_KEY_UP:
//		light_rotatex -= 5;
//		break;
//	}
//
//	// odrysowanie okna
//	DisplayScene();
//}
//
//// obsługa menu podręcznego
//
//void Menu(int value)
//{
//	switch (value)
//	{
//		// rysowany obiekt - kula
//	case SPHERE:
//		object = SPHERE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - czajnik
//	case TEAPOT:
//		object = TEAPOT;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - stożek
//	case CONE:
//		object = CONE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - torus
//	case TORUS:
//		object = TORUS;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - sześcian
//	case CUBE:
//		object = CUBE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - dwunastościan
//	case DODECAHEDRON:
//		object = DODECAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - ośmiościan
//	case OCTAHEDRON:
//		object = OCTAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - czworościan
//	case TETRAHEDRON:
//		object = TETRAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - dwudziestościan
//	case ICOSAHEDRON:
//		object = ICOSAHEDRON;
//		DisplayScene();
//		break;
//
//		// materiał - mosiądz
//	case BRASS:
//		ambient = BrassAmbient;
//		diffuse = BrassDiffuse;
//		specular = BrassSpecular;
//		shininess = BrassShininess;
//		DisplayScene();
//		break;
//
//		// materiał - brąz
//	case BRONZE:
//		ambient = BronzeAmbient;
//		diffuse = BronzeDiffuse;
//		specular = BronzeSpecular;
//		shininess = BronzeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowany brąz
//	case POLISHED_BRONZE:
//		ambient = PolishedBronzeAmbient;
//		diffuse = PolishedBronzeDiffuse;
//		specular = PolishedBronzeSpecular;
//		shininess = PolishedBronzeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - chrom
//	case CHROME:
//		ambient = ChromeAmbient;
//		diffuse = ChromeDiffuse;
//		specular = ChromeSpecular;
//		shininess = ChromeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - miedź
//	case COPPER:
//		ambient = CopperAmbient;
//		diffuse = CopperDiffuse;
//		specular = CopperSpecular;
//		shininess = CopperShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowana miedź
//	case POLISHED_COPPER:
//		ambient = PolishedCopperAmbient;
//		diffuse = PolishedCopperDiffuse;
//		specular = PolishedCopperSpecular;
//		shininess = PolishedCopperShininess;
//		DisplayScene();
//		break;
//
//		// materiał - złoto
//	case GOLD:
//		ambient = GoldAmbient;
//		diffuse = GoldDiffuse;
//		specular = GoldSpecular;
//		shininess = GoldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowane złoto
//	case POLISHED_GOLD:
//		ambient = PolishedGoldAmbient;
//		diffuse = PolishedGoldDiffuse;
//		specular = PolishedGoldSpecular;
//		shininess = PolishedGoldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - grafit (cyna z ołowiem)
//	case PEWTER:
//		ambient = PewterAmbient;
//		diffuse = PewterDiffuse;
//		specular = PewterSpecular;
//		shininess = PewterShininess;
//		DisplayScene();
//		break;
//
//		// materiał - srebro
//	case SILVER:
//		ambient = SilverAmbient;
//		diffuse = SilverDiffuse;
//		specular = SilverSpecular;
//		shininess = SilverShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowane srebro
//	case POLISHED_SILVER:
//		ambient = PolishedSilverAmbient;
//		diffuse = PolishedSilverDiffuse;
//		specular = PolishedSilverSpecular;
//		shininess = PolishedSilverShininess;
//		DisplayScene();
//		break;
//
//		// materiał - szmaragd
//	case EMERALD:
//		ambient = EmeraldAmbient;
//		diffuse = EmeraldDiffuse;
//		specular = EmeraldSpecular;
//		shininess = EmeraldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - jadeit
//	case JADE:
//		ambient = JadeAmbient;
//		diffuse = JadeDiffuse;
//		specular = JadeSpecular;
//		shininess = JadeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - obsydian
//	case OBSIDIAN:
//		ambient = ObsidianAmbient;
//		diffuse = ObsidianDiffuse;
//		specular = ObsidianSpecular;
//		shininess = ObsidianShininess;
//		DisplayScene();
//		break;
//
//		// materiał - perła
//	case PEARL:
//		ambient = PearlAmbient;
//		diffuse = PearlDiffuse;
//		specular = PearlSpecular;
//		shininess = PearlShininess;
//		DisplayScene();
//		break;
//
//		// metariał - rubin
//	case RUBY:
//		ambient = RubyAmbient;
//		diffuse = RubyDiffuse;
//		specular = RubySpecular;
//		shininess = RubyShininess;
//		DisplayScene();
//		break;
//
//		// materiał - turkus
//	case TURQUOISE:
//		ambient = TurquoiseAmbient;
//		diffuse = TurquoiseDiffuse;
//		specular = TurquoiseSpecular;
//		shininess = TurquoiseShininess;
//		DisplayScene();
//		break;
//
//		// materiał - czarny plastik
//	case BLACK_PLASTIC:
//		ambient = BlackPlasticAmbient;
//		diffuse = BlackPlasticDiffuse;
//		specular = BlackPlasticSpecular;
//		shininess = BlackPlasticShininess;
//		DisplayScene();
//		break;
//
//		// materiał - czarna guma
//	case BLACK_RUBBER:
//		ambient = BlackRubberAmbient;
//		diffuse = BlackRubberDiffuse;
//		specular = BlackRubberSpecular;
//		shininess = BlackRubberShininess;
//		DisplayScene();
//		break;
//
//		// obszar renderingu - całe okno
//	case FULL_WINDOW:
//		aspect = FULL_WINDOW;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// obszar renderingu - aspekt 1:1
//	case ASPECT_1_1:
//		aspect = ASPECT_1_1;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// wyjście
//	case EXIT:
//		exit(0);
//	}
//}
//
//// sprawdzenie i przygotowanie obsługi wybranych rozszerzeń
//
//void ExtensionSetup()
//{
//	// pobranie numeru wersji biblioteki OpenGL
//	const char *version = (char*)glGetString(GL_VERSION);
//
//	// odczyt wersji OpenGL
//	int major = 0, minor = 0;
//	if (sscanf(version, "%d.%d", &major, &minor) != 2)
//	{
//#ifndef WIN32
//		printf("Błędny format wersji OpenGL\n");
//#else
//
//		printf("Bledny format wersji OpenGL\n");
//#endif
//
//		exit(0);
//	}
//
//	// sprawdzenie czy jest co najmniej wersja 1.4
//	if (major > 1 || minor >= 4)
//	{
//		// pobranie wskaźnika wybranej funkcji OpenGL 1.4
//		glWindowPos2i = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
//	}
//	else
//		// sprawdzenie czy jest obsługiwane rozszerzenie ARB_window_pos
//		if (glutExtensionSupported("GL_ARB_window_pos"))
//		{
//			// pobranie wskaźnika wybranej funkcji rozszerzenia ARB_window_pos
//			glWindowPos2i = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress
//				("glWindowPos2iARB");
//		}
//		else
//		{
//			printf("Brak rozszerzenia ARB_window_pos!\n");
//			exit(0);
//		}
//}
//
//int main(int argc, char *argv[])
//{
//	// inicjalizacja biblioteki GLUT
//	glutInit(&argc, argv);
//
//	// inicjalizacja bufora ramki
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//	// rozmiary głównego okna programu
//	glutInitWindowSize(500, 500);
//
//	// utworzenie głównego okna programu
//
//#ifdef WIN32
//
//	glutCreateWindow("światło kierunkowe");
//#else
//
//	glutCreateWindow("Swiatlo kierunkowe");
//#endif
//
//	// dołączenie funkcji generującej scenę 3D
//	glutDisplayFunc(DisplayScene);
//
//	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
//	glutReshapeFunc(Reshape);
//
//	// dołączenie funkcji obsługi klawiatury
//	glutKeyboardFunc(Keyboard);
//
//	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
//	glutSpecialFunc(SpecialKeys);
//
//	// obsługa przycisków myszki
//	glutMouseFunc(MouseButton);
//
//	// obsługa ruchu kursora myszki
//	glutMotionFunc(MouseMotion);
//
//	// utworzenie menu podręcznego
//	glutCreateMenu(Menu);
//
//	// utworzenie podmenu - obiekt
//	int MenuObject = glutCreateMenu(Menu);
//	glutAddMenuEntry("Kula", SPHERE);
//	glutAddMenuEntry("Czajnik", TEAPOT);
//
//#ifdef WIN32
//
//	glutAddMenuEntry("Stożek", CONE);
//	glutAddMenuEntry("Torus", TORUS);
//	glutAddMenuEntry("Sześcian", CUBE);
//	glutAddMenuEntry("Dwunastościan", DODECAHEDRON);
//	glutAddMenuEntry("Ośmiościan", OCTAHEDRON);
//	glutAddMenuEntry("Czworościan", TETRAHEDRON);
//	glutAddMenuEntry("Dwudziestościan", ICOSAHEDRON);
//#else
//
//	glutAddMenuEntry("Stozek", CONE);
//	glutAddMenuEntry("Torus", TORUS);
//	glutAddMenuEntry("Szescian", CUBE);
//	glutAddMenuEntry("Dwunastoscian", DODECAHEDRON);
//	glutAddMenuEntry("Osmioscian", OCTAHEDRON);
//	glutAddMenuEntry("Czworoscian", TETRAHEDRON);
//	glutAddMenuEntry("Dwudziestoscian", ICOSAHEDRON);
//#endif
//
//	// utworzenie podmenu - Materiał
//	int MenuMaterial = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Mosiądz", BRASS);
//	glutAddMenuEntry("Brąz", BRONZE);
//	glutAddMenuEntry("Polerowany brąz", POLISHED_BRONZE);
//	glutAddMenuEntry("Chrom", CHROME);
//	glutAddMenuEntry("Miedź", COPPER);
//	glutAddMenuEntry("Polerowana miedź", POLISHED_COPPER);
//	glutAddMenuEntry("Złoto", GOLD);
//	glutAddMenuEntry("Polerowane złoto", POLISHED_GOLD);
//	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
//	glutAddMenuEntry("Srebro", SILVER);
//	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
//	glutAddMenuEntry("Szmaragd", EMERALD);
//	glutAddMenuEntry("Jadeit", JADE);
//	glutAddMenuEntry("Obsydian", OBSIDIAN);
//	glutAddMenuEntry("Perła", PEARL);
//	glutAddMenuEntry("Rubin", RUBY);
//	glutAddMenuEntry("Turkus", TURQUOISE);
//	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
//	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
//#else
//
//	glutAddMenuEntry("Mosiadz", BRASS);
//	glutAddMenuEntry("Braz", BRONZE);
//	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
//	glutAddMenuEntry("Chrom", CHROME);
//	glutAddMenuEntry("Miedz", COPPER);
//	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
//	glutAddMenuEntry("Zloto", GOLD);
//	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
//	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
//	glutAddMenuEntry("Srebro", SILVER);
//	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
//	glutAddMenuEntry("Szmaragd", EMERALD);
//	glutAddMenuEntry("Jadeit", JADE);
//	glutAddMenuEntry("Obsydian", OBSIDIAN);
//	glutAddMenuEntry("Perla", PEARL);
//	glutAddMenuEntry("Rubin", RUBY);
//	glutAddMenuEntry("Turkus", TURQUOISE);
//	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
//	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
//#endif
//
//	// utworzenie podmenu - Aspekt obrazu
//	int MenuAspect = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
//#else
//
//	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
//#endif
//
//	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);
//
//	// menu główne
//	glutCreateMenu(Menu);
//	glutAddSubMenu("Obiekt", MenuObject);
//
//#ifdef WIN32
//
//	glutAddSubMenu("Materiał", MenuMaterial);
//#else
//
//	glutAddSubMenu("Material", MenuMaterial);
//#endif
//
//	glutAddSubMenu("Aspekt obrazu", MenuAspect);
//#ifdef WIN32
//
//	glutAddMenuEntry("Wyjście", EXIT);
//#else
//
//	glutAddMenuEntry("Wyjscie", EXIT);
//#endif
//
//	// określenie przycisku myszki obsługującej menu podręczne
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// sprawdzenie i przygotowanie obsługi wybranych rozszerzeń
//	ExtensionSetup();
//
//	// wprowadzenie programu do obsługi pętli komunikatów
//	glutMainLoop();
//	return 0;
//}

///////////////////////////////////////////////////////////////////// PROGARM 2 /////////////////////////////////////////////////////////////////////


//// opengl_globalne_swiatlo_otaczajace.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//
//
///*
//(c) Janusz Ganczarski
//http://www.januszg.hg.pl
//JanuszG@enter.net.pl
//*/
//
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include "colors.h"
//
//// stałe do obsługi menu podręcznego
//
//enum
//{
//	FULL_WINDOW,    // aspekt obrazu - całe okno
//	ASPECT_1_1,     // aspekt obrazu 1:1
//	EXIT            // wyjście
//};
//
//// aspekt obrazu
//
//int aspect = FULL_WINDOW;
//
//// rozmiary bryły obcinania
//
//const GLdouble left = -2.0;
//const GLdouble right = 2.0;
//const GLdouble bottom = -2.0;
//const GLdouble top = 2.0;
//const GLdouble near_ = 3.0;
//const GLdouble far_ = 7.0;
//
//// kąty obrotu
//
//GLfloat rotatex = 0.0;
//GLfloat rotatey = 0.0;
//
//// wskaŸnik naciśnięcia lewego przycisku myszki
//
//int button_state = GLUT_UP;
//
//// poło¿enie kursora myszki
//
//int button_x, button_y;
//
//// składowe globalnego światła otaczającego
//// wartośæ początkowa odpowiada wartości domyślnej
//// składowych tego światła
//
//GLfloat ambient_light[4] =
//{
//	0.2,0.2,0.2,1.0
//};
//
//// funkcja rysująca napis w wybranym miejscu
//
//void DrawString(GLfloat x, GLfloat y, char *string)
//{
//	// poło¿enie napisu
//	glRasterPos2f(x, y);
//
//	// wyświetlenie napisu
//	int len = strlen(string);
//	for (int i = 0; i < len; i++)
//		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
//}
//
//// funkcja generująca scenę 3D
//
//void Display()
//{
//	// kolor tła - zawartośæ bufora koloru
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	// czyszczenie bufora koloru i bufora głębokości
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// wybór macierzy modelowania
//	glMatrixMode(GL_MODELVIEW);
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// przesunięcie układu współrzędnych sześcianu do środka bryły odcinania
//	glTranslatef(0, 0, -(near_ + far_) / 2);
//
//	// obroty sześcianu
//	glRotatef(rotatex, 1.0, 0, 0);
//	glRotatef(rotatey, 0, 1.0, 0);
//
//	// niewielkie powiększenie sześcianu
//	glScalef(1.15, 1.15, 1.15);
//
//	// włączenie oświetlenia
//	glEnable(GL_LIGHTING);
//
//	// parametry globalnego światła otaczającego
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
//
//	// włączenie obsługi właściwości materiałów
//	glEnable(GL_COLOR_MATERIAL);
//
//	// właściwości materiału określone przez kolor wierzchołków
//	glColorMaterial(GL_FRONT, GL_AMBIENT);
//
//	// włączenie testu bufora głębokości
//	glEnable(GL_DEPTH_TEST);
//
//	// rysowanie sześcianu - 12 trójkątów
//	glBegin(GL_TRIANGLES);
//	glColor3fv(Red);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//
//	glColor3fv(Magenta);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//
//	glColor3fv(Cyan);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//
//	glColor3fv(Lime);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//
//	glColor3fv(Blue);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//
//	glColor3fv(Yellow);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//
//	// koniec definicji sześcianu
//	glEnd();
//
//	// wyłączenie oświetlenia
//	glDisable(GL_LIGHTING);
//
//	// wyłączenie obsługi właściwości materiałów
//	glDisable(GL_COLOR_MATERIAL);
//
//	// wyświetlenie składowych globalnego światła otaczającego
//	char string[100];
//	GLfloat rgba[4];
//	glColor3fv(Black);
//
//	// pobranie wartości składowych światła otaczającego
//	// (oczywiście wartości te odpowiadają tablicy ambient_light)
//	glGetFloatv(GL_LIGHT_MODEL_AMBIENT, rgba);
//	sprintf(string, "AMBIENT: R=%f G=%f B=%f A=%f", rgba[0], rgba[1], rgba[2], rgba[3]);
//
//	// trzeba odpowiednio przekształciæ układ współrzędnych
//	// aby napis znajdował się na samej "górze" bryły obcinania
//	glLoadIdentity();
//	glTranslatef(0, 0, -near_);
//
//	// narysowanie napisu
//	DrawString(left, bottom, string);
//
//	// skierowanie poleceñ do wykonania
//	glFlush();
//
//	// zamiana buforów koloru
//	glutSwapBuffers();
//}
//
//// zmiana wielkości okna
//
//void Reshape(int width, int height)
//{
//	// obszar renderingu - całe okno
//	glViewport(0, 0, width, height);
//
//	// wybór macierzy rzutowania
//	glMatrixMode(GL_PROJECTION);
//
//	// macierz rzutowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// parametry bryły obcinania
//	if (aspect == ASPECT_1_1)
//	{
//		// wysokośæ okna większa od wysokości okna
//		if (width < height && width > 0)
//			glFrustum(left, right, bottom*height / width, top*height / width, near_, far_);
//		else
//
//			// szerokośæ okna większa lub równa wysokości okna
//			if (width >= height && height > 0)
//				glFrustum(left*width / height, right*width / height, bottom, top, near_, far_);
//	}
//	else
//		glFrustum(left, right, bottom, top, near_, far_);
//
//	// generowanie sceny 3D
//	Display();
//}
//
//// obsługa klawiatury
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	// zmiana wartości składowej R
//	if (key == 'R' && ambient_light[0] < 1.0)
//		ambient_light[0] += 0.05;
//	else
//		if (key == 'r' && ambient_light[0] > -1.0)
//			ambient_light[0] -= 0.05;
//
//	// zmiana wartości składowej G
//	if (key == 'G' && ambient_light[1] < 1.0)
//		ambient_light[1] += 0.05;
//	else
//		if (key == 'g' && ambient_light[1] > -1.0)
//			ambient_light[1] -= 0.05;
//
//	// zmiana wartości składowej B
//	if (key == 'B' && ambient_light[2] < 1.0)
//		ambient_light[2] += 0.05;
//	else
//		if (key == 'b' && ambient_light[2] > -1.0)
//			ambient_light[2] -= 0.05;
//
//	// narysowanie sceny
//	Display();
//}
//
//// obsługa klawiszy funkcyjnych i klawiszy kursora
//
//void SpecialKeys(int key, int x, int y)
//{
//	switch (key)
//	{
//		// kursor w lewo
//	case GLUT_KEY_LEFT:
//		rotatey -= 1;
//		break;
//
//		// kursor w górę
//	case GLUT_KEY_UP:
//		rotatex -= 1;
//		break;
//
//		// kursor w prawo
//	case GLUT_KEY_RIGHT:
//		rotatey += 1;
//		break;
//
//		// kursor w dół
//	case GLUT_KEY_DOWN:
//		rotatex += 1;
//		break;
//	}
//
//	// odrysowanie okna
//	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//}
//
//// obsługa przycisków myszki
//
//void MouseButton(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		// zapamiętanie stanu lewego przycisku myszki
//		button_state = state;
//
//		// zapamiętanie poło¿enia kursora myszki
//		if (state == GLUT_DOWN)
//		{
//			button_x = x;
//			button_y = y;
//		}
//	}
//}
//
//// obsługa ruchu kursora myszki
//
//void MouseMotion(int x, int y)
//{
//	if (button_state == GLUT_DOWN)
//	{
//		rotatey += 30 * (right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
//		button_x = x;
//		rotatex -= 30 * (top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
//		button_y = y;
//		glutPostRedisplay();
//	}
//}
//
//// obsługa menu podręcznego
//
//void Menu(int value)
//{
//	switch (value)
//	{
//		// obszar renderingu - całe okno
//	case FULL_WINDOW:
//		aspect = FULL_WINDOW;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// obszar renderingu - aspekt 1:1
//	case ASPECT_1_1:
//		aspect = ASPECT_1_1;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// wyjście
//	case EXIT:
//		exit(0);
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	// inicjalizacja biblioteki GLUT
//	glutInit(&argc, argv);
//
//	// inicjalizacja bufora ramki
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//	// rozmiary głównego okna programu
//	glutInitWindowSize(500, 500);
//
//	// utworzenie głównego okna programu
//#ifdef WIN32
//
//	glutCreateWindow("Globalne światło otaczające");
//#else
//
//	glutCreateWindow("Globalne swiatlo otaczajace");
//#endif
//
//	// dołączenie funkcji generującej scenę 3D
//	glutDisplayFunc(Display);
//
//	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
//	glutReshapeFunc(Reshape);
//
//	// dołączenie funkcji obsługi klawiatury
//	glutKeyboardFunc(Keyboard);
//
//	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
//	glutSpecialFunc(SpecialKeys);
//
//	// obsługa przycisków myszki
//	glutMouseFunc(MouseButton);
//
//	// obsługa ruchu kursora myszki
//	glutMotionFunc(MouseMotion);
//
//	// utworzenie menu podręcznego
//	glutCreateMenu(Menu);
//
//	// utworzenie podmenu - aspekt obrazu
//	int MenuAspect = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
//#else
//
//	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
//#endif
//
//	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);
//
//	// menu główne
//	glutCreateMenu(Menu);
//	glutAddSubMenu("Aspekt obrazu", MenuAspect);
//#ifdef WIN32
//
//	glutAddMenuEntry("Wyjście", EXIT);
//#else
//
//	glutAddMenuEntry("Wyjscie", EXIT);
//#endif
//
//	// określenie przycisku myszki obsługującej menu podręczne
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// wprowadzenie programu do obsługi pętli komunikatów
//	glutMainLoop();
//	return 0;
//}


///////////////////////////////////////////////////////////////////// PROGARM 3 /////////////////////////////////////////////////////////////////////


//// wskaźnik na funkcjê glWindowPos2i
//
//PFNGLWINDOWPOS2IPROC glWindowPos2i = NULL;
//
//// stałe do obsługi menu podrêcznego
//
//enum
//{
//	// obiekty
//	SPHERE,               // kula
//	TEAPOT,               // czajnik
//	CONE,                 // stożek
//	TORUS,                // torus
//	CUBE,                 // sześcian
//	DODECAHEDRON,         // dwunastościan
//	OCTAHEDRON,           // ośmiościan
//	TETRAHEDRON,          // czworościan
//	ICOSAHEDRON,          // dwudziestościan
//
//						  // materiały
//	BRASS,                // mosiądz
//	BRONZE,               // brąz
//	POLISHED_BRONZE,      // polerowany brąz
//	CHROME,               // chrom
//	COPPER,               // miedź
//	POLISHED_COPPER,      // polerowana miedź
//	GOLD,                 // złoto
//	POLISHED_GOLD,        // polerowane złoto
//	PEWTER,               // grafit (cyna z ołowiem)
//	SILVER,               // srebro
//	POLISHED_SILVER,      // polerowane srebro
//	EMERALD,              // szmaragd
//	JADE,                 // jadeit
//	OBSIDIAN,             // obsydian
//	PEARL,                // perła
//	RUBY,                 // rubin
//	TURQUOISE,            // turkus
//	BLACK_PLASTIC,        // czarny plastik
//	BLACK_RUBBER,         // czarna guma
//
//						  // obszar renderingu
//	FULL_WINDOW,          // aspekt obrazu - całe okno
//	ASPECT_1_1,           // aspekt obrazu 1:1
//	EXIT                  // wyjście
//};
//
//// aspekt obrazu
//
//int aspect = FULL_WINDOW;
//
//// usuniêcie definicji makr near i far
//
//#ifdef near
//#undef near
//#endif
//#ifdef far
//#undef far
//#endif
//
//// rozmiary bryły obcinania
//
//const GLdouble left = -2.0;
//const GLdouble right = 2.0;
//const GLdouble bottom = -2.0;
//const GLdouble top = 2.0;
//const GLdouble near = 3.0;
//const GLdouble far = 7.0;
//
//// kąty obrotu obiektu
//
//GLfloat rotatex = 0.0;
//GLfloat rotatey = 0.0;
//
//// wskaźnik naciśniêcia lewego przycisku myszki
//
//int button_state = GLUT_UP;
//
//// położenie kursora myszki
//
//int button_x, button_y;
//
//// współczynnik skalowania
//
//GLfloat scale = 1.0;
//
//// właściwości materiału - domyślnie mosiądz
//
//const GLfloat *ambient = BrassAmbient;
//const GLfloat *diffuse = BrassDiffuse;
//const GLfloat *specular = BrassSpecular;
//GLfloat shininess = BrassShininess;
//
//// wyświetlany obiekt 3D
//
//int object = SPHERE;
//
//// kierunek źródła światła
//
//GLfloat light_position[4] =
//{
//	0.0,0.0,2.0,1.0
//};
//
//// kąty obrotu położenia źródła światła
//
//GLfloat light_rotatex = 0.0;
//GLfloat light_rotatey = 0.0;
//
//// kierunek reflektora
//
//GLfloat spot_direction[3] =
//{
//	0.0,0.0,-1.0
//};
//
//// kąt odciêcia reflektora
//
//GLfloat spot_cutoff = 180.0;
//
//// wykładnik tłumienia kątowego reflektora
//
//GLfloat spot_exponent = 128.0;
//
//// stały współczynnik tłumienia światła
//
//GLfloat constant_attenuation = 1.0;
//
//// liniowy współczynnik tłumienia światła
//
//GLfloat linear_attenuation = 0.0;
//
//// kwadratowy współczynnik tłumienia światła
//
//GLfloat quadratic_attenuation = 0.0;
//
//// funkcja rysująca napis w wybranym miejscu
//// (wersja korzystająca z funkcji glWindowPos2i)
//
//void DrawString(GLint x, GLint y, char *string)
//{
//	// położenie napisu
//	glWindowPos2i(x, y);
//
//	// wyświetlenie napisu
//	int len = strlen(string);
//	for (int i = 0; i < len; i++)
//		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
//}
//
//// funkcja generująca scenê 3D
//
//void DisplayScene()
//{
//	// kolor tła - zawartośæ bufora koloru
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	// czyszczenie bufora koloru i bufora głêbokości
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	// wybór macierzy modelowania
//	glMatrixMode(GL_MODELVIEW);
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// włączenie testu bufora głêbokości
//	glEnable(GL_DEPTH_TEST);
//
//	// włączenie oświetlenia
//	glEnable(GL_LIGHTING);
//
//	// włączenie światła GL_LIGHT0
//	glEnable(GL_LIGHT0);
//
//	// włączenie automatycznej normalizacji wektorów normalnych
//	glEnable(GL_NORMALIZE);
//
//	// przesuniêcie układu współrzêdnych obiektu do środka bryły odcinania
//	glTranslatef(0, 0, -(near + far) / 2);
//
//	// obroty obiektu
//	glRotatef(rotatex, 1.0, 0, 0);
//	glRotatef(rotatey, 0, 1.0, 0);
//
//	// skalowanie obiektu - klawisze "+" i "-"
//	glScalef(scale, scale, scale);
//
//	// właściwości materiału
//	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
//
//	// kąt odciêcia reflektora
//	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);
//
//	// wykładnik tłumienia kątowego reflektora
//	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
//
//	// stały współczynnik tłumienia światła,
//	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constant_attenuation);
//
//	// liniowy współczynnik tłumienia światła
//	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linear_attenuation);
//
//	// kwadratowy współczynnik tłumienia światła
//	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);
//
//	// zmiana położenia źródła światła jest wykonywana niezależnie
//	// od obrotów obiektu, stąd odłożenie na stos macierzy modelowania
//	glPushMatrix();
//
//	// macierz modelowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// przesuniêcie układu współrzêdnych źródła światła do środka bryły odcinania
//	glTranslatef(0, 0, -(near + far) / 2);
//
//	// obroty położenia źródła światła - klawisze kursora
//	glRotatef(light_rotatex, 1.0, 0, 0);
//	glRotatef(light_rotatey, 0, 1.0, 0);
//
//	// przesuniêcie źródła światła
//	glTranslatef(light_position[0], light_position[1], light_position[2]);
//
//	// ustalenie pozycji źródła światła
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	// ustalenie kierunku reflektora
//	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
//
//	// odłożenie na stos zmiennych stanu związanych z oświetleniem sceny
//	glPushAttrib(GL_LIGHTING_BIT);
//
//	// wyłacznie źródła światła GL_LIGHT0
//	glDisable(GL_LIGHT0);
//
//	// materiał imitujący świecenie kuli na czerwono
//	glMaterialfv(GL_FRONT, GL_EMISSION, Red);
//
//	// narysowanie kuli położonej w początku źródła światła
//	glutSolidSphere(0.1, 30, 20);
//
//	// przywrócenie zmiennych stanu związanych z oświetleniem sceny
//	glPopAttrib();
//
//	// przywrócenie pierwotnej macierzy modelowania
//	glPopMatrix();
//
//	// rysowanie wybranego obiektu 3D
//	switch (object)
//	{
//		// kula
//	case SPHERE:
//		glutSolidSphere(1.0, 50, 40);
//		break;
//
//		// czajnik
//	case TEAPOT:
//		glutSolidTeapot(1);
//		break;
//
//		// stożek
//	case CONE:
//		glutSolidCone(1, 1, 50, 40);
//		break;
//
//		// torus
//	case TORUS:
//		glutSolidTorus(0.3, 1, 40, 50);
//		break;
//
//		// sześcian
//	case CUBE:
//		glutSolidCube(1);
//		break;
//
//		// dwunastościan
//	case DODECAHEDRON:
//		glutSolidDodecahedron();
//		break;
//
//		// ośmiościan
//	case OCTAHEDRON:
//		glutSolidOctahedron();
//		break;
//
//		// czworościan
//	case TETRAHEDRON:
//		glutSolidTetrahedron();
//		break;
//
//		// dwudziestościan
//	case ICOSAHEDRON:
//		glutSolidIcosahedron();
//		break;
//	}
//
//	// informacje o wartościach modyfikowanych
//	// parametrów źródła światała GL_LIGHT0
//	char string[200];
//	GLfloat vec[4];
//	glColor3fv(Black);
//
//	// kierunek źródła światła
//	glGetLightfv(GL_LIGHT0, GL_POSITION, vec);
//	sprintf(string, "GL_POSITION = (%f,%f,%f,%f)", vec[0], vec[1], vec[2], vec[3]);
//	DrawString(2, 2, string);
//
//	glGetLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, vec);
//	sprintf(string, "GL_SPOT_DIRECTION = (%f,%f,%f)", vec[0], vec[1], vec[2]);
//	DrawString(2, 16, string);
//
//	// kąt odciêcia reflektora
//	glGetLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, vec);
//	sprintf(string, "GL_SPOT_CUTOFF = %f", vec[0]);
//	DrawString(2, 30, string);
//
//	// wykładnik tłumienia kątowego reflektora
//	glGetLightfv(GL_LIGHT0, GL_SPOT_EXPONENT, vec);
//	sprintf(string, "GL_SPOT_EXPONENT = %f", vec[0]);
//	DrawString(2, 44, string);
//
//	// stały współczynnik tłumienia światła,
//	glGetLightfv(GL_LIGHT0, GL_CONSTANT_ATTENUATION, vec);
//	sprintf(string, "GL_CONSTANT_ATTENUATION = %f", vec[0]);
//	DrawString(2, 58, string);
//
//	// liniowy współczynnik tłumienia światła
//	glGetLightfv(GL_LIGHT0, GL_LINEAR_ATTENUATION, vec);
//	sprintf(string, "GL_LINEAR_ATTENUATION = %f", vec[0]);
//	DrawString(2, 72, string);
//
//	// kwadratowy współczynnik tłumienia światła
//	glGetLightfv(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, vec);
//	sprintf(string, "GL_QUADRATIC_ATTENUATION = %f", vec[0]);
//	DrawString(2, 86, string);
//
//	// skierowanie poleceñ do wykonania
//	glFlush();
//
//	// zamiana buforów koloru
//	glutSwapBuffers();
//}
//
//// zmiana wielkości okna
//
//void Reshape(int width, int height)
//{
//	// obszar renderingu - całe okno
//	glViewport(0, 0, width, height);
//
//	// wybór macierzy rzutowania
//	glMatrixMode(GL_PROJECTION);
//
//	// macierz rzutowania = macierz jednostkowa
//	glLoadIdentity();
//
//	// parametry bryły obcinania
//	if (aspect == ASPECT_1_1)
//	{
//		// wysokośæ okna wiêksza od wysokości okna
//		if (width < height && width > 0)
//			glFrustum(left, right, bottom*height / width, top*height / width, near, far);
//		else
//
//			// szerokośæ okna wiêksza lub równa wysokości okna
//			if (width >= height && height > 0)
//				glFrustum(left*width / height, right*width / height, bottom, top, near, far);
//	}
//	else
//		glFrustum(left, right, bottom, top, near, far);
//
//	// generowanie sceny 3D
//	DisplayScene();
//}
//
//// obsługa klawiatury
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//		// klawisz "+" - powiêkszenie obiektu
//	case '+':
//		scale += 0.05;
//		break;
//
//		// klawisz "-" - zmniejszenie obiektu
//	case '-':
//		if (scale > 0.05)
//			scale -= 0.05;
//		break;
//
//		// klawisz "S" - zwiêkszenie kąta obciêcia reflektora
//	case 'S':
//		if (spot_cutoff == 90)
//			spot_cutoff = 180;
//		else
//			if (spot_cutoff < 90)
//				spot_cutoff++;
//		break;
//
//		// klawisz "s" - zmniejszenie kąta obciêcia reflektora
//	case 's':
//		if (spot_cutoff == 180)
//			spot_cutoff = 90;
//		else
//			if (spot_cutoff > 0)
//				spot_cutoff--;
//		break;
//
//		// klawisz "E" - zwiêkszenie wykładnika tłumienia kątowego reflektora
//	case 'E':
//		if (spot_exponent < 128)
//			spot_exponent++;
//		break;
//
//		// klawisz "e" - zmniejszenie wykładnika tłumienia kątowego reflektora
//	case 'e':
//		if (spot_exponent > 0)
//			spot_exponent--;
//		break;
//
//		// klawisz "C" - zwiêkszenie stałego współczynnika tłumienia światła
//	case 'C':
//		constant_attenuation += 0.1;
//		break;
//
//		// klawisz "c" - zmniejszenie stałego współczynnika tłumienia światła
//	case 'c':
//		if (constant_attenuation > 0)
//			constant_attenuation -= 0.1;
//		break;
//
//		// klawisz "L" - zwiêkszenie liniowego współczynnika tłumienia światła
//	case 'L':
//		linear_attenuation += 0.1;
//		break;
//
//		// klawisz "l" - zmniejszenie liniowego współczynnika tłumienia światła
//	case 'l':
//		if (linear_attenuation > 0)
//			linear_attenuation -= 0.1;
//		break;
//
//		// klawisz "Q" - zwiêkszenie kwadratowego współczynnika tłumienia światła
//	case 'Q':
//		quadratic_attenuation += 0.1;
//		break;
//
//		// klawisz "q" - zmniejszenie kwadratowego współczynnika tłumienia światła
//	case 'q':
//		if (quadratic_attenuation > 0)
//			quadratic_attenuation -= 0.1;
//		break;
//	}
//
//	// narysowanie sceny
//	DisplayScene();
//}
//
//// obsługa przycisków myszki
//
//void MouseButton(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		// zapamiêtanie stanu lewego przycisku myszki
//		button_state = state;
//
//		// zapamiêtanie położenia kursora myszki
//		if (state == GLUT_DOWN)
//		{
//			button_x = x;
//			button_y = y;
//		}
//	}
//}
//
//// obsługa ruchu kursora myszki
//
//void MouseMotion(int x, int y)
//{
//	if (button_state == GLUT_DOWN)
//	{
//		rotatey += 30 * (right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
//		button_x = x;
//		rotatex -= 30 * (top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
//		button_y = y;
//		glutPostRedisplay();
//	}
//}
//
//// obsługa klawiszy funkcyjnych i klawiszy kursora
//
//void SpecialKeys(int key, int x, int y)
//{
//	switch (key)
//	{
//		// kursor w lewo
//	case GLUT_KEY_LEFT:
//		light_rotatey -= 5;
//		break;
//
//		// kursor w prawo
//	case GLUT_KEY_RIGHT:
//		light_rotatey += 5;
//		break;
//
//		// kursor w dół
//	case GLUT_KEY_DOWN:
//		light_rotatex += 5;
//		break;
//
//		// kursor w górê
//	case GLUT_KEY_UP:
//		light_rotatex -= 5;
//		break;
//	}
//
//	// odrysowanie okna
//	DisplayScene();
//}
//
//// obsługa menu podrêcznego
//
//void Menu(int value)
//{
//	switch (value)
//	{
//		// rysowany obiekt - kula
//	case SPHERE:
//		object = SPHERE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - czajnik
//	case TEAPOT:
//		object = TEAPOT;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - stożek
//	case CONE:
//		object = CONE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - torus
//	case TORUS:
//		object = TORUS;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - sześcian
//	case CUBE:
//		object = CUBE;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - dwunastościan
//	case DODECAHEDRON:
//		object = DODECAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - ośmiościan
//	case OCTAHEDRON:
//		object = OCTAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - czworościan
//	case TETRAHEDRON:
//		object = TETRAHEDRON;
//		DisplayScene();
//		break;
//
//		// rysowany obiekt - dwudziestościan
//	case ICOSAHEDRON:
//		object = ICOSAHEDRON;
//		DisplayScene();
//		break;
//
//		// materiał - mosiądz
//	case BRASS:
//		ambient = BrassAmbient;
//		diffuse = BrassDiffuse;
//		specular = BrassSpecular;
//		shininess = BrassShininess;
//		DisplayScene();
//		break;
//
//		// materiał - brąz
//	case BRONZE:
//		ambient = BronzeAmbient;
//		diffuse = BronzeDiffuse;
//		specular = BronzeSpecular;
//		shininess = BronzeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowany brąz
//	case POLISHED_BRONZE:
//		ambient = PolishedBronzeAmbient;
//		diffuse = PolishedBronzeDiffuse;
//		specular = PolishedBronzeSpecular;
//		shininess = PolishedBronzeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - chrom
//	case CHROME:
//		ambient = ChromeAmbient;
//		diffuse = ChromeDiffuse;
//		specular = ChromeSpecular;
//		shininess = ChromeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - miedź
//	case COPPER:
//		ambient = CopperAmbient;
//		diffuse = CopperDiffuse;
//		specular = CopperSpecular;
//		shininess = CopperShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowana miedź
//	case POLISHED_COPPER:
//		ambient = PolishedCopperAmbient;
//		diffuse = PolishedCopperDiffuse;
//		specular = PolishedCopperSpecular;
//		shininess = PolishedCopperShininess;
//		DisplayScene();
//		break;
//
//		// materiał - złoto
//	case GOLD:
//		ambient = GoldAmbient;
//		diffuse = GoldDiffuse;
//		specular = GoldSpecular;
//		shininess = GoldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowane złoto
//	case POLISHED_GOLD:
//		ambient = PolishedGoldAmbient;
//		diffuse = PolishedGoldDiffuse;
//		specular = PolishedGoldSpecular;
//		shininess = PolishedGoldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - grafit (cyna z ołowiem)
//	case PEWTER:
//		ambient = PewterAmbient;
//		diffuse = PewterDiffuse;
//		specular = PewterSpecular;
//		shininess = PewterShininess;
//		DisplayScene();
//		break;
//
//		// materiał - srebro
//	case SILVER:
//		ambient = SilverAmbient;
//		diffuse = SilverDiffuse;
//		specular = SilverSpecular;
//		shininess = SilverShininess;
//		DisplayScene();
//		break;
//
//		// materiał - polerowane srebro
//	case POLISHED_SILVER:
//		ambient = PolishedSilverAmbient;
//		diffuse = PolishedSilverDiffuse;
//		specular = PolishedSilverSpecular;
//		shininess = PolishedSilverShininess;
//		DisplayScene();
//		break;
//
//		// materiał - szmaragd
//	case EMERALD:
//		ambient = EmeraldAmbient;
//		diffuse = EmeraldDiffuse;
//		specular = EmeraldSpecular;
//		shininess = EmeraldShininess;
//		DisplayScene();
//		break;
//
//		// materiał - jadeit
//	case JADE:
//		ambient = JadeAmbient;
//		diffuse = JadeDiffuse;
//		specular = JadeSpecular;
//		shininess = JadeShininess;
//		DisplayScene();
//		break;
//
//		// materiał - obsydian
//	case OBSIDIAN:
//		ambient = ObsidianAmbient;
//		diffuse = ObsidianDiffuse;
//		specular = ObsidianSpecular;
//		shininess = ObsidianShininess;
//		DisplayScene();
//		break;
//
//		// materiał - perła
//	case PEARL:
//		ambient = PearlAmbient;
//		diffuse = PearlDiffuse;
//		specular = PearlSpecular;
//		shininess = PearlShininess;
//		DisplayScene();
//		break;
//
//		// metariał - rubin
//	case RUBY:
//		ambient = RubyAmbient;
//		diffuse = RubyDiffuse;
//		specular = RubySpecular;
//		shininess = RubyShininess;
//		DisplayScene();
//		break;
//
//		// materiał - turkus
//	case TURQUOISE:
//		ambient = TurquoiseAmbient;
//		diffuse = TurquoiseDiffuse;
//		specular = TurquoiseSpecular;
//		shininess = TurquoiseShininess;
//		DisplayScene();
//		break;
//
//		// materiał - czarny plastik
//	case BLACK_PLASTIC:
//		ambient = BlackPlasticAmbient;
//		diffuse = BlackPlasticDiffuse;
//		specular = BlackPlasticSpecular;
//		shininess = BlackPlasticShininess;
//		DisplayScene();
//		break;
//
//		// materiał - czarna guma
//	case BLACK_RUBBER:
//		ambient = BlackRubberAmbient;
//		diffuse = BlackRubberDiffuse;
//		specular = BlackRubberSpecular;
//		shininess = BlackRubberShininess;
//		DisplayScene();
//		break;
//
//		// obszar renderingu - całe okno
//	case FULL_WINDOW:
//		aspect = FULL_WINDOW;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// obszar renderingu - aspekt 1:1
//	case ASPECT_1_1:
//		aspect = ASPECT_1_1;
//		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//		break;
//
//		// wyjście
//	case EXIT:
//		exit(0);
//	}
//}
//
//// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ
//
//void ExtensionSetup()
//{
//	// pobranie numeru wersji biblioteki OpenGL
//	const char *version = (char*)glGetString(GL_VERSION);
//
//	// odczyt wersji OpenGL
//	int major = 0, minor = 0;
//	if (sscanf(version, "%d.%d", &major, &minor) != 2)
//	{
//#ifndef WIN32
//		printf("Błêdny format wersji OpenGL\n");
//#else
//
//		printf("Bledny format wersji OpenGL\n");
//#endif
//
//		exit(0);
//	}
//
//	// sprawdzenie czy jest co najmniej wersja 1.4
//	if (major > 1 || minor >= 4)
//	{
//		// pobranie wskaźnika wybranej funkcji OpenGL 1.4
//		glWindowPos2i = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
//	}
//	else
//		// sprawdzenie czy jest obsługiwane rozszerzenie ARB_window_pos
//		if (glutExtensionSupported("GL_ARB_window_pos"))
//		{
//			// pobranie wskaźnika wybranej funkcji rozszerzenia ARB_window_pos
//			glWindowPos2i = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress
//				("glWindowPos2iARB");
//		}
//		else
//		{
//			printf("Brak rozszerzenia ARB_window_pos!\n");
//			exit(0);
//		}
//}
//
//int main(int argc, char *argv[])
//{
//	// inicjalizacja biblioteki GLUT
//	glutInit(&argc, argv);
//
//	// inicjalizacja bufora ramki
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//
//	// rozmiary głównego okna programu
//	glutInitWindowSize(500, 500);
//
//	// utworzenie głównego okna programu
//	glutCreateWindow("Reflektor");
//
//	// dołączenie funkcji generującej scenê 3D
//	glutDisplayFunc(DisplayScene);
//
//	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
//	glutReshapeFunc(Reshape);
//
//	// dołączenie funkcji obsługi klawiatury
//	glutKeyboardFunc(Keyboard);
//
//	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
//	glutSpecialFunc(SpecialKeys);
//
//	// obsługa przycisków myszki
//	glutMouseFunc(MouseButton);
//
//	// obsługa ruchu kursora myszki
//	glutMotionFunc(MouseMotion);
//
//	// utworzenie menu podrêcznego
//	glutCreateMenu(Menu);
//
//	// utworzenie podmenu - obiekt
//	int MenuObject = glutCreateMenu(Menu);
//	glutAddMenuEntry("Kula", SPHERE);
//	glutAddMenuEntry("Czajnik", TEAPOT);
//
//#ifdef WIN32
//
//	glutAddMenuEntry("Stożek", CONE);
//	glutAddMenuEntry("Torus", TORUS);
//	glutAddMenuEntry("Sześcian", CUBE);
//	glutAddMenuEntry("Dwunastościan", DODECAHEDRON);
//	glutAddMenuEntry("Ośmiościan", OCTAHEDRON);
//	glutAddMenuEntry("Czworościan", TETRAHEDRON);
//	glutAddMenuEntry("Dwudziestościan", ICOSAHEDRON);
//#else
//
//	glutAddMenuEntry("Stozek", CONE);
//	glutAddMenuEntry("Torus", TORUS);
//	glutAddMenuEntry("Szescian", CUBE);
//	glutAddMenuEntry("Dwunastoscian", DODECAHEDRON);
//	glutAddMenuEntry("Osmioscian", OCTAHEDRON);
//	glutAddMenuEntry("Czworoscian", TETRAHEDRON);
//	glutAddMenuEntry("Dwudziestoscian", ICOSAHEDRON);
//#endif
//
//	// utworzenie podmenu - Materiał
//	int MenuMaterial = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Mosiądz", BRASS);
//	glutAddMenuEntry("Brąz", BRONZE);
//	glutAddMenuEntry("Polerowany brąz", POLISHED_BRONZE);
//	glutAddMenuEntry("Chrom", CHROME);
//	glutAddMenuEntry("Miedź", COPPER);
//	glutAddMenuEntry("Polerowana miedź", POLISHED_COPPER);
//	glutAddMenuEntry("Złoto", GOLD);
//	glutAddMenuEntry("Polerowane złoto", POLISHED_GOLD);
//	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
//	glutAddMenuEntry("Srebro", SILVER);
//	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
//	glutAddMenuEntry("Szmaragd", EMERALD);
//	glutAddMenuEntry("Jadeit", JADE);
//	glutAddMenuEntry("Obsydian", OBSIDIAN);
//	glutAddMenuEntry("Perła", PEARL);
//	glutAddMenuEntry("Rubin", RUBY);
//	glutAddMenuEntry("Turkus", TURQUOISE);
//	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
//	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
//#else
//
//	glutAddMenuEntry("Mosiadz", BRASS);
//	glutAddMenuEntry("Braz", BRONZE);
//	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
//	glutAddMenuEntry("Chrom", CHROME);
//	glutAddMenuEntry("Miedz", COPPER);
//	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
//	glutAddMenuEntry("Zloto", GOLD);
//	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
//	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
//	glutAddMenuEntry("Srebro", SILVER);
//	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
//	glutAddMenuEntry("Szmaragd", EMERALD);
//	glutAddMenuEntry("Jadeit", JADE);
//	glutAddMenuEntry("Obsydian", OBSIDIAN);
//	glutAddMenuEntry("Perla", PEARL);
//	glutAddMenuEntry("Rubin", RUBY);
//	glutAddMenuEntry("Turkus", TURQUOISE);
//	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
//	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
//#endif
//
//	// utworzenie podmenu - Aspekt obrazu
//	int MenuAspect = glutCreateMenu(Menu);
//#ifdef WIN32
//
//	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
//#else
//
//	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
//#endif
//
//	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);
//
//	// menu główne
//	glutCreateMenu(Menu);
//	glutAddSubMenu("Obiekt", MenuObject);
//
//#ifdef WIN32
//
//	glutAddSubMenu("Materiał", MenuMaterial);
//#else
//
//	glutAddSubMenu("Material", MenuMaterial);
//#endif
//
//	glutAddSubMenu("Aspekt obrazu", MenuAspect);
//#ifdef WIN32
//
//	glutAddMenuEntry("Wyjście", EXIT);
//#else
//
//	glutAddMenuEntry("Wyjscie", EXIT);
//#endif
//
//	// określenie przycisku myszki obsługującej menu podrêczne
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ
//	ExtensionSetup();
//
//	// wprowadzenie programu do obsługi pêtli komunikatów
//	glutMainLoop();
//	return 0;
//}




///////////////////////////////////////////////////////////////////// PROGARM 4 /////////////////////////////////////////////////////////////////////


// wskaźnik dostępności rozszerzenia EXT_rescale_normal

bool rescale_normal = false;

// stałe do obsługi menu podręcznego

enum
{
	BRASS,                // mosiądz
	BRONZE,               // brąz
	POLISHED_BRONZE,      // polerowany brąz
	CHROME,               // chrom
	COPPER,               // miedź
	POLISHED_COPPER,      // polerowana miedź
	GOLD,                 // złoto
	POLISHED_GOLD,        // polerowane złoto
	PEWTER,               // grafit (cyna z ołowiem)
	SILVER,               // srebro
	POLISHED_SILVER,      // polerowane srebro
	EMERALD,              // szmaragd
	JADE,                 // jadeit
	OBSIDIAN,             // obsydian
	PEARL,                // perła
	RUBY,                 // rubin
	TURQUOISE,            // turkus
	BLACK_PLASTIC,        // czarny plastik
	BLACK_RUBBER,         // czarna guma
	NORMALS_SMOOTH,       // jeden wektor normalny na wierzchołek
	NORMALS_FLAT,         // jeden wektor normalny na ścianę
	FULL_WINDOW,          // aspekt obrazu - całe okno
	ASPECT_1_1,           // aspekt obrazu 1:1
	EXIT                  // wyjście
};

// aspekt obrazu

int aspect = FULL_WINDOW;

// usunięcie definicji makr near i far

#ifdef near
#undef near
#endif
#ifdef far
#undef far
#endif

// rozmiary bryły obcinania

const GLdouble left = -1.0;
const GLdouble right = 1.0;
const GLdouble bottom = -1.0;
const GLdouble top = 1.0;
const GLdouble near = 3.0;
const GLdouble far = 7.0;

// kąty obrotu

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;

// wskaźnik naciśnięcia lewego przycisku myszki

int button_state = GLUT_UP;

// poło¿enie kursora myszki

int button_x, button_y;

// współczynnik skalowania

GLfloat scale = 1.0;

// właściwości materiału - domyślnie mosiądz

const GLfloat *ambient = BrassAmbient;
const GLfloat *diffuse = BrassDiffuse;
const GLfloat *specular = BrassSpecular;
GLfloat shininess = BrassShininess;

// wektory normalne

int normals = NORMALS_FLAT;

// współrzędne wierzchołków dwudziestościanu

GLfloat vertex[12 * 3] =
{
	0.000,  0.667,  0.500,   // v0
	0.000,  0.667, -0.500,   // v1
	0.000, -0.667, -0.500,   // v2
	0.000, -0.667,  0.500,   // v3
	0.667,  0.500,  0.000,   // v4
	0.667, -0.500,  0.000,   // v5
	-0.667, -0.500,  0.000,  // v6
	-0.667,  0.500,  0.000,  // v7
	0.500,  0.000,  0.667,   // v8
	-0.500,  0.000,  0.667,  // v9
	-0.500,  0.000, -0.667,  // v10
	0.500,  0.000, -0.667    // v11
};

// opis ścian dwudziestościanu

int triangles[20 * 3] =
{
	2, 10, 11,
	1, 11, 10,
	1, 10,  7,
	1,  4, 11,
	0,  1,  7,
	0,  4,  1,
	0,  9,  8,
	3,  8,  9,
	0,  7,  9,
	0,  8,  4,
	3,  9,  6,
	3,  5,  8,
	2,  3,  6,
	2,  5,  3,
	2,  6, 10,
	2, 11,  5,
	6,  7, 10,
	6,  9,  7,
	4,  5, 11,
	4,  8,  5
};

// obliczanie wektora normalnego dla wybranej ściany

void Normal(GLfloat *n, int i)
{
	GLfloat v1[3], v2[3];

	// obliczenie wektorów na podstawie współrzędnych wierzchołków trójkątów
	v1[0] = vertex[3 * triangles[3 * i + 1] + 0] - vertex[3 * triangles[3 * i + 0] + 0];
	v1[1] = vertex[3 * triangles[3 * i + 1] + 1] - vertex[3 * triangles[3 * i + 0] + 1];
	v1[2] = vertex[3 * triangles[3 * i + 1] + 2] - vertex[3 * triangles[3 * i + 0] + 2];
	v2[0] = vertex[3 * triangles[3 * i + 2] + 0] - vertex[3 * triangles[3 * i + 1] + 0];
	v2[1] = vertex[3 * triangles[3 * i + 2] + 1] - vertex[3 * triangles[3 * i + 1] + 1];
	v2[2] = vertex[3 * triangles[3 * i + 2] + 2] - vertex[3 * triangles[3 * i + 1] + 2];

	// obliczenie waktora normalnego przy pomocy iloczynu wektorowego
	n[0] = v1[1] * v2[2] - v1[2] * v2[1];
	n[1] = v1[2] * v2[0] - v1[0] * v2[2];
	n[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

// normalizacja wektora

void Normalize(GLfloat *v)
{
	// obliczenie długości wektora
	GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

	// normalizacja wektora
	if (d)
	{
		v[0] /= d;
		v[1] /= d;
		v[2] /= d;
	}
}

// funkcja generująca scenę 3D

void Display()
{
	// kolor tła - zawartość bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru i bufora głębokości
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesunięcie układu współrzędnych obiektu do środka bryły odcinania
	glTranslatef(0, 0, -(near + far) / 2);

	// obroty obiektu
	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scale, scale, scale);

	// włączenie testu bufora głębokości
	glEnable(GL_DEPTH_TEST);

	// włączenie oświetlenia
	glEnable(GL_LIGHTING);

	// włączenie światła GL_LIGHT0 z parametrami domyślnymi
	glEnable(GL_LIGHT0);

	// właściwości materiału
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	// włączenie automatycznej normalizacji wektorów normalnych
	// lub automatycznego skalowania jednostkowych wektorów normalnych
	if (rescale_normal == true)
		glEnable(GL_RESCALE_NORMAL);
	else
		glEnable(GL_NORMALIZE);

	// początek definicji obiektu
	glBegin(GL_TRIANGLES);

	// generowanie obiektu gładkiego - jeden uśredniony
	// wektor normalny na wierzchołek
	if (normals == NORMALS_SMOOTH)
		for (int i = 0; i < 20; i++)
		{
			// obliczanie wektora normalnego dla pierwszego wierzchołka
			GLfloat n[3];
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich ścian posiadających bie¿ący wierzchołek
			for (int j = 0; j < 20; j++)
				if (3 * triangles[3 * i + 0] == 3 * triangles[3 * j + 0] ||
					3 * triangles[3 * i + 0] == 3 * triangles[3 * j + 1] ||
					3 * triangles[3 * i + 0] == 3 * triangles[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych ścian
					GLfloat nv[3];
					Normal(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uśredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obsługuje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescale_normal == true)
				Normalize(n);
			glNormal3fv(n);
			glVertex3fv(&vertex[3 * triangles[3 * i + 0]]);

			// obliczanie wektora normalnego dla drugiego wierzchołka
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich ścian posiadających bie¿ący wierzchołek
			for (int j = 0; j < 20; j++)
				if (3 * triangles[3 * i + 1] == 3 * triangles[3 * j + 0] ||
					3 * triangles[3 * i + 1] == 3 * triangles[3 * j + 1] ||
					3 * triangles[3 * i + 1] == 3 * triangles[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych ścian
					GLfloat nv[3];
					Normal(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uśredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obsługuje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescale_normal == true)
				Normalize(n);
			glNormal3fv(n);
			glVertex3fv(&vertex[3 * triangles[3 * i + 1]]);

			// obliczanie wektora normalnego dla trzeciego wierzchołka
			n[0] = n[1] = n[2] = 0.0;

			// wyszukanie wszystkich ścian posiadających bie¿ący wierzchołek
			for (int j = 0; j < 20; j++)
				if (3 * triangles[3 * i + 2] == 3 * triangles[3 * j + 0] ||
					3 * triangles[3 * i + 2] == 3 * triangles[3 * j + 1] ||
					3 * triangles[3 * i + 2] == 3 * triangles[3 * j + 2])
				{
					// dodawanie wektorów normalnych poszczególnych ścian
					GLfloat nv[3];
					Normal(nv, j);
					n[0] += nv[0];
					n[1] += nv[1];
					n[2] += nv[2];
				}

			// uśredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obsługuje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescale_normal == true)
				Normalize(n);
			glNormal3fv(n);
			glVertex3fv(&vertex[3 * triangles[3 * i + 2]]);
		}
	else

		// generowanie obiektu "płaskiego" - jeden wektor normalny na ścianę
		for (int i = 0; i < 20; i++)
		{
			GLfloat n[3];
			Normal(n, i);

			// uśredniony wektor normalny jest normalizowany tylko, gdy biblioteka
			// obsługuje automatyczne skalowania jednostkowych wektorów normalnych
			if (rescale_normal == true)
				Normalize(n);
			glNormal3fv(n);
			glVertex3fv(&vertex[3 * triangles[3 * i + 0]]);
			glVertex3fv(&vertex[3 * triangles[3 * i + 1]]);
			glVertex3fv(&vertex[3 * triangles[3 * i + 2]]);
		}

	// koniec definicji obiektu
	glEnd();

	// skierowanie poleceñ do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

// zmiana wielkości okna

void Reshape(int width, int height)
{
	// obszar renderingu - całe okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bryły obcinania
	if (aspect == ASPECT_1_1)
	{
		// wysokość okna większa od wysokości okna
		if (width < height && width > 0)
			glFrustum(left, right, bottom*height / width, top*height / width, near, far);
		else

			// szerokość okna większa lub równa wysokości okna
			if (width >= height && height > 0)
				glFrustum(left*width / height, right*width / height, bottom, top, near, far);
	}
	else
		glFrustum(left, right, bottom, top, near, far);

	// generowanie sceny 3D
	Display();
}

// obsługa klawiatury

void Keyboard(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scale += 0.05;
	else

		// klawisz -
		if (key == '-' && scale > 0.05)
			scale -= 0.05;

	// narysowanie sceny
	Display();
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotatey -= 1;
		break;

		// kursor w górę
	case GLUT_KEY_UP:
		rotatex -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotatey += 1;
		break;

		// kursor w dół
	case GLUT_KEY_DOWN:
		rotatex += 1;
		break;
	}

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa przycisków myszki

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiętanie stanu lewego przycisku myszki
		button_state = state;

		// zapamiętanie poło¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

// obsługa ruchu kursora myszki

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		rotatey += 30 * (right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
		button_x = x;
		rotatex -= 30 * (top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
		button_y = y;
		glutPostRedisplay();
	}
}

// obsługa menu podręcznego

void Menu(int value)
{
	switch (value)
	{
		// materiał - mosiądz
	case BRASS:
		ambient = BrassAmbient;
		diffuse = BrassDiffuse;
		specular = BrassSpecular;
		shininess = BrassShininess;
		Display();
		break;

		// materiał - brąz
	case BRONZE:
		ambient = BronzeAmbient;
		diffuse = BronzeDiffuse;
		specular = BronzeSpecular;
		shininess = BronzeShininess;
		Display();
		break;

		// materiał - polerowany brąz
	case POLISHED_BRONZE:
		ambient = PolishedBronzeAmbient;
		diffuse = PolishedBronzeDiffuse;
		specular = PolishedBronzeSpecular;
		shininess = PolishedBronzeShininess;
		Display();
		break;

		// materiał - chrom
	case CHROME:
		ambient = ChromeAmbient;
		diffuse = ChromeDiffuse;
		specular = ChromeSpecular;
		shininess = ChromeShininess;
		Display();
		break;

		// materiał - miedź
	case COPPER:
		ambient = CopperAmbient;
		diffuse = CopperDiffuse;
		specular = CopperSpecular;
		shininess = CopperShininess;
		Display();
		break;

		// materiał - polerowana miedź
	case POLISHED_COPPER:
		ambient = PolishedCopperAmbient;
		diffuse = PolishedCopperDiffuse;
		specular = PolishedCopperSpecular;
		shininess = PolishedCopperShininess;
		Display();
		break;

		// materiał - złoto
	case GOLD:
		ambient = GoldAmbient;
		diffuse = GoldDiffuse;
		specular = GoldSpecular;
		shininess = GoldShininess;
		Display();
		break;

		// materiał - polerowane złoto
	case POLISHED_GOLD:
		ambient = PolishedGoldAmbient;
		diffuse = PolishedGoldDiffuse;
		specular = PolishedGoldSpecular;
		shininess = PolishedGoldShininess;
		Display();
		break;

		// materiał - grafit (cyna z ołowiem)
	case PEWTER:
		ambient = PewterAmbient;
		diffuse = PewterDiffuse;
		specular = PewterSpecular;
		shininess = PewterShininess;
		Display();
		break;

		// materiał - srebro
	case SILVER:
		ambient = SilverAmbient;
		diffuse = SilverDiffuse;
		specular = SilverSpecular;
		shininess = SilverShininess;
		Display();
		break;

		// materiał - polerowane srebro
	case POLISHED_SILVER:
		ambient = PolishedSilverAmbient;
		diffuse = PolishedSilverDiffuse;
		specular = PolishedSilverSpecular;
		shininess = PolishedSilverShininess;
		Display();
		break;

		// materiał - szmaragd
	case EMERALD:
		ambient = EmeraldAmbient;
		diffuse = EmeraldDiffuse;
		specular = EmeraldSpecular;
		shininess = EmeraldShininess;
		Display();
		break;

		// materiał - jadeit
	case JADE:
		ambient = JadeAmbient;
		diffuse = JadeDiffuse;
		specular = JadeSpecular;
		shininess = JadeShininess;
		Display();
		break;

		// materiał - obsydian
	case OBSIDIAN:
		ambient = ObsidianAmbient;
		diffuse = ObsidianDiffuse;
		specular = ObsidianSpecular;
		shininess = ObsidianShininess;
		Display();
		break;

		// materiał - perła
	case PEARL:
		ambient = PearlAmbient;
		diffuse = PearlDiffuse;
		specular = PearlSpecular;
		shininess = PearlShininess;
		Display();
		break;

		// metariał - rubin
	case RUBY:
		ambient = RubyAmbient;
		diffuse = RubyDiffuse;
		specular = RubySpecular;
		shininess = RubyShininess;
		Display();
		break;

		// materiał - turkus
	case TURQUOISE:
		ambient = TurquoiseAmbient;
		diffuse = TurquoiseDiffuse;
		specular = TurquoiseSpecular;
		shininess = TurquoiseShininess;
		Display();
		break;

		// materiał - czarny plastik
	case BLACK_PLASTIC:
		ambient = BlackPlasticAmbient;
		diffuse = BlackPlasticDiffuse;
		specular = BlackPlasticSpecular;
		shininess = BlackPlasticShininess;
		Display();
		break;

		// materiał - czarna guma
	case BLACK_RUBBER:
		ambient = BlackRubberAmbient;
		diffuse = BlackRubberDiffuse;
		specular = BlackRubberSpecular;
		shininess = BlackRubberShininess;
		Display();
		break;

		// wektory normalne - GLU_SMOOTH
	case NORMALS_SMOOTH:
		normals = NORMALS_SMOOTH;
		Display();
		break;

		// wektory normalne - GLU_FLAT
	case NORMALS_FLAT:
		normals = NORMALS_FLAT;
		Display();
		break;

		// obszar renderingu - całe okno
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjście
	case EXIT:
		exit(0);
	}
}

// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ

void ExtensionSetup()
{
	// pobranie numeru wersji biblioteki OpenGL
	const char *version = (char*)glGetString(GL_VERSION);

	// odczyt wersji OpenGL
	int major = 0, minor = 0;
	if (sscanf(version, "%d.%d", &major, &minor) != 2)
	{
#ifndef WIN32
		printf("Błędny format wersji OpenGL\n");
#else

		printf("Bledny format wersji OpenGL\n");
#endif

		exit(0);
	}

	// sprawdzenie czy jest co najmniej wersja 1.2
	if (major > 1 || minor >= 2)
		rescale_normal = true;
	else
		// sprawdzenie czy jest obsługiwane rozszerzenie EXT_rescale_normal
		if (glutExtensionSupported("GL_EXT_rescale_normal"))
			rescale_normal = true;
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// rozmiary głównego okna programu
	glutInitWindowSize(500, 500);

	// utworzenie głównego okna programu
	glutCreateWindow("Wektory normalne");

	// dołączenie funkcji generującej scenę 3D
	glutDisplayFunc(Display);

	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);

	// dołączenie funkcji obsługi klawiatury
	glutKeyboardFunc(Keyboard);

	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys);

	// obsługa przycisków myszki
	glutMouseFunc(MouseButton);

	// obsługa ruchu kursora myszki
	glutMotionFunc(MouseMotion);

	// utworzenie menu podręcznego
	glutCreateMenu(Menu);

	// utworzenie podmenu - Materiał
	int MenuMaterial = glutCreateMenu(Menu);
#ifdef WIN32

	glutAddMenuEntry("Mosiądz", BRASS);
	glutAddMenuEntry("Brąz", BRONZE);
	glutAddMenuEntry("Polerowany brąz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedź", COPPER);
	glutAddMenuEntry("Polerowana miedź", POLISHED_COPPER);
	glutAddMenuEntry("Złoto", GOLD);
	glutAddMenuEntry("Polerowane złoto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Perła", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#else

	glutAddMenuEntry("Mosiadz", BRASS);
	glutAddMenuEntry("Braz", BRONZE);
	glutAddMenuEntry("Polerowany braz", POLISHED_BRONZE);
	glutAddMenuEntry("Chrom", CHROME);
	glutAddMenuEntry("Miedz", COPPER);
	glutAddMenuEntry("Polerowana miedz", POLISHED_COPPER);
	glutAddMenuEntry("Zloto", GOLD);
	glutAddMenuEntry("Polerowane zloto", POLISHED_GOLD);
	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);
	glutAddMenuEntry("Srebro", SILVER);
	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);
	glutAddMenuEntry("Szmaragd", EMERALD);
	glutAddMenuEntry("Jadeit", JADE);
	glutAddMenuEntry("Obsydian", OBSIDIAN);
	glutAddMenuEntry("Perla", PEARL);
	glutAddMenuEntry("Rubin", RUBY);
	glutAddMenuEntry("Turkus", TURQUOISE);
	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);
	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);
#endif

	// utworzenie podmenu - Wektory normalne
	int MenuNormals = glutCreateMenu(Menu);
#ifndef WIN32

	glutAddMenuEntry("Jeden wektor normalny na wierzcholek", NORMALS_SMOOTH);
	glutAddMenuEntry("Jeden wektor normalny na sciane", NORMALS_FLAT);
#else

	glutAddMenuEntry("Jeden wektor normalny na wierzchołek", NORMALS_SMOOTH);
	glutAddMenuEntry("Jeden wektor normalny na ścianę", NORMALS_FLAT);
#endif

	// utworzenie podmenu - aspekt obrazu
	int MenuAspect = glutCreateMenu(Menu);
#ifndef WIN32

	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
#else

	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu główne
	glutCreateMenu(Menu);

#ifdef WIN32

	glutAddSubMenu("Materiał", MenuMaterial);
#else

	glutAddSubMenu("Material", MenuMaterial);
#endif

	glutAddSubMenu("Wektory normalne", MenuNormals);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
#ifndef WIN32

	glutAddMenuEntry("Wyjście", EXIT);
#else

	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	// określenie przycisku myszki obsługującej menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ
	ExtensionSetup();

	// wprowadzenie programu do obsługi pętli komunikatów
	glutMainLoop();
	return 0;
}




