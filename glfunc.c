#include <windows.h>
#include <gl/gl.h>

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}


void show2Dtriangle(float theta)
{
    glPushMatrix();
    glTranslatef(-0.5f,0.0f,0.0f);
    glRotatef(-theta, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);
/*
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
*/
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex3f( 0.00f,  1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex3f( 0.87f, -0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex3f(-0.87f, -0.5f, 0.0f);
    glEnd();

    glPopMatrix();
}

void show2Dsquare(float theta)
{
    glPushMatrix();
    glTranslatef(0.5f,0.0f,0.0f);
    glRotatef(theta,0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
/*
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f,-0.5f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(0.5f,-0.5f);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(0.5f,0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.5f,0.5f);
*/
        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.5f,-0.5f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.0f); glVertex3f( 0.5f,-0.5f, 0.0f);
        glColor3f(0.0f, 1.0f, 1.0f); glVertex3f( 0.5f, 0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.0f);

    glEnd();
    glPopMatrix();
}


float theta = 0.0f;

void AnimateGL(HDC hDC)
{
    /* OpenGL animation code goes here */

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    show2Dtriangle(theta);
    show2Dsquare(theta);

    SwapBuffers(hDC);

    theta += 1.0f;
//    Sleep (10);
}
