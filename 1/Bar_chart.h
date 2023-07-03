#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <set>
#include <string>
#include <cmath>

using namespace std;

void generate_12x(vector <double>&);
void fill_vec(istream&, vector <double>&);
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

//cURL

struct Input {
	vector <double> numbers;
	size_t bin_count;
};

Input read_input(istream& in, bool prompt);