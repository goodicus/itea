# Compilation guidance
To build with CMake first clone and install vcpkg.
Go to the folder where you want to have your vcpkg built and call the following command:

### Vcpkg compilation step
[Vcpkg Readme file](https://github.com/microsoft/vcpkg#readme)

```sh
git clone https://github.com/Microsoft/vcpkg.git && cd vcpkg
```

For Windows:
```sh
.\bootstrap-vcpkg.bat && .\vcpkg install GTest --triplet x64-windows
```

For Linux:
```sh
./bootstrap-vcpkg.sh && ./vcpkg install GTest --triplet x64-linux.cmake
```

### Project compilation step
Then call the building step:
(Note: if you don't need test projects in your solution - set -DENABLE_UNIT_TESTS=OFF, or simply remove it)
```sh
cmake -B *path/to/build/dir* -S *path/to/source/dir* -DBUILD_TESTS=ON -DCMAKE_TOOLCHAIN_FILE=*path/to/vcpkg.cmake*
```
Example (Windows):
```sh
cmake -B ./.build -S . -DCMAKE_TOOLCHAIN_FILE=d:/development/vcpkg/scripts/buildsystems/vcpkg.cmake
```
