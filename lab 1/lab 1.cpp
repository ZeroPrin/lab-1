
#include <GL/glew.h>
#include <iostream>
#include <GL/glut.h>
#include <glm/vec3.hpp>

GLuint VBO; // указатель на буфер вершин

void RenderSceneCB() 
{
    glClear(GL_COLOR_BUFFER_BIT); // очистка

    glEnableVertexAttribArray(0);// индексация
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // снова привязка 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // передаём колво объектов и то, как их рисовать
    glDrawArrays(GL_TRIANGLES, 0, 3);// рисуем всё
    glDisableVertexAttribArray(0); // отключение индексации

    glutSwapBuffers(); // меняю буфер используемый с заготовленным

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv); // инициализация глут
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768); // создаем окно с параметрами размер и позиции
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ыыыыыыыыыы");// имя окна

    glutDisplayFunc(RenderSceneCB); // вызов функции 

    //glClearColor(0.6f, 0.2f, 0.3f, 0.4f); // смена цвета


    GLenum res = glewInit(); // инициализируем GLEW и проверяем на ошибки

    // правильно ли иницилизирован глут 

    if (res != GLEW_OK) // если нет, ошибка
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }


    glm::vec3 Vertices[3]; // инициализация точек
    Vertices[0] = glm::vec3(0.0f, 0.5f, 0.0f); // X Y Z
    Vertices[1] = glm::vec3(0.5f, 0.0f, 0.0f);
    Vertices[2] = glm::vec3(-0.5f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);// создаём буффер для помещения объетов
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // буфер будет хранить массив вершин
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // наполнение буфера данными
                                                               // источник для команд рисования 

    glutMainLoop(); // регулярный вызов отрисовки
}






