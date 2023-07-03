#include <iostream>
#include <algorithm>
#include "Bar_chart.h"
//#include "test.h"
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

using namespace std;


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	if (argc > 1) {
		CURL* curl = curl_easy_init();
		if (curl) {
			CURLcode res;
			curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
	}

	return 0;
	const auto input = read_input(cin, true);
	vector<size_t>bins(input.bin_count);

	make_histogram(bins, input);
	cerr << '\n';
	//show_histogram_text(bins, MAX_ASTERISK);
	show_histogram_svg(bins, MAX_ASTERISK);

}


