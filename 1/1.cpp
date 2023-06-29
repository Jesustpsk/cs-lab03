#include <iostream>
#include <algorithm>
#include "Bar_chart.h"

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	size_t num_count;
	cerr << "Введите количесво чисел: ";
	cin >> num_count;

	vector <double>numbers(num_count);
	cerr << "\nСгенерировать числа? (y/n) ";
	char answ;
	cin >> answ;
	if (answ == 'y') {
		generate_12x(numbers);
	}
	else if (answ == 'n') {
		fill_vec(numbers);
	}
	else {
		system("cls");
		cout << "Error!\n";
		system("pause");
		system("cls");
		return main();
	}
	size_t bin_count;
	cerr << "\nВведите количество корзин: ";
	cin >> bin_count;
	vector<size_t>bins(bin_count);

	make_histogram(bins, numbers, bin_count);
	cerr << '\n';
	//show_histogram_text(bins, MAX_ASTERISK);
	show_histogram_svg(bins, MAX_ASTERISK);
}