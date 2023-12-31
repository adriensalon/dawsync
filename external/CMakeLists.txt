set(SMTG_ENABLE_VST3_HOSTING_EXAMPLES OFF CACHE BOOL "We do not need examples." FORCE)
set(SMTG_ENABLE_VST3_PLUGIN_EXAMPLES OFF CACHE BOOL "We do not need examples." FORCE)
set(SMTG_ENABLE_VSTGUI_SUPPORT ON CACHE BOOL "We currently need VSTGUI." FORCE)

# SMTG_BUILD_UNIVERSAL_BINARY mac only
# SMTG_CREATE_BUNDLE_FOR_WINDOWS
set(SMTG_CREATE_PLUGIN_LINK OFF CACHE BOOL "We do not need to create simlinks." FORCE)
set(SMTG_CREATE_VST2_AGAIN_SAMPLE_VERSION OFF CACHE BOOL "We do not need examples." FORCE)
set(SMTG_CXX_STANDARD "17" CACHE STRING "We use C++17." FORCE)
set(SMTG_ENABLE_ADDRESS_SANITIZER OFF CACHE BOOL "We trust Steinberg I guess." FORCE)

# SMTG_ENABLE_TARGET_VARS_LOG bizarre
set(SMTG_ENABLE_USE_OF_JACK OFF CACHE BOOL "We do not need Jack." FORCE)
set(SMTG_MDA_VST3_VST2_COMPATIBLE OFF CACHE BOOL "We do not need this." FORCE)

# SMTG_IOS_DEVELOPMENT_TEAM: Needed for building the InterAppAudio and AUv3 examples for iOS (Mac only)
# SMTG_MYPLUGINS_SRC_PATH: Here you can add your VST 3 plug-ins folder
# SMTG_PLUGIN_TARGET_PATH: Here you can redefine the VST 3 plug-ins folder
# SMTG_PLUGIN_TARGET_USER_PROGRAM_FILES_COMMON: use FOLDERID_UserProgramFilesCommon as VST 3 target path (Windows only) (default ON)
# SMTG_RENAME_ASSERT: Rename ASSERT to SMTG_ASSERT to avoid conflicts with 3rd party libraries (default ON)
# SMTG_RUN_VST_VALIDATOR: Run the VST validator on VST 3 plug-ins each time they are built (default ON)
# SMTG_USE_STATIC_CRT: Use static CRuntime on Windows (option /MT) (default OFF: /MD is used) (Windows only)
add_subdirectory(vst3sdk)
target_include_directories(sdk PUBLIC vst3sdk)
target_include_directories(sdk PUBLIC vst3sdk/vstgui4)

set(RTMIDI_BUILD_STATIC_LIBS ON CACHE BOOL "We do need this." FORCE)
set(RTMIDI_BUILD_SHARED_LIBS OFF CACHE BOOL "We do not need this." FORCE)
set(RTMIDI_BUILD_TESTING OFF CACHE BOOL "We do not need this." FORCE)
add_subdirectory(rtmidi)

add_subdirectory(audiofile)

set(NO_EXAMPLES ON CACHE BOOL "We do not need examples." FORCE)

# add_subdirectory(libdatachannel)
# target_include_directories(sdk PUBLIC libdatachannel/include)