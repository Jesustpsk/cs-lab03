#include <iostream>
#include <algorithm>
#include "Bar_chart.h"
//#include "test.h"
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

using namespace std;


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	Input input;
	if (argc > 1) {
		input = download(argv[1]);
	}
	else {
		input = read_input(cin, true);
	}
	vector<size_t>bins(input.bin_count);

	make_histogram(bins, input);
	cerr << '\n';
	//show_histogram_text(bins, MAX_ASTERISK);
	show_histogram_svg(bins, MAX_ASTERISK);

}


