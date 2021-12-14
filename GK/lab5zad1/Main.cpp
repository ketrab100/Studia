/*************************************************************************************/

//  Szkielet programu do tworzenia modelu sceny 3-D z wizualizacj¹ osi
//  uk³adu wspó³rzêdnych dla rzutowania perspektywicznego

/*************************************************************************************/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <cmath>
#include <iostream>


static GLfloat theta1 = 0.0;   // k¹t obrotu obiektu y
static GLfloat phi1 = 0.0;  // k¹t obrotu obiektu x
static GLfloat theta2 = 0.0;   // k¹t obrotu obiektu y
static GLfloat phi2 = 0.0;  // k¹t obrotu obiektu x
static GLfloat pix2angle;     // przelicznik pikseli na stopnie

static double pi = 3.1415926;

static GLint status = 0;       // stan klawiszy myszy
  // 0 - nie naciœniêto ¿adnego klawisza
  // 1 - naciœniêty zostaæ lewy klawisz
  // 2 - naciœniêty zosta³ prawy klawisz

static int x_pos_old = 0;       // poprzednia pozycja kursora myszy
static int y_pos_old = 0;

static int delta_x = 0;        // ró¿nica pomiêdzy pozycj¹ bie¿¹c¹
 // i poprzedni¹ kursora myszy
static int delta_y = 0;

static float radius = 15;

typedef float point3[3];


static GLfloat light1[] = { 0.0, 0.0, 15.0 };
static GLfloat light2[] = { 0.0, 0.0, 15.0 };
// inicjalizacja po³o¿enia obserwatora

const int n = 50;
//tablica zawierajaca informacje o kolorach
point3 colors[n][n];

//Funkcja wypelniajaca tablice losowymi kolorami
void randomColors()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			colors[i][j][0] = float(rand() % 101) / 100;
			colors[i][j][1] = float(rand() % 101) / 100;
			colors[i][j][2] = float(rand() % 101) / 100;
		}
	}
}

//Funkcja rysujaca jajko
void Egg(void)
{
	// tablica punktow
	point3 array[n][n];
	point3 normal[n][n];
	float u, v;
	//generowanie wspolrzednych punktow w 3D
	for (int i = 0; i < n; i++)
	{
		u = float(i) / n;
		for (int j = 0; j < n; j++)
		{
			v = float(j) / n;
			array[i][j][0] = (-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * cos(3.14 * v);
			array[i][j][1] = 160 * pow(u, 4) - 320 * pow(u, 3) + 160 * pow(u, 2) - 3.5f;
			array[i][j][2] = (-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * sin(3.14 * v);

			float xu, xv, yu, yv, zu, zv;
			xu = (-450 * pow(u, 4) + 900 * pow(u, 3) - 810 * pow(u, 2) + 360 * u - 45) * cos(pi * v);
			xv = pi * (90 * pow(u, 5) - 255 * pow(u, 4) + 270 * pow(u, 3) - 180 * pow(u, 2) + 45 * u) * sin(pi * v);
			yu = 640 * pow(u, 3) - 960 * pow(u, 2) + 320 * u;
			yv = 0;
			zu = (-450 * pow(u, 4) + 900 * pow(u, 3) - 810 * pow(u, 2) + 360 * u - 45) * sin(pi * v);
			zv = -pi * (90 * pow(u, 5) - 255 * pow(u, 4) + 270 * pow(u, 3) - 180 * pow(u, 2) + 45 * u) * cos(pi * v);

			float x, y, z;
			x = yu * zv - zu * yv;
			y = zu * xv - xu * zv;
			z = xu * yv - yu * xv;

			float vectorLen;
			vectorLen = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

			if (vectorLen != 0)
			{
				x /= vectorLen * -1;
				y /= vectorLen * -1;
				z /= vectorLen * -1;
			}

			if (i < (n / 2) - (n / 10) + 1)
			{
				x *= -1;
				y *= -1;
				z *= -1;
			}

			normal[i][j][0] = x;
			normal[i][j][1] = y;
			normal[i][j][2] = z;

		}
	}
	//rysowanie punktow
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				glNormal3fv(normal[i][j]);
				glVertex3fv(array[i][j]);
				glNormal3fv(normal[(i + 1) % n][j]);
				glVertex3fv(array[(i + 1) % n][j]);
				glNormal3fv(normal[(i + 1) % n][j + 1]);
				glVertex3fv(array[(i + 1) % n][j + 1]);
			}
			else
			{
				//laczenie trojkatow w osi poziomej
				glNormal3fv(normal[i][j]);
				glVertex3fv(array[i][j]);
				glNormal3fv(normal[(i + 1) % n][j]);
				glVertex3fv(array[(i + 1) % n][j]);
				glNormal3fv(normal[(n - (i + 1)) % n][0]);
				glVertex3fv(array[(n - (i + 1)) % n][0]);
			}
			if (j + 1 < n)
			{
				glNormal3fv(normal[i][j]);
				glVertex3fv(array[i][j]);
				glNormal3fv(normal[i][j + 1]);
				glVertex3fv(array[i][j + 1]);
				glNormal3fv(normal[(i + 1) % n][j + 1]);
				glVertex3fv(array[(i + 1) % n][j + 1]);
			}
			else
			{
				//laczenie trojkatow w osi poziomej
				glNormal3fv(normal[i][j]);
				glVertex3fv(array[i][j]);
				glNormal3fv(normal[(n - i) % n][0]);
				glVertex3fv(array[(n - i) % n][0]);
				glNormal3fv(normal[(n - (i + 1)) % n][0]);
				glVertex3fv(array[(n - (i + 1)) % n][0]);
			}
		}
	}
	glEnd();

}
/*************************************************************************************/
// Funkcja "bada" stan myszy i ustawia wartoœci odpowiednich zmiennych globalnych
void Mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x_pos_old = x;       // przypisanie aktualnie odczytanej pozycji kursora
		// jako pozycji poprzedniej
		y_pos_old = y;

		status = 1;          // wciêniêty zosta³ lewy klawisz myszy
	}
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		x_pos_old = x;       // przypisanie aktualnie odczytanej pozycji kursora
		// jako pozycji poprzedniej
		y_pos_old = y;

		status = 2;
	}
	else
	{
		status = 0;          // nie zosta³ wciêniêty ¿aden klawisz
	}
}

