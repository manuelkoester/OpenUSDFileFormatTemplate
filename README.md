# OpenUSDFileFormatTemplate

A template project for creating custom USD file format plugins, designed to work with both standalone USD and Houdini's USD.

> **Note**: This template has currently only been tested on Windows.

## Overview

This project provides a template for developing custom USD file format plugins. It's set up to work with both standalone USD and Houdini's USD toolkit. The template includes all necessary build configuration and boilerplate code to get started with USD plugin development.

Every place that needs replacement can be found via a simple `OpenUsdFileFormatTemplate` search.

## Prerequisites

- Either:
  - USD installation, or
  - Houdini installation with USD toolkit

## Building the Project

```bash
cmake -G "Visual Studio 17 2022" -T host=x64 -A x64
cmake --build build --config Release
```

### CMake Variables

| Variable name | Example | Purpose |
|-|-|-|
| Houdini_DIR | `-DHoudini_DIR=C:/Program Files/Side Effects Software/Houdini 20.5.445/toolkit/cmake` | Switch to using Houdini's USD |
| Python3_EXECUTABLE | `-DPython3_EXECUTABLE=C:/Users/manum/Documents/_Content/01_Projects/fbxtesting/usdtweak/build/usd/python/python.exe` | Path to the Python executable |
| Python3_LIBRARY | `-DPython3_LIBRARY=C:/Users/manum/Documents/_Content/01_Projects/fbxtesting/usdtweak/build/usd/python/libs/python311.lib` | Path to the Python library |
| Python3_INCLUDE_DIR | `-DPython3_INCLUDE_DIR=C:/Users/manum/Documents/_Content/01_Projects/fbxtesting/usdtweak/build/usd/python/include` | Path to the Python include directory |
| Python3_VERSION | `-DPython3_VERSION=3.11` | Version of Python |

## Project Structure

```
.
├── cmake/                             # CMake modules and configuration
├── src/                               # Source files
│   ├── OpenUsdFileFormatTemplate.cpp  # Main source file
│   ├── OpenUsdFileFormatTemplate.h    # Header file
│   ├── debugCodes.h                   # Debug code definitions
│   └── plugInfo.json                  # Plugin information
├── CMakeLists.txt                     # Main CMake configuration
├── CMakePresets.json                  # CMake presets for different build configurations
└── LICENSE                            # MIT License
```

## Usage

After building, the plugin will be available in the build directory. To use it:

1. Add the resources folder containing the `plugInfo.json` to your `PXR_PLUGINPATH_NAME` environment variable.
2. Add the build folder containing the `OpenUsdFileFormatTemplate.dll` to your `PATH` environment variable.

### Adding New File Format Support

1. Modify all places that contain the string `OpenUsdFileFormatTemplate` (with various casings) to your own file format name
2. Rebuild the project

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

The project includes code derived from [usdtweak](https://github.com/cpichard/usdtweak) which is licensed under the Apache License 2.0. See the [NOTICE](NOTICE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Acknowledgments

- Original USD file format template code from [usdtweak](https://github.com/cpichard/usdtweak)
