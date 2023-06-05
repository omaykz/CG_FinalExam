#include <GL/glut.h>
#include <GL/gl.h>


void drawSphere(float radius, int slices, int stacks) {
    glColor3f(1.0f, 1.0f, 1.0f);  // 设置球体的颜色为白色
    GLUquadric* quadric = gluNewQuadric();
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);
}

void drawTable(float size) {
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glVertex3f(-size, -size + 1.0f, -size);
    glVertex3f(-size, -size + 1.0f, size);
    glVertex3f(size, -size + 1.0f, size);
    glVertex3f(size, -size + 1.0f, -size);
    glEnd();
}
void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 2.0f };
    GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f,2.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position[] = { 3.0f, 2.0f, 1.0f, 2.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat diffuseColor[] = { 0.8f, 0.8f, 0.8f, 1.0f };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // 设置背景颜色为白色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);  // 设置透视投影
    gluLookAt(0, 3, 10, 0, 0, 0, 0, 1, 0);  // 设置相机视图

    glRotatef(1, 1, 1, 1);

    glEnable(GL_COLOR_MATERIAL_FACE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    setupLighting();

    glColor3f(1, 0, 0);
    drawSphere(1.0f, 50, 50);

    glColor3f(0.5f, 0.5f, 0.5f);
    drawTable(2.5f);


    glPushMatrix();


    glDisable(GL_LIGHTING);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f);
    drawSphere(1.0f, 50, 50);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Sphere");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}