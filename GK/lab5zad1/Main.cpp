/*************************************************************************************/

//  Szkielet programu do tworzenia modelu sceny 3-D z wizualizacj� osi
//  uk�adu wsp�rz�dnych dla rzutowania perspektywicznego

/*************************************************************************************/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <cmath>
#include <iostream>


static GLfloat theta1 = 0.0;   // k�t obrotu obiektu y
static GLfloat phi1 = 0.0;  // k�t obrotu obiektu x
static GLfloat theta2 = 0.0;   // k�t obrotu obiektu y
static GLfloat phi2 = 0.0;  // k�t obrotu obiektu x
static GLfloat pix2angle;     // przelicznik pikseli na stopnie

static double pi = 3.1415926;

static GLint status = 0;       // stan klawiszy myszy
  // 0 - nie naci�ni�to �adnego klawisza
  // 1 - naci�ni�ty zosta� lewy klawisz
  // 2 - naci�ni�ty zosta� prawy klawisz

static int x_pos_old = 0;       // poprzednia pozycja kursora myszy
static int y_pos_old = 0;

static int delta_x = 0;        // r�nica pomi�dzy pozycj� bie��c�
 // i poprzedni� kursora myszy
static int delta_y = 0;

static float radius = 15;

typedef float point3[3];


static GLfloat light1[] = { 0.0, 0.0, 15.0 };
static GLfloat light2[] = { 0.0, 0.0, 15.0 };
// inicjalizacja po�o�enia obserwatora

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
// Funkcja "bada" stan myszy i ustawia warto�ci odpowiednich zmiennych globalnych
void Mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		x_pos_old = x;       // przypisanie aktualnie odczytanej pozycji kursora
		// jako pozycji poprzedniej
		y_pos_old = y;

		status = 1;          // wci�ni�ty zosta� lewy klawisz myszy
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
		status = 0;          // nie zosta� wci�ni�ty �aden klawisz
	}
}

/*************************************************************************************/
// Funkcja "monitoruje" po�o�enie kursora myszy i ustawia warto�ci odpowiednich
// zmiennych globalnych
void Motion(GLsizei x, GLsizei y)
{
	delta_x = x - x_pos_old;     // obliczenie r�nicy po�o�enia kursora myszy
	delta_y = y - y_pos_old;

	x_pos_old = x;            // podstawienie bie��cego po�o�enia jako poprzednie
	y_pos_old = y;

	glutPostRedisplay();     // przerysowanie obrazu sceny
}


