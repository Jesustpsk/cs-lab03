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

void svg_begin(double width, double height){
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end(){
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='"<< baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black", string fill_opacity = "1") {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width 
        << "' height='" << height << "' stroke='" << stroke << "' fill ='" << fill 
        << "' fill-opacity ='" << fill_opacity << "'/>";
}

void show_histogram_svg(vector<size_t>& bins, const size_t MAX_ASTERISK) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    size_t max_count = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        if (bins[i] > max_count) {
            max_count = bins[i];
        }
    }

    double top = 0;
    for (size_t bin : bins) {
        if (bin < 100 && bin > 9) {
            svg_text(TEXT_LEFT + 5, top + TEXT_BASELINE, to_string(bin));
        }else if (bin < 10) {
            svg_text(TEXT_LEFT + 10, top + TEXT_BASELINE, to_string(bin));
        }
        else {
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        }

        double bin_width;
        if (max_count > (IMAGE_WIDTH / 10)) {
            bin_width = IMAGE_WIDTH * (static_cast<double>(bin) / max_count);
        }
        else {
            bin_width = BLOCK_WIDTH * bin;
        }


        double fill_opacity = static_cast<double>(bin) / static_cast<double>(max_count);
        string opacity = "";
        opacity += to_string(fill_opacity)[0];
        opacity += ".";
        opacity += to_string(fill_opacity)[2];
        svg_rect(TEXT_WIDTH, top, bin_width - 50, BIN_HEIGHT, "black", "black", opacity);
        top += BIN_HEIGHT;
    }
    svg_end();
}