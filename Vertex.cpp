#include "Vertex.h"
Vertex::Vertex(double a00, double a01, double a02, double a03, double a10, double a11, double a12, double a13,
double a20, double a21, double a22, double a23, double a30, double a31, double a32, double a33)
{
	B[0][0] = a00; B[0][1] = a01; B[0][2] = a02; B[0][3] = a03;
	B[1][0] = a10; B[1][1] = a11; B[1][2] = a12; B[1][3] = a13;
	B[2][0] = a20; B[2][1] = a21; B[2][2] = a22; B[2][3] = a23;
	B[3][0] = a30; B[3][1] = a31; B[3][2] = a32; B[3][3] = a33;
}