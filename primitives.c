#include<GL/glut.h>
#include<stdio.h>

void output(){
    int i;
    while(1){
        printf("1.Vertex\n2.Line\n3.Line Strip\n4.Line Loop\n5.Triangles\n6.Triangle Strip\n7.Triangle Fan\n8.Quadrilateral\n9.Quad Strip\n10.Polygon\n");
        printf("Enter the choice:");
        scanf("%d",&i);
        glClear(GL_COLOR_BUFFER_BIT);
        switch(i){
            case 1:
                    glPointSize(7.0);
                    glBegin(GL_POINTS);
                    glVertex2f(0,0);
                    break;
            case 2:
                    glLineWidth(7);
                    glBegin(GL_LINES);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    break;
            case 3:
                    glLineWidth(7);
                    glBegin(GL_LINE_STRIP);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(0.5,0.5);
                    glVertex2f(-0.5,-0.5);
                    break;
            case 4:
                    glLineWidth(7);
                    glBegin(GL_LINE_LOOP);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(0.5,0.5);
                    glVertex2f(-0.5,-0.5);
                    break;
            case 5:
                    glBegin(GL_TRIANGLES);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(-0.5,-0.5);
                    break;
            case 6:
                    glBegin(GL_TRIANGLE_STRIP);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(-0.5,-0.5);
                    glVertex2f(0,-1);
                    break;
            case 7:
                    glBegin(GL_TRIANGLE_FAN);
                    glColor3f(0,0,1);
                    glVertex2f(0,0);
                    glVertex2f(0.5,0);
                    glVertex2f(0.5,0.5);
                    glColor3f(0,1,0);
                    glVertex2f(0,0.5);
                    glColor3f(1,0,0);
                    glVertex2f(-0.5,0.5);
                    break;
            case 8:
                    glBegin(GL_QUADS);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(-0.5,-0.5);
                    break;
            case 9:
                    glBegin(GL_QUAD_STRIP);
                    glVertex2f(-0.5,-0.5);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(0.5,0.5);
                    glVertex2f(1,-1);
                    glVertex2f(1,1);
                    break;
            case 10:
                    glBegin(GL_POLYGON);
                    glVertex2f(-0.5,0.5);
                    glVertex2f(0,1);
                    glVertex2f(0.5,0.5);
                    glVertex2f(0.5,-0.5);
                    glVertex2f(0,-1);
                    glVertex2f(-0.5,-0.5);
                    break;
            default:
                    //glColor3f(1,0,0);
                    glBegin(GL_QUADS);
                    glVertex2f(-1,1);
                    glVertex2f(1,1);
                    glVertex2f(1,-1);
                    glVertex2f(-1,-1);
                    glColor3f(0,0,1);
                    glBegin(GL_LINES);
                    glVertex2f(0,1);
                    glVertex2f(0,-1);
                    glColor3f(0,1,0);
                    glBegin(GL_LINES);
                    glVertex2f(1,0);
                    glVertex2f(-1,0);
                    break;
        }
        glEnd();
        glFlush();
    }
}

int main(int argc,char **argv){
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowPosition(268,250);
        glutInitWindowSize(500,500);
        glutCreateWindow("Primitives");
        glutDisplayFunc(output);
        glutMainLoop();
        return 0;
}
