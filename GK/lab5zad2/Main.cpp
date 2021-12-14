#include <windows.h>
#include <cmath>
#include <math.h>
#include <gl/gl.h>
#include <gl/glut.h>


typedef float point3[3];
int model = 2;
static GLfloat theta[] = { 0.0, 0.0, 0.0 }; // trzy k�ty obrotu

/*************************************************************************************/
const int n = 150;
//tablica zawierajaca informacje o kolorach
point3 colors[n][n];
float pi = 3.1415;
point3 yello = { 0,1,1 };

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
				x /= vectorLen;
				y /= vectorLen;
				z /= vectorLen;
			}

			if (i < (n / 2) - (n / 16))
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

// Funkcja okre�laj�ca co ma by� rysowane (zawsze wywo�ywana gdy trzeba
// przerysowa� scen�)
void RenderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszcz�cym

	glLoadIdentity();
	// Czyszczenie macierzy bie��cej

	// Narysowanie osi przy pomocy funkcji zdefiniowanej wy�ej
	glRotatef(theta[0], 1.0, 0.0, 0.0);

	glRotatef(theta[1], 0.0, 1.0, 0.0);

	glRotatef(theta[2], 0.0, 0.0, 1.0);

	if (model == 1)
	{
		glutSolidTeapot(3);
	}
	else if (model == 2)
	{
		Egg();
	}


	glFlush();
	// Przekazanie polece� rysuj�cych do wykonania



	glutSwapBuffers();

}


void keys(unsigned char key, int x, int y)
{
	if (key == 't') model = 1;
	if (key == 'e') model = 2;
	RenderScene(); // przerysowanie obrazu sceny
}

/*************************************************************************************/

void spinEgg()
{
	theta[0] -= 0.5;
	if (theta[0] > 360.0) theta[0] -= 360.0;

	theta[1] -= 0.5;
	if (theta[1] > 360.0) theta[1] -= 360.0;

	theta[2] -= 0.5;
	if (theta[2] > 360.0) theta[2] -= 360.0;

	glutPostRedisplay(); //od�wie�enie zawarto�ci aktualnego okna
}

// Funkcja ustalaj�ca stan renderowania



void MyInit(void)
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Kolor czyszc�cy (wype�nienia okna) ustawiono na czarny
	/*************************************************************************************/

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

	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	// po�o�enie �r�d�a


	GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 1.0 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a otoczenia
	// Ia = [Iar,Iag,Iab]

	GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a powoduj�cego
	// odbicie dyfuzyjne Id = [Idr,Idg,Idb]

	GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0 };
	// sk�adowe intensywno�ci �wiecenia �r�d�a �wiat�a powoduj�cego
	// odbicie kierunkowe Is = [Isr,Isg,Isb]

	GLfloat att_constant = { 1.0 };
	// sk�adowa sta�a ds dla modelu zmian o�wietlenia w funkcji
	// odleg�o�ci od �r�d�a

	GLfloat att_linear = { 0.05 };
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

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, att_constant);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, att_linear);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, att_quadratic);


	/*************************************************************************************/
	// Ustawienie opcji systemu o�wietlania sceny

	glShadeModel(GL_SMOOTH); // w�aczenie �agodnego cieniowania
	glEnable(GL_LIGHTING);   // w�aczenie systemu o�wietlenia sceny
	glEnable(GL_LIGHT0);     // w��czenie �r�d�a o numerze 0
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

	GLfloat AspectRatio;
	// Deklaracja zmiennej AspectRatio  okre�laj�cej proporcj�
	// wymiar�w okna

	if (vertical == 0)  // Zabezpieczenie przed dzieleniem przez 0

		vertical = 1;

	glViewport(0, 0, horizontal, vertical);
	// Ustawienie wielko�ciokna okna widoku (viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)  

	glMatrixMode(GL_PROJECTION);
	// Prze��czenie macierzy bie��cej na macierz projekcji

	glLoadIdentity();
	// Czyszcznie macierzy bie��cej            

	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
	// Wyznaczenie wsp�czynnika  proporcji okna
	// Gdy okno nie jest kwadratem wymagane jest okre�lenie tak zwanej
	// przestrzeni ograniczaj�cej pozwalaj�cej zachowa� w�a�ciwe
	// proporcje rysowanego obiektu.
	// Do okreslenia przestrzeni ograniczj�cej s�u�y funkcja
	// glOrtho(...)            

	if (horizontal <= vertical)

		glOrtho(-7.5, 7.5, -7.5 / AspectRatio, 7.5 / AspectRatio, 10.0, -10.0);

	else

		glOrtho(-7.5 * AspectRatio, 7.5 * AspectRatio, -7.5, 7.5, 10.0, -10.0);

	glMatrixMode(GL_MODELVIEW);
	// Prze��czenie macierzy bie��cej na macierz widoku modelu                                    

	glLoadIdentity();
	// Czyszcenie macierzy bie��cej

}

/*************************************************************************************/

// G��wny punkt wej�cia programu. Program dzia�a w trybie konsoli



void main(void)
{
	//randomColors();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300, 300);

	glutCreateWindow("Jajko");

	glutKeyboardFunc(keys);

	glutIdleFunc(spinEgg);

	glutDisplayFunc(RenderScene);
	// Okre�lenie, �e funkcja RenderScene b�dzie funkcj� zwrotn�
	// (callback function).  Bedzie ona wywo�ywana za ka�dym razem
	// gdy zajdzie potrzba przeryswania okna

	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcj� zwrotn� odpowiedzialn�
	// zazmiany rozmiaru okna      

	MyInit();
	// Funkcja MyInit() (zdefiniowana powy�ej) wykonuje wszelkie
	// inicjalizacje konieczne  przed przyst�pieniem do renderowania

	glEnable(GL_DEPTH_TEST);
	// W��czenie mechanizmu usuwania powierzchni niewidocznych

	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT

}

/*************************************************************************************/