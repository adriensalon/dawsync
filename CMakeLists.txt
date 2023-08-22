cmake_minimum_required(VERSION 3.19)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

project(vstsync

	# This is your plug-in version number. Change it here only.
	# Version number symbols usable in C++ can be found in
	# source/plugin/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
	VERSION 1.0.0.0
	DESCRIPTION "vstsync VST 3 Plug-in"
)

add_subdirectory(external)

set(SMTG_VSTGUI_ROOT "${SDK_ROOT}")

smtg_enable_vst3_sdk()

smtg_add_vst3plugin(vstsync
	source/network/test.cpp
	source/plugin/version.h
	source/plugin/cids.h
	source/plugin/processor.h
	source/plugin/processor.cpp
	source/plugin/controller.h
	source/plugin/controller.cpp
	source/plugin/entry.cpp
)

if(SMTG_ADD_VSTGUI)
	target_sources(vstsync PRIVATE resource/plugin_editor.uidesc)
	target_link_libraries(vstsync PRIVATE vstgui_support)
	smtg_target_add_plugin_resources(vstsync RESOURCES "resource/plugin_editor.uidesc")
endif(SMTG_ADD_VSTGUI)

smtg_target_add_plugin_snapshots(vstsync RESOURCES
	resource/47132ABEAC0B5605BBE04172D9D94E3F_snapshot.png
	resource/47132ABEAC0B5605BBE04172D9D94E3F_snapshot_2.0x.png)

target_include_directories(vstsync PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source)

target_link_libraries(vstsync PRIVATE sdk)
target_link_libraries(vstsync PRIVATE rtmidi)

# target_link_libraries(vstsync PRIVATE datachannel-static)
smtg_target_configure_version_file(vstsync)

if(SMTG_MAC)
	smtg_target_set_bundle(vstsync
		BUNDLE_IDENTIFIER com.adriensalon.vstsync
		COMPANY_NAME "My Plug-in Company")

	smtg_target_set_debug_executable(vstsync
		"/Applications/VST3PluginTestHost.app"
		"--pluginfolder;$(BUILT_PRODUCTS_DIR)")

elseif(SMTG_WIN)
	target_sources(vstsync PRIVATE resource/win32resource.rc)

	if(MSVC)
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT vstsync)

		# smtg_target_set_debug_executable(vstsync
		# "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
		# "--pluginfolder \"$(OutDir)/\"")
	endif()
endif(SMTG_MAC)
