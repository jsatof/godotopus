#include "example.h"

#include <godot_cpp/core/class_db.hpp>

namespace godot {

void GDExample::_bind_methods() {

}

GDExample::GDExample() {
}

GDExample::~GDExample() {
}

void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_pos = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));
	set_position(new_pos);
}


}

