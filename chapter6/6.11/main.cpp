#include <iostream>
#include <fstream>
using namespace std;

const int svgheight = 500;
const int svgwidth = 500;

/* 
s;"\([^"]\+\)";\\"" << \1 << "\\";g
*/
void fillRect(ofstream &out, int x, int y, int width, int height) {
	out << "<rect ";
	out << "x=\"" << x << "\" ";
	out << "y=\"" << y << "\" ";
	out << "width=\"" << width << "\" ";
	out << "height=\"" << height << "\" ";
	/* out << "style=\"stroke:purple;stroke-width:2\""; */
	/* out << "style=\"stroke:purple;stroke-width:2\""; */
	out << "/>\n";
}

void line(ofstream &out, int x1, int y1, int x2, int y2) {
	out << "<line ";
	out << "x1=\"" << x1 << "\" ";
	out << "y1=\"" << y1 << "\" ";
	out << "x2=\"" << x2 << "\" ";
	out << "y2=\"" << y2 << "\" ";
	out << "style=\"stroke:black;stroke-width:2\"";
	out << "/>\n";
};
	
int main(int argc, char *argv[]){
	if (argc <= 1) {
		cout << "Not enough args\n";
		exit(1);
	}

	ofstream output;
	output.open("chart.svg");
	if (output.fail()) {
		cerr << "can't open output file\n";
		exit(1);
	}
	output << 
		"<?xml version=\"1.0\" standalone=\"no\"?>\n"
		"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \n"
		"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
		"<svg width=\"" << 500 << "\" height=\"" << 500 << "\"\n"
		"xmlns=\"http://www.w3.org/2000/svg\">\n";


	line(output, 2, 0, 2, svgheight);
	line(output, 2, svgheight, svgwidth, svgheight);

	const int numcount = argc-1;
	int nums[numcount];
	
	int max = 0;
	for (int i=0; i < numcount; i++) {
		nums[i] = stoi(argv[i+1]);

		if (nums[i] > max) {
			max = nums[i];
		}
	}

	{
		const int spacing = svgwidth / (numcount * 2 + 1);
		const int maxheight = 400;
		const int width = spacing;
		/* const int width = 30; */

		int x = spacing;
		for (int num : nums) {
			int height = (num * maxheight) / max;
			fillRect(output, x, svgheight - height, width, height);
			x += width + spacing;
		}
	}

	output << "\n</svg>\n";


	output.close();
}

