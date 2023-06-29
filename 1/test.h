#pragma once
#include <cassert>
#include "Bar_chart.h"


void test_minmax() {
	double min = min_el({ 1, 2, 3 });
	double max = max_el({ 1, 2, 3 });
	assert(min == 1);
	assert(max == 3);
}
void test_allnegative(vector<double>numbers) {
	bool all_negative = true;
	for (auto i = 0; i < numbers.size(); i++) {
		if (numbers[i] >= 0) {
			all_negative = false;
			break;
		}
	}
	assert(all_negative == true);
}
void test_allsame(vector<double>numbers) {
	bool all_same = true;
	double temp = numbers[0];
	for (auto i = 0; i < numbers.size(); i++) {
		if (numbers[i] != temp) {
			all_same = false;
			break;
		}
	}
	assert(all_same == true);
}
void test_onenum(vector<double>numbers) {
	if(numbers.size() > 0)
		assert(numbers.size() == 1);
}
void test_emptyarr(vector<double>numbers) {
	bool empty = true;
	if (numbers.size() > 0) {
		bool empty = false;
	}
	else
		assert(empty == true);
}