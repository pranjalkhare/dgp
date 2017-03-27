#include "shape.hpp"

void Shape::print() {
	cout<<"Type: "<<type<<endl;
	cout<<"BBox: "<<endl;
	Vector3 loWcs = transform*bbox.getLow();
	Vector3 hiWcs = transform*bbox.getHigh();
	cout<<"lo: "<<loWcs[0]<<" "<<loWcs[1]<<" "<<loWcs[2]<<endl;
	cout<<"hi: "<<hiWcs[0]<<" "<<hiWcs[1]<<" "<<hiWcs[2]<<endl;
}