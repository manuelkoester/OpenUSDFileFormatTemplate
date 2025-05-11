# This file is derived from:
# https://github.com/cpichard/usdtweak/blob/develop/cmake/houdini/pxrConfig.cmake
# Original work Copyright (c) 2024 cpichard
# Licensed under the Apache License, Version 2.0

# Finds the Houdini USD toolkit and sets up the necessary variables

if(NOT DEFINED Houdini_DIR)
    message(FATAL_ERROR "Houdini_DIR must be set to the directory containing Houdini's USD toolkit")
endif()

# Find Houdini package
find_package(Houdini REQUIRED)

# PXR_INCLUDE_DIRS
get_property(PXR_INCLUDE_DIRS TARGET Houdini PROPERTY INTERFACE_INCLUDE_DIRECTORIES)

# PXR_LIBRARIES
set(PXR_LIBRARIES usdUtils;ar;arch;gf;js;kind;ndr;pcp;plug;sdf;sdr;tf;trace;usd;usdGeom;usdHydra;usdLux;usdRender;usdRi;usdShade;usdSkel;usdVol;vt;work;usdImaging;cameraUtil;hd;hf;pxOsd)
foreach (lib ${PXR_LIBRARIES})
    add_library(${lib} ALIAS Houdini::Dep::pxr_${lib})
endforeach ()

# Additional libraries not configured in HoudiniConfig.cmake
set(EXTRA_PXR_LIBRARIES usdImagingGL;glf;hgiGL;garch;usdAppUtils)
foreach(extra_lib ${EXTRA_PXR_LIBRARIES})
    add_library(${extra_lib} SHARED IMPORTED)
    set_target_properties(${extra_lib} PROPERTIES IMPORTED_IMPLIB ${_houdini_install_root}/custom/houdini/dsolib/libpxr_${extra_lib}.lib)
    list(APPEND PXR_LIBRARIES ${extra_lib})
endforeach()

# Add USD transitive dependencies
list(APPEND PXR_LIBRARIES Houdini::Dep::python${_houdini_python_version};Houdini::Dep::hboost_python;Houdini::Dep::tbb;Houdini::Dep::tbbmalloc)

# Get PXR_VERSION
find_file(pxr_h pxr/pxr.h PATHS ${PXR_INCLUDE_DIRS})
foreach (xxx MAJOR MINOR PATCH)
    file(STRINGS
        ${pxr_h}
        value
        REGEX "#define PXR_${xxx}_VERSION .*$")
    string(REGEX MATCHALL "[0-9]+" PXR_${xxx}_VERSION ${value})
endforeach ()
file(STRINGS
    ${pxr_h}
    value
    REGEX "#define PXR_VERSION .*$")
string(REGEX MATCHALL "[0-9]+" PXR_VERSION ${value})

# Add compilation definitions and options
add_compile_options(${_houdini_compile_options})
add_compile_definitions(${_houdini_defines} -DMAKING_DSO) 