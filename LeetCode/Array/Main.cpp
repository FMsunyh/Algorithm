#include <vector>
#include "Array.h"
using namespace std;

int main()
{
	vector<int> vec;

	vec.push_back(0);
	/*vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);*/
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(6);
	/*vec.push_back(7);
	vec.push_back(8);*/

	Array* arr = new Array();
	arr->RemoveElement(vec, 5);

}