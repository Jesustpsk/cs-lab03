#pragma once
#define CURL_STATICLIB
#include <curl.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <set>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

//cURL

struct Input {
	vector <double> numbers;
	size_t bin_count;
};
size_t write_data(void* contents, size_t size, size_t nmemb, stringstream* buffer);
Input download(const string&);

void generate_12x(vector <double>&);
void fill_vec(istream&, vector <double>&);

Input read_input(istream& in, bool prompt);

double max_el(vector <double>);
double min_el(vector <double>);
void make_histogram(vector <size_t>&, const Input&);
void show_histogram_text(vector<size_t>, const size_t);

//SVG

void svg_begin(double, double);
void svg_end();
void svg_text(double, double, string);
void svg_rect(double, double, double, double, string, string, string);
void show_histogram_svg(vector<size_t>&, const size_t);