/*************************************************************************************/
// Funkcja "monitoruje" po³o¿enie kursora myszy i ustawia wartoœci odpowiednich
// zmiennych globalnych
void Motion(GLsizei x, GLsizei y)
{
	delta_x = x - x_pos_old;     // obliczenie ró¿nicy po³o¿enia kursora myszy
	delta_y = y - y_pos_old;

	x_pos_old = x;            // podstawienie bie¿¹cego po³o¿enia jako poprzednie
	y_pos_old = y;

	glutPostRedisplay();     // przerysowanie obrazu sceny
}


/*************************************************************************************/
// Funkcja okreœlaj¹ca co ma byæ rysowane (zawsze wywo³ywana, gdy trzeba
// przerysowaæ scenê)
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszcz¹cym

	glLoadIdentity();
	// Czyszczenie macierzy bie??cej

	gluLookAt(10, 0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// Zdefiniowanie po³o¿enia obserwatora


	if (status == 1)                     // jeœli lewy klawisz myszy wciêniêty
	{
		theta1 += delta_x * pix2angle / 100;    // modyfikacja k¹ta obrotu o kat proporcjonalny
		// do ró¿nicy po³o¿eñ kursora myszy

		phi1 += delta_y * pix2angle / 100;

		if (phi1 > pi / 2)
		{
			phi1 = pi / 2;
		}
		if (phi1 < -pi / 2)
		{
			phi1 = -pi / 2;
		}
	}
	if (status == 2)
	{
		theta2 += delta_x * pix2angle / 100;    // modyfikacja k¹ta obrotu o kat proporcjonalny
		// do ró¿nicy po³o¿eñ kursora myszy

		phi2 += delta_y * pix2angle / 100;

		if (phi2 > pi / 2)
		{
			phi2 = pi / 2;
		}
		if (phi2 < -pi / 2)
		{
			phi2 = -pi / 2;
		}
	}

	light1[0] = radius * cos(theta1) * cos(phi1);
	light1[1] = radius * sin(phi1);
	light1[2] = radius * sin(theta1) * cos(phi1);

	light2[0] = radius * cos(theta2) * cos(phi2);
	light2[1] = radius * sin(phi2);
	light2[2] = radius * sin(theta2) * cos(phi2);



	Egg();
	GLfloat light_position1[] = { light1[0], light1[1], light1[2], 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);

	GLfloat light_position2[] = { light2[0], light2[1], light2[2], 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
	// Narysowanie jajka
	glFlush();
	// Przekazanie poleceñ rysuj¹cych do wykonania
	glutSwapBuffers();

}



/*************************************************************************************/
// Funkcja ustalaj¹ca stan renderowania
void MyInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Kolor czyszcz¹cy (wype³nienia okna) ustawiono na czarny

	/*************************************************************************************/

	//  Definicja materia³u z jakiego zrobiony jest czajnik
	//  i definicja Ÿród³a œwiat³a

	/*************************************************************************************/


	/*************************************************************************************/
	// Definicja materia³u z jakiego zrobiony jest czajnik

	GLfloat mat_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	// wspó³czynniki ka =[kar,kag,kab] dla œwiat³a otoczenia

	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	// wspó³czynniki kd =[kdr,kdg,kdb] œwiat³a rozproszonego

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	// wspó³czynniki ks =[ksr,ksg,ksb] dla œwiat³a odbitego              

	GLfloat mat_shininess = { 20.0 };
	// wspó³czynnik n opisuj¹cy po³ysk powierzchni

	/*************************************************************************************/
	// Definicja Ÿród³a œwiat³a

	GLfloat light_position[] = { light1[0], light1[1], light1[2], 1.0 };
	// po³o¿enie Ÿród³a


	GLfloat light_ambient1[] = { 1, 0.0, 0.0, 1.0 };
	GLfloat light_ambient2[] = { 0.0, 0.0, 1, 1.0 };
	// sk³adowe intensywnoœci œwiecenia Ÿród³a œwiat³a otoczenia
	// Ia = [Iar,Iag,Iab]

	GLfloat light_diffuse1[] = { 1, 0, 0, 1 };
	GLfloat light_diffuse2[] = { 0, 0, 1, 1 };
	// sk³adowe intensywnoœci œwiecenia Ÿród³a œwiat³a powoduj¹cego
	// odbicie dyfuzyjne Id = [Idr,Idg,Idb]

	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1 };
	// sk³adowe intensywnoœci œwiecenia Ÿród³a œwiat³a powoduj¹cego
	// odbicie kierunkowe Is = [Isr,Isg,Isb]

	GLfloat att_constant = { 1.0 };
	// sk³adowa sta³a ds dla modelu zmian oœwietlenia w funkcji
	// odleg³oœci od Ÿród³a

	GLfloat att_linear = { 0.001 };
	// sk³adowa liniowa dl dla modelu zmian oœwietlenia w funkcji
	// odleg³oœci od Ÿród³a

	GLfloat att_quadratic = { 0.001 };
	// sk³adowa kwadratowa dq dla modelu zmian oœwietlenia w funkcji
	// odleg³oœci od Ÿród³a

	/*************************************************************************************/
	// Ustawienie parametrów materia³u i Ÿród³a œwiat³a

	/*************************************************************************************/
	// Ustawienie patrametrów materia³u


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	/*************************************************************************************/
	// Ustawienie parametrów Ÿród³a

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, att_quadratic);


	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, att_quadratic);


	/*************************************************************************************/
	// Ustawienie opcji systemu oœwietlania sceny

	glShadeModel(GL_SMOOTH); // w³aczenie ³agodnego cieniowania
	glEnable(GL_LIGHTING);   // w³aczenie systemu oœwietlenia sceny
	glEnable(GL_LIGHT0);     // w³¹czenie Ÿród³a o numerze 0
	glEnable(GL_LIGHT1);	 // w³¹czenie Ÿród³a o numerze 1
	glEnable(GL_DEPTH_TEST); // w³¹czenie mechanizmu z-bufora

	/*************************************************************************************/
}