/*************************************************************************************/
// Funkcja okre�laj�ca co ma by� rysowane (zawsze wywo�ywana, gdy trzeba
// przerysowa� scen�)
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszcz�cym

	glLoadIdentity();
	// Czyszczenie macierzy bie??cej

	gluLookAt(10, 0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// Zdefiniowanie po�o�enia obserwatora


	if (status == 1)                     // je�li lewy klawisz myszy wci�ni�ty
	{
		theta1 += delta_x * pix2angle / 100;    // modyfikacja k�ta obrotu o kat proporcjonalny
		// do r�nicy po�o�e� kursora myszy

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
		theta2 += delta_x * pix2angle / 100;    // modyfikacja k�ta obrotu o kat proporcjonalny
		// do r�nicy po�o�e� kursora myszy

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
	// Przekazanie polece� rysuj�cych do wykonania
	glutSwapBuffers();

}



/*************************************************************************************/
// Funkcja ustalaj�ca stan renderowania
void MyInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Kolor czyszcz�cy (wype�nienia okna) ustawiono na czarny

	/*************************************************************************************/

	//  Definicja materia�u z jakiego zrobiony jest czajnik
	//  i definicja �r�d�a �wiat�a

	/*************************************************************************************/


	/*************************************************************************************/
	// Definicja materia�u z jakiego zrobiony jest czajnik

	GLfloat mat_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	// wsp�czynniki ka =[kar,kag,kab] dla �wiat�a otoczenia

	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	// wsp�czynniki kd =[kdr,kdg,kdb] �wiat�a rozproszonego

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	// wsp�czynniki ks =[ksr,ksg,ksb] dla �wiat�a odbitego              

	GLfloat mat_shininess = { 20.0 };
	// wsp�czynnik n opisuj�cy po�ysk powierzchni

	/*************************************************************************************/
	// Definicja �r�d�a �wiat�a

	GLfloat light_position[] = { light1[0], light1[1], light1[2], 1.0 };
	// po�o�enie �r�d�a


	GLfloat light_ambient1[] = { 1, 0.0, 0.0, 1.0 };
	GLfloat light_ambient2[] = { 0.0, 0.0, 1, 1.0 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a otoczenia
	// Ia = [Iar,Iag,Iab]

	GLfloat light_diffuse1[] = { 1, 0, 0, 1 };
	GLfloat light_diffuse2[] = { 0, 0, 1, 1 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a powoduj�cego
	// odbicie dyfuzyjne Id = [Idr,Idg,Idb]

	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a powoduj�cego
	// odbicie kierunkowe Is = [Isr,Isg,Isb]

	GLfloat att_constant = { 1.0 };
	// sk�adowa sta�a ds dla modelu zmian o�wietlenia w funkcji
	// odleg�o�ci od �r�d�a

	GLfloat att_linear = { 0.001 };
	// sk�adowa liniowa dl dla modelu zmian o�wietlenia w funkcji
	// odleg�o�ci od �r�d�a

	GLfloat att_quadratic = { 0.001 };
	// sk�adowa kwadratowa dq dla modelu zmian o�wietlenia w funkcji
	// odleg�o�ci od �r�d�a

	/*************************************************************************************/
	// Ustawienie parametr�w materia�u i �r�d�a �wiat�a

	/*************************************************************************************/
	// Ustawienie patrametr�w materia�u


	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	/*************************************************************************************/
	// Ustawienie parametr�w �r�d�a

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
	// Ustawienie opcji systemu o�wietlania sceny

	glShadeModel(GL_SMOOTH); // w�aczenie �agodnego cieniowania
	glEnable(GL_LIGHTING);   // w�aczenie systemu o�wietlenia sceny
	glEnable(GL_LIGHT0);     // w��czenie �r�d�a o numerze 0
	glEnable(GL_LIGHT1);	 // w��czenie �r�d�a o numerze 1
	glEnable(GL_DEPTH_TEST); // w��czenie mechanizmu z-bufora

	/*************************************************************************************/
}

/*************************************************************************************/
// Funkcja ma za zadanie utrzymanie sta�ych proporcji rysowanych
// w przypadku zmiany rozmiar�w okna.
// Parametry vertical i horizontal (wysoko�� i szeroko�� okna) s�
// przekazywane do funkcji za ka�dym razem gdy zmieni si� rozmiar okna.
void ChangeSize(GLsizei horizontal, GLsizei vertical)
{
	pix2angle = 360.0 / (float)horizontal;  // przeliczenie pikseli na stopnie

	glMatrixMode(GL_PROJECTION);
	// Prze��czenie macierzy bie��cej na macierz projekcji

	glLoadIdentity();
	// Czyszcznie macierzy bie��cej

	gluPerspective(70, 1.0, 1.0, 30.0);
	// Ustawienie parametr�w dla rzutu perspektywicznego


	if (horizontal <= vertical)
		glViewport(0, (vertical - horizontal) / 2, horizontal, horizontal);

	else
		glViewport((horizontal - vertical) / 2, 0, vertical, vertical);
	// Ustawienie wielko�ci okna okna widoku (viewport) w zale�no�ci
	// relacji pomi�dzy wysoko�ci� i szeroko�ci� okna

	glMatrixMode(GL_MODELVIEW);
	// Prze��czenie macierzy bie��cej na macierz widoku modelu  

	glLoadIdentity();
	// Czyszczenie macierzy bie��cej
}

/*************************************************************************************/
// G��wny punkt wej�cia programu. Program dzia�a w trybie konsoli
void main(void)
{
	randomColors();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Rzutowanie perspektywiczne");

	glutMouseFunc(Mouse);
	// Ustala funkcj� zwrotn� odpowiedzialn� za badanie stanu myszy

	glutMotionFunc(Motion);
	// Ustala funkcj� zwrotn� odpowiedzialn� za badanie ruchu myszy

	glutDisplayFunc(RenderScene);
	// Okre�lenie, �e funkcja RenderScene b�dzie funkcj� zwrotn�
	// (callback function).  B�dzie ona wywo�ywana za ka�dym razem
	// gdy zajdzie potrzeba przerysowania okna


	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcj� zwrotn� odpowiedzialn�
	// za zmiany rozmiaru okna                      


	MyInit();
	// Funkcja MyInit() (zdefiniowana powy�ej) wykonuje wszelkie
	// inicjalizacje konieczne  przed przyst�pieniem do renderowania
	glEnable(GL_DEPTH_TEST);
	// W��czenie mechanizmu usuwania niewidocznych element�w sceny

	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT
}

/*************************************************************************************/