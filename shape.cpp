#include "shape.hpp"

void Shape::print() {
	cout<<"Type: "<<type<<endl;
	cout<<"BBox: "<<endl;
	cout<<"lo: "<<bbox.lo.p[0]<<" "<<bbox.lo.p[1]<<" "<<bbox.lo.p[2]<<endl;
	cout<<"hi: "<<bbox.hi.p[0]<<" "<<bbox.hi.p[1]<<" "<<bbox.hi.p[2]<<endl;
}