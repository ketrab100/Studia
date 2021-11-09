/*************************************************************************************/

//  Szkielet programu do tworzenia modelu sceny 3-D z wizualizacj� osi 
//  uk�adu wsp�rz�dnych dla rzutowania perspektywicznego

/*************************************************************************************/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include<cmath>


typedef float point3[3];

static GLfloat viewer[] = { 0.0, 0.0, 10.0 };
// inicjalizacja po�o�enia obserwatora
static GLfloat radius = 0.0;
static GLfloat theta = 0.0;   // k�t obrotu obiektu

static GLfloat phi = 0.0;
static GLfloat pix2angle = 0.0;     // przelicznik pikseli na stopnie

static GLint statusl = 0;       // stan klawiszy myszy
                               // 0 - nie naci�ni�to �adnego klawisza
                               // 1 - naci�ni�ty zosta� lewy klawisz
static GLint statusr = 0;



static int x_pos_old = 0;       // poprzednia pozycja kursora myszy
static int y_pos_old = 0;
static int delta_x = 0;        // r�nica pomi�dzy pozycj� bie��c�
static int delta_y = 0;        // i poprzedni� kursora myszy

static int z_pos_old = 0;
static int delta_z = 0;


/*************************************************************************************/

// Funkcja rysuj�ca osie uk�adu wsp�?rz?dnych

typedef float point3[3];
int model = 3;  // 1- punkty, 2- siatka, 3 - wype�nione tr�jk�ty

/*************************************************************************************/
const int n = 20;
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
    point3 array[n][n];
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
        }
    }
    //rysowanie punktow
    if (model == 1)
    {
        glColor3f(1.0f, 1.0f, 0);
        glRotated(15, 1, 0, 0);
        glBegin(GL_POINTS);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                glVertex3fv(array[i][j]);
            }
        }
        glEnd();
    }
    //rysowanie siatki
    if (model == 2)
    {
        glColor3f(1.0f, 1.0f, 0);
        glRotated(15, 1, 0, 0);
        glBegin(GL_LINES);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                glVertex3fv(array[i][j]);
                glVertex3fv(array[(i + 1) % n][j]);
                if (j + 1 < n)
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[i][j + 1]);
                }
                else
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[(n - i) % n][0]);
                }
                if (j + 1 < n)
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[(i + 1) % n][j + 1]);
                }
                else
                {
                    glVertex3fv(array[i][j]);
                    glVertex3fv(array[(n - (i + 1)) % n][0]);
                }


            }
        }
        glEnd();
    }
    //rysowanie trojkatow
    if (model == 3)
    {
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (j + 1 < n)
                {
                    glColor3fv(colors[i][j]);
                    glVertex3fv(array[i][j]);
                    glColor3fv(colors[(i + 1) % n][j]);
                    glVertex3fv(array[(i + 1) % n][j]);
                    glColor3fv(colors[(i + 1) % n][j + 1]);
                    glVertex3fv(array[(i + 1) % n][j + 1]);
                }
                else
                {
                    glColor3fv(colors[i][j]);
                    glVertex3fv(array[i][j]);
                    glColor3fv(colors[(i + 1) % n][j]);
                    glVertex3fv(array[(i + 1) % n][j]);
                    glColor3fv(colors[(n - (i + 1)) % n][0]);
                    glVertex3fv(array[(n - (i + 1)) % n][0]);
                }
                if (j + 1 < n)
                {
                    glColor3fv(colors[i][j]);
                    glVertex3fv(array[i][j]);
                    glColor3fv(colors[i][j + 1]);
                    glVertex3fv(array[i][j + 1]);
                    glColor3fv(colors[(i + 1) % n][j + 1]);
                    glVertex3fv(array[(i + 1) % n][j + 1]);
                }
                else
                {
                    glColor3fv(colors[i][j]);
                    glVertex3fv(array[i][j]);
                    glColor3fv(colors[(n - i) % n][0]);
                    glVertex3fv(array[(n - i) % n][0]);
                    glColor3fv(colors[(n - (i + 1)) % n][0]);
                    glVertex3fv(array[(n - (i + 1)) % n][0]);
                }
            }
        }
        glEnd();
    }

}


