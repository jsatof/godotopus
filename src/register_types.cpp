#include "register_types.h"
#include "example.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

namespace godot {

void init_opus_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<GDExample>();
}

void deinit_opus_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {

GDExtensionBool GDE_EXPORT opus_module_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
												const GDExtensionClassLibraryPtr p_lib,
												GDExtensionInitialization *r_init)
{
	godot::GDExtensionBinding::InitObject initObject(p_get_proc_address, p_lib, r_init);
	initObject.register_initializer(init_opus_module);
	initObject.register_terminator(deinit_opus_module);
	initObject.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
	return initObject.init();
}

}

}
