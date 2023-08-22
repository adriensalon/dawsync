
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

project(DAWSync

	# This is your plug-in version number. Change it here only.
	# Version number symbols usable in C++ can be found in
	# source/plugin/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
	VERSION 1.0.0.0
	DESCRIPTION "DAWSync plug-in")

set(SMTG_VSTGUI_ROOT "${SDK_ROOT}")

smtg_enable_vst3_sdk()

set(dawsync_glue_sources
	source/glue/mix.cpp
	source/glue/network.cpp
	source/glue/transport.cpp)

set(dawsync_widgets_sources)

set(dawsync_sources
	source/plugin/version.h
	source/plugin/cids.h
	source/plugin/processor.h
	source/plugin/processor.cpp
	source/plugin/controller.h
	source/plugin/controller.cpp
	source/plugin/entry.cpp)

smtg_add_vst3plugin(DAWSync PACKAGE_NAME "DAWSync" SOURCES_LIST
	${dawsync_glue_sources}
	${dawsync_widgets_sources}
	${dawsync_sources})

if(SMTG_ADD_VSTGUI)
	target_sources(DAWSync PRIVATE resource/plugin_editor.uidesc)
	target_link_libraries(DAWSync PRIVATE vstgui_support)
	smtg_target_add_plugin_resources(DAWSync RESOURCES "resource/plugin_editor.uidesc")
endif(SMTG_ADD_VSTGUI)

smtg_target_add_plugin_snapshots(DAWSync RESOURCES
	resource/47132ABEAC0B5605BBE04172D9D94E3F_snapshot.png
	resource/47132ABEAC0B5605BBE04172D9D94E3F_snapshot_2.0x.png)

target_include_directories(DAWSync PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source)

target_link_libraries(DAWSync PRIVATE sdk)
target_link_libraries(DAWSync PRIVATE vstgui)
target_link_libraries(DAWSync PRIVATE vstgui_support)
target_link_libraries(DAWSync PRIVATE vstgui_uidescription)

target_link_libraries(DAWSync PRIVATE rtmidi)

# target_link_libraries(DAWSync PRIVATE datachannel-static)
smtg_target_configure_version_file(DAWSync)

if(SMTG_MAC)
	smtg_target_set_bundle(DAWSync
		BUNDLE_IDENTIFIER com.adriensalon.DAWSync
		COMPANY_NAME "adrien salon")

# smtg_target_set_debug_executable(DAWSync
# "/Applications/VST3PluginTestHost.app"
# "--pluginfolder;$(BUILT_PRODUCTS_DIR)")
elseif(SMTG_WIN)
	target_sources(DAWSync PRIVATE resource/win32resource.rc)

	if(MSVC)
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DAWSync)

		# smtg_target_set_debug_executable(DAWSync
		# "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
		# "--pluginfolder \"$(OutDir)/\"")
	endif()
endif(SMTG_MAC)