void Axes(void)
{

    point3  x_min = { -5.0, 0.0, 0.0 };
    point3  x_max = { 5.0, 0.0, 0.0 };
    // pocz?tek i koniec obrazu osi x

    point3  y_min = { 0.0, -5.0, 0.0 };
    point3  y_max = { 0.0,  5.0, 0.0 };
    // pocz?tek i koniec obrazu osi y

    point3  z_min = { 0.0, 0.0, -5.0 };
    point3  z_max = { 0.0, 0.0,  5.0 };
    //  pocz?tek i koniec obrazu osi y

    glColor3f(1.0f, 0.0f, 0.0f);  // kolor rysowania osi - czerwony
    glBegin(GL_LINES); // rysowanie osi x

    glVertex3fv(x_min);
    glVertex3fv(x_max);

    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);  // kolor rysowania - zielony
    glBegin(GL_LINES);  // rysowanie osi y

    glVertex3fv(y_min);
    glVertex3fv(y_max);

    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);  // kolor rysowania - niebieski
    glBegin(GL_LINES); // rysowanie osi z

    glVertex3fv(z_min);
    glVertex3fv(z_max);

    glEnd();

}


/*************************************************************************************/
// Funkcja "bada" stan myszy i ustawia warto�ci odpowiednich zmiennych globalnych

void Mouse(int btn, int state, int x, int y)
{


    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x_pos_old = x;        // przypisanie aktualnie odczytanej pozycji kursora
                                // jako pozycji poprzedniej
        statusl = 1;          // wci�ni�ty zosta� lewy klawisz myszy

        y_pos_old = y;
    }
    else
        statusl = 0;          // nie zosta� wci�ni�ty �aden klawisz

    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        z_pos_old = y;
        statusr = 1;
    }
    else
        statusr = 0;
}

/*************************************************************************************/
// Funkcja "monitoruje" po�o�enie kursora myszy i ustawia warto�ci odpowiednich
// zmiennych globalnych

void Motion(GLsizei x, GLsizei y)
{

    delta_x = x - x_pos_old;     // obliczenie r�nicy po�o�enia kursora myszy

    x_pos_old = x;            // podstawienie bie��cego po�o�enia jako poprzednie

    delta_y = y - y_pos_old;

    y_pos_old = y;


    delta_z = y - z_pos_old;
    z_pos_old = y;

    glutPostRedisplay();     // przerysowanie obrazu sceny
}

/*************************************************************************************/



/*************************************************************************************/

// Funkcja okre�laj�ca co ma by� rysowane (zawsze wywo�ywana, gdy trzeba
// przerysowa� scen�)



void RenderScene(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Czyszczenie okna aktualnym kolorem czyszcz�cym

    glLoadIdentity();
    // Czyszczenie macierzy bie??cej

    if (statusr == 1)
    {
       radius += delta_z;
       if (radius > 15)
       {
           radius = 15;
       }
       if (radius < 0.5)
       {
           radius = 0.5;
       }
    }

    
    // Zdefiniowanie po�o�enia obserwatora

    Axes();
    // Narysowanie osi przy pomocy funkcji zdefiniowanej powy�ej 

    if (statusl == 1)                     // je�li lewy klawisz myszy wci�ni�ty
    {
        theta += delta_x * pix2angle/100;    // modyfikacja k�ta obrotu o kat proporcjonalny
        phi += delta_y * pix2angle/100;      // do r�nicy po�o�e� kursora myszy
    }         

    viewer[0] = radius * cos(theta) * cos(phi);
    viewer[1] = radius * sin(phi);
    viewer[2] = radius * sin(theta) * cos(phi);

    gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    glColor3f(1.0f, 1.0f, 1.0f);
    // Ustawienie koloru rysowania na bia�y

    Egg();
    // Narysowanie czajnika 

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

    glutDisplayFunc(RenderScene);
    // Okre�lenie, �e funkcja RenderScene b�dzie funkcj� zwrotn�
    // (callback function).  B�dzie ona wywo�ywana za ka�dym razem
    // gdy zajdzie potrzeba przerysowania okna

    glutMouseFunc(Mouse);
    // Ustala funkcj� zwrotn� odpowiedzialn� za badanie stanu myszy

    glutMotionFunc(Motion);
    // Ustala funkcj� zwrotn� odpowiedzialn� za badanie ruchu myszy



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