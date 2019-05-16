#include<iostream>

void main()
{

	/** Rotation plane */
	double a = -0.320462, b = -0.177388, c = 0.930504; // vector

	/** rotation & translation */
	double planeNormal[] = { a, b, c };
	double xyNormal[] = { 0.0, 0.0, 1.0 };

	double crossPruduct[3];
	double dotPruduct, normCrossPruduct;


	crossPruduct[0] = planeNormal[1] * xyNormal[2] - planeNormal[2] * xyNormal[1];
	crossPruduct[1] = -(planeNormal[0] * xyNormal[2] - planeNormal[2] * xyNormal[0]);
	crossPruduct[2] = planeNormal[0] * xyNormal[1] - planeNormal[1] * xyNormal[0];

	dotPruduct = planeNormal[0] * xyNormal[0] + planeNormal[1] * xyNormal[1] + planeNormal[2] * xyNormal[2];
	normCrossPruduct = sqrt(crossPruduct[0] * crossPruduct[0] + crossPruduct[1] * crossPruduct[1] + crossPruduct[2] * crossPruduct[2]);

	double radian = atan2(normCrossPruduct, dotPruduct);
	double oriTheta = radian * 180 / 3.14;

	//double checkTheta = acos(c / sqrt(planeNormal[0] * planeNormal[0] + planeNormal[1] * planeNormal[1] + planeNormal[2] * planeNormal[2]));
	double cosTheta;
	std::cout << "checkTheta: " << radian * 180 / 3.14159 << std::endl;

	//double cosTheta = c / sqrt(planeNormal[0] * planeNormal[0] + planeNormal[1] * planeNormal[1] + planeNormal[2] * planeNormal[2]);

	for (int i = 0; i <= 36; i += 3)
	{
		cosTheta = radian + 0.087266 * i; // 0.087266 = 5 degrees

		double newCos = cos(cosTheta);

		double son = (a*a + b*b)*newCos*newCos;
		double mother = (1 - newCos*newCos);

		double NewC = sqrt(son / mother);

		planeNormal[2] = NewC;

		double NewTheta = acos(planeNormal[2] / sqrt(planeNormal[0] * planeNormal[0] + planeNormal[1] * planeNormal[1] + planeNormal[2] * planeNormal[2]));

		if (cosTheta > 3.14 / 2 && cosTheta < 3.14 || cosTheta >(3 * 3.14 / 2) && cosTheta < 0) //180<theta<90  degrees or 270<theta<0 degrees
		{
			NewC = -NewC;
		}

		std::cout << "Deg: " << i * 5 << " c:" << NewC << " New Theta:" << NewTheta * 180 / 3.14 << std::endl;
	}
}