#include "Bar_chart.h"

void generate_12x(vector <double> & numbers)
{
    srand(time(0));
    int out;
    for (auto i = 0; i < numbers.size(); i++) {
        out = 0;
        for (auto j = 0; j < 12; j++) {
            out += rand() % numbers.size() + 1;
        }
        numbers[i] = out;
    }
}

void fill_vec(vector <double>& numbers) {
    cerr << "\nЗаполните вектор:\n";
    for (auto i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
    }
}

double max_el(vector <double> numbers) {
    double max = numbers[0];
    if (numbers.size() > 1) {
        for (auto i = 1; i < numbers.size(); i++) {
            if (numbers[i] > max)
                max = numbers[i];
        }
    }
    return max;
}

double min_el(vector <double> numbers) {
    double min = numbers[0];
    if (numbers.size() > 1) {
        for (auto i = 1; i < numbers.size(); i++) {
            if (numbers[i] < min)
                min = numbers[i];
        }
    }
    return min;
}
void make_histogram(vector <size_t>& bins, vector<double> numbers, size_t bin_count) {
    double bin_size = (max_el(numbers) - min_el(numbers)) / bin_count;

    for (size_t i = 0; i < numbers.size(); i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min_el(numbers) + j * bin_size;
            auto hi = min_el(numbers) + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
}

void show_histogram_text(vector<size_t> bins, const size_t MAX_ASTERISK) {
    size_t max_count = 0;
    for (size_t bin : bins) {
        if (bin > max_count) {
            max_count = bin;
        }
    }

    for (size_t i = 0; i < bins.size(); i++) {
        if (bins[i] < 100) {
            cout << ' ';
        }

        if (bins[i] < 10) {
            cout << ' ';
        }

        cout << bins[i] << "|";

        size_t height;
        if (max_count > MAX_ASTERISK) {
            if (bins[i] > MAX_ASTERISK) {
                height = MAX_ASTERISK * 1.0;
            }
            else {
                height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
            }
        }
        else {
            height = bins[i];
        }

        for (size_t j = 0; j < height; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}