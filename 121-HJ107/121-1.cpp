#include <iostream>
#include <cstdio>

using namespace std;

// 牛顿迭代公式 f(x) = x^3 - 216
// x_{n+1} = x_n -
double getCubeRoot(double input) {
	double root_old = 6.0;
	double root_new = 1.0;

	while (root_new - root_old >= 0.1 || root_new - root_old <= -0.1){
		root_old = root_new;
		root_new = root_old*2/3 + input/(3.0*root_old*root_old);
	}

	return root_new;
}

int main(int argc, char **argv) {
	double input = 0.0;
	while(cin >> input){
		printf("%0.1f\n", getCubeRoot(input));
	}
	return 0;
}

