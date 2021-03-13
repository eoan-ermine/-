/*
Напишите функцию, которая принимает на вход вектор времени ответа и
вычисляет медиану этого вектора. Вектор может быть неотсортированным.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
	if(!samples.size()) {
		return pair(false, 0);
	}
	sort(samples.begin(), samples.end());

	int center = samples.size() / 2;
	return pair(true, samples.size() % 2 ? samples[center] :
					  (samples[center] + samples[center - 1]) / 2);
}
