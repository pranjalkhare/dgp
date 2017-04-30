#include "renderable.hpp"
vector<string> renderableList = {"roof", "wall", "window", "door"};

Renderable* Renderable::generateRenderable(string& type, AxisAlignedBox3 bbox) {
	Renderable* retval;
	if(type == "roof") {
		retval = new Roof(bbox);
	} else if(type == "wall") {
		retval = new Wall(bbox);
	} else if(type == "window") {
		retval = new Win(bbox);
	} else if(type == "door") {
		retval = new Door(bbox);
	} else {
		cerr << "Unknown type for rendering" << endl;
		exit(0);
	}

	return retval;
}

void draw_bbox(Graphics::RenderSystem & rs, ColorRGBA const & plane_color, AxisAlignedBox3 bbox){
	rs.pushShader();
    rs.setShader(NULL);

    rs.pushColorFlags();

      rs.setColor(plane_color);
      rs.beginPrimitive(Graphics::RenderSystem::Primitive::QUADS);
        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getHigh()[2]);


      rs.endPrimitive();

    rs.popColorFlags();

  rs.popShader();
}

void draw_bbox_roof(Graphics::RenderSystem & rs, ColorRGBA const & plane_color, AxisAlignedBox3 bbox){
	rs.pushShader();
    rs.setShader(NULL);

    rs.pushColorFlags();

      rs.setColor(plane_color);
      rs.beginPrimitive(Graphics::RenderSystem::Primitive::QUADS);
        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);

        rs.sendVertex(bbox.getLow()[0],bbox.getLow()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getLow()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getHigh()[1],bbox.getLow()[2]);
        rs.sendVertex(bbox.getHigh()[0],bbox.getLow()[1],bbox.getLow()[2]);

        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getHigh()[1],bbox.getHigh()[2]);
        rs.sendVertex((bbox.getLow()[0]+bbox.getHigh()[0])/2.0,bbox.getLow()[1],bbox.getHigh()[2]);


      rs.endPrimitive();

    rs.popColorFlags();

  rs.popShader();
}

Roof::Roof(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Roof::print() {
	cout << "Render:\n";
	cout << "Type: roof\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

void Roof::draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color) {
	
	draw_bbox_roof(rs, ColorRGB(1.0, 0.0, 0.0), bbox);

}


Wall::Wall(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Wall::print() {
	cout << "Render:\n";
	cout << "Type: wall\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

void Wall::draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color) {
	draw_bbox(rs, ColorRGB(1.0, 1.0, 1.0), bbox);
}

Win::Win(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Win::print() {
	cout << "Render:\n";
	cout << "Type: window\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

void Win::draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color) {
	draw_bbox(rs, ColorRGB(0.0, 0.0, 1.0), bbox);
}

Door::Door(AxisAlignedBox3 bbox1) {
	bbox = bbox1;
}

void Door::print() {
	cout << "Render:\n";
	cout << "Type: door\n";
	cout << "lo: (" << bbox.getLow()[0] << ", "<< bbox.getLow()[1] << ", "<< bbox.getLow()[2] << ")\n";
	cout << "hi: (" << bbox.getHigh()[0] << ", "<< bbox.getHigh()[1] << ", "<< bbox.getHigh()[2] << ")\n";
}

void Door::draw(Graphics::RenderSystem & rs, ColorRGBA const & plane_color) {
	draw_bbox(rs, ColorRGB(0.0, 1.0, 0.0), bbox);
}