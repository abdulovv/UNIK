#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	const double PI = 3.141592653589793;
	int x1, x2, x3, y1, y2, y3;
	double side1, side2, side3, s, p, h1, h2, h3, m1, m2, m3, angle1, angle2, angle3, angleDEG1, angleDEG2, angleDEG3, b1, b2, b3, inscribedRadius, ro,squareOfInscribedCircle,sro,lengthOfInscribedCircle,lro;

	cout << "Введите х1:";
	cin >> x1;
	cout << "" << endl;

	cout << "Введите х2:";
	cin >> x2;
	cout << "" << endl;

	cout << "Введите х3:";
	cin >> x3;
	cout << "" << endl;

	cout << "Введите y1:";
	cin >> y1;
	cout << "" << endl;

	cout << "Введите y2:";
	cin >> y2;
	cout << "" << endl;

	cout << "Введите y3:";
	cin >> y3;
	cout << "" << endl;


	side1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	side2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));

	side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

	p = (side1 + side2 + side3) / 2;

	s = sqrt(p * (p - side1) * (p - side2) * (p - side3));//1

	h1 = 2 * s / side1;
	h2 = 2 * s / side2;
	h3 = 2 * s / side3;

	m1 = sqrt(2 * (pow(side1, 2) + pow(side2, 2))- pow(side3, 2)) / 2;
	m2 = sqrt(2 * (pow(side3, 2) + pow(side1, 2)) - pow(side2, 2)) / 2;
	m3 = sqrt(2 * (pow(side3, 2) + pow(side2, 2)) - pow(side1, 2)) / 2;

	angle1 = acos((pow(side3, 2) + pow(side2, 2) - pow(side1, 2)) / (2* side3 * side2));
	angle2 = acos((pow(side3, 2) + pow(side1, 2) - pow(side2, 2)) / (2 * side3 * side1));
	angle3 = acos((pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) / (2 * side1 * side2));

	b1 = sqrt((side2 * side3) * (side1 + side2 + side3) * (side2 + side3 - side1)) / (side2 + side3);
	b2 = sqrt((side1 * side3) * (side1 + side2 + side3) * (side1 + side3 - side2)) / (side1 + side3);
	b3 = sqrt((side1 * side2) * (side1 + side2 + side3) * (side1 + side2 - side3)) / (side1 + side2);

	inscribedRadius = s / p;
	ro = side1 * side2 * side3 / (4 * s);

	squareOfInscribedCircle = PI * pow(inscribedRadius,2);
	sro = PI * pow(ro, 2);

	lengthOfInscribedCircle = PI * inscribedRadius * 2;
	lro = PI * ro * 2;

	angleDEG1 = angle1 * 180 / PI;
	angleDEG2 = angle2 * 180 / PI;
	angleDEG3 = angle3 * 180 / PI;

	s = p* inscribedRadius;//2
	s = side1 * side2 * sin(angle3) / 2; //3

	cout << "сторона1:" << side1 << endl;
	cout << "сторона2:" << side2 << endl;
	cout << "сторона3" << side3 << endl;
	cout << "площадь:" << s <<endl;
	cout << "периметр:" << p*2 << endl;
	cout << "медиана1:" << m1 << endl;
	cout << "медиана2:" << m2 << endl;
	cout << "медиана3:" << m3 << endl;
	cout << "высота1:" << h1 << endl;
	cout << "высота2:" << h2 << endl;
	cout << "высота3:" << h3 << endl;
	cout << "биссектриса1:" << b1 << endl;
    cout << "биссектриса2:" << b2 << endl;
	cout << "биссектриса3:" << b3 << endl;
	cout << "угол 1(rad):" << angle1 << endl;
	cout << "угол 2(rad):" << angle2 << endl;
	cout << "угол 3(rad):" << angle3 << endl;
	cout << "угол 1(deg):" << angleDEG1 << endl;
	cout << "угол 2(deg):" << angleDEG2 << endl;
	cout << "угол 3(deg):" << angleDEG3 << endl;
	cout << "радиус вписанной окружности:" << inscribedRadius << endl;
	cout << "радиус описанной окружности:" << ro << endl;
	cout << "длина вписанной окружности:" << lengthOfInscribedCircle << endl;
	cout << "длина описанной окружности:" << lro << endl;
	cout << "площадь описанной окружности:" << sro << endl;
	cout << "площадь вписанной окружности:" << squareOfInscribedCircle << endl;


	

	















}