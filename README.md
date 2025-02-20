## Based on work by [Ryan-rsm-McKenzie](https://github.com/Ryan-rsm-McKenzie)
* [FlatMapMarkersSSE](https://github.com/Ryan-rsm-McKenzie/FlatMapMarkersSSE)
* [ExamplePlugin-CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/ExamplePlugin-CommonLibSSE)

## Requirements
* [CMake](https://cmake.org/)
	* Add this to your `PATH`
* [The Elder Scrolls V: Skyrim Special Edition](https://store.steampowered.com/app/489830)
	* Add the environment variable `Skyrim64Path` to point to the root installation of your game directory (the one containing `SkyrimSE.exe`).
* [Vcpkg](https://github.com/microsoft/vcpkg)
	* Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
* [Visual Studio Community 2022](https://visualstudio.microsoft.com/)
	* Desktop development with C++

## Build Dependencies (handled by vcpkg and git submodule)
* [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)
* [Json2Settings](https://github.com/Ryan-rsm-McKenzie/Json2Settings)
* [JSON for Modern C++](https://github.com/nlohmann/json)

## Building
```
git clone https://github.com/Ryan-rsm-McKenzie/ExamplePlugin-CommonLibSSE
cd ExamplePlugin-CommonLibSSE
git submodule init
git submodule update
cmake --preset vs2022-windows
cmake --build build --config Release
```

## Tips
* Set `COPY_OUTPUT` to `ON` to automatically copy the built dll to the game directory, i.e. `cmake --preset vs2022-windows -DCOPY_OUTPUT=ON`
* Build the `package` target to automatically build and zip up your dll in a ready-to-distribute format.