/*************************************************************************************/
// Funkcja ma za zadanie utrzymanie sta³ych proporcji rysowanych
// w przypadku zmiany rozmiarów okna.
// Parametry vertical i horizontal (wysokoœæ i szerokoœæ okna) s¹
// przekazywane do funkcji za ka¿dym razem gdy zmieni siê rozmiar okna.
void ChangeSize(GLsizei horizontal, GLsizei vertical)
{
	pix2angle = 360.0 / (float)horizontal;  // przeliczenie pikseli na stopnie

	glMatrixMode(GL_PROJECTION);
	// Prze³¹czenie macierzy bie¿¹cej na macierz projekcji

	glLoadIdentity();
	// Czyszcznie macierzy bie¿¹cej

	gluPerspective(70, 1.0, 1.0, 30.0);
	// Ustawienie parametrów dla rzutu perspektywicznego


	if (horizontal <= vertical)
		glViewport(0, (vertical - horizontal) / 2, horizontal, horizontal);

	else
		glViewport((horizontal - vertical) / 2, 0, vertical, vertical);
	// Ustawienie wielkoœci okna okna widoku (viewport) w zale¿noœci
	// relacji pomiêdzy wysokoœci¹ i szerokoœci¹ okna

	glMatrixMode(GL_MODELVIEW);
	// Prze³¹czenie macierzy bie¿¹cej na macierz widoku modelu  

	glLoadIdentity();
	// Czyszczenie macierzy bie¿¹cej
}

/*************************************************************************************/
// G³ówny punkt wejœcia programu. Program dzia³a w trybie konsoli
void main(void)
{
	randomColors();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Rzutowanie perspektywiczne");

	glutMouseFunc(Mouse);
	// Ustala funkcjê zwrotn¹ odpowiedzialn¹ za badanie stanu myszy

	glutMotionFunc(Motion);
	// Ustala funkcjê zwrotn¹ odpowiedzialn¹ za badanie ruchu myszy

	glutDisplayFunc(RenderScene);
	// Okreœlenie, ¿e funkcja RenderScene bêdzie funkcj¹ zwrotn¹
	// (callback function).  Bêdzie ona wywo³ywana za ka¿dym razem
	// gdy zajdzie potrzeba przerysowania okna


	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcjê zwrotn¹ odpowiedzialn¹
	// za zmiany rozmiaru okna                      


	MyInit();
	// Funkcja MyInit() (zdefiniowana powy¿ej) wykonuje wszelkie
	// inicjalizacje konieczne  przed przyst¹pieniem do renderowania
	glEnable(GL_DEPTH_TEST);
	// W³¹czenie mechanizmu usuwania niewidocznych elementów sceny

	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT
}

/*************************************************************************************/