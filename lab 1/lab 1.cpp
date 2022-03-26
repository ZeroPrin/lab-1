#include <GL/glut.h>
#include <iostream>

void RenderSceneCB() 
{
    glClear(GL_COLOR_BUFFER_BIT); // очистка вроде
    glutSwapBuffers(); // меняю буфер используемый с заготовленным
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // инициализация глут
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768); // создаем окно с параметрами размер и позиции
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ыыыыыыыыыы");

    glutDisplayFunc(RenderSceneCB); // вызов функции 

    glClearColor(0.6f, 0.2f, 0.3f, 0.4f); // смена цвета

   

   
    glutMainLoop(); // ??? 


}

