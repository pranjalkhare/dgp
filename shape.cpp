#include "shape.hpp"

void Shape::print() {
	cout<<"Type: "<<type<<endl;
	cout<<"BBox: "<<endl;
	cout<<"lo: "<<bbox.getLow()[0]<<" "<<bbox.getLow()[1]<<" "<<bbox.getLow()[2]<<endl;
	cout<<"hi: "<<bbox.getHigh()[0]<<" "<<bbox.getHigh()[1]<<" "<<bbox.getHigh()[2]<<endl;
}