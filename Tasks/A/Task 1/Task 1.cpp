#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double d, h, w, k;
	cin >> d >> h >> w >> k;	

	double bis = sqrt(d * d + w * w);
	if (w == 0) {
		if (k >= d * 2)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	else if (h >= 2 * w) {
		if (k >= bis * 2)
			cout << atan(w / d) * 180 / M_PI << endl;
		else
			cout << -1 << endl;
	}
	else {
		if(acos(2*d/k)>=atan(w/d))
			cout << acos(2 * d / k) * 180 / M_PI << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}