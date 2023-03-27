cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

set(vst3sdk_SOURCE_DIR "C:/VST_SDK/vst3sdk")
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(arvin_distort_pedal
    # This is your plug-in version number. Change it here only.
    # Version number symbols usable in C++ can be found in
    # source/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
    VERSION 1.0.0.0 
    DESCRIPTION "arvin_distort_pedal VST 3 Plug-in"
)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(arvin_distort_pedal
    source/version.h
    source/myplugincids.h
    source/mypluginprocessor.h
    source/mypluginprocessor.cpp
    source/myplugincontroller.h
    source/myplugincontroller.cpp
    source/mypluginentry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(arvin_distort_pedal
        PRIVATE
            resource/myplugineditor.uidesc
    )
    target_link_libraries(arvin_distort_pedal
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(arvin_distort_pedal
        RESOURCES
            "resource/myplugineditor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (arvin_distort_pedal
    RESOURCES
        resource/06C86355F79C589788BDC7A98A7296E9_snapshot.png
        resource/06C86355F79C589788BDC7A98A7296E9_snapshot_2.0x.png
)

target_link_libraries(arvin_distort_pedal
    PRIVATE
        sdk
)

smtg_target_configure_version_file(arvin_distort_pedal)

if(SMTG_MAC)
    smtg_target_set_bundle(arvin_distort_pedal
        BUNDLE_IDENTIFIER com.arvinplugin.arvin-distort_pedal
        COMPANY_NAME "Arvin Plugin"
    )
    smtg_target_set_debug_executable(arvin_distort_pedal
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(arvin_distort_pedal PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT arvin_distort_pedal)

        smtg_target_set_debug_executable(arvin_distort_pedal
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
