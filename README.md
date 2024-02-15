# SUMO TraCI Library Configuration with C++ using CMake

## Short Introduction:

SUMO, which stands for "Simulation of Urban MObility," is an open-source, highly portable traffic simulation package tailored for handling large networks. Primarily developed by employees of the Institute of Transportation Systems at the German Aerospace Center. The primary method of interacting with a running simulation is through TraCI, offering comprehensive flexibility for cross-platform, cross-language, and networked interaction, with SUMO serving as the server. To enable integration with client code, bindings need to be supplied for each client language.

## Motivation:

As there isn't much material or comprehensive instruction available on configuring the SUMO TraCI library with the C++ language using CMake, this repository aims to provide detailed, step-by-step guidance to assist you in completing the configuration.

## Precondition:

- Using CMAKE to configure your C++ project
- Using CMAKE GUI to build your project
- Using libTraci API
- Windows Environment
- cloned SUMO from SUMO GitHub repository 
- CMAKE 3.28
- c++ 17 Standard


## Getting Started:

1. Clone SUMO from GitHub repository [here](https://github.com/eclipse-sumo/sumo).
2. Clone SUMO Library from GitHub repository [here](https://github.com/DLR-TS/SUMOLibraries).
3. Add System variables:
   - `SUMO_HOME`: location of SUMO
   - `SUMO_LIBRARIES`: location of SUMO Libraries
   - `Path`: Add `<location of sumo/bin>`
5. Build SUMO:
   - Open CMAKE GUI
   - Where is the source code: location of your SUMO
   - Where to build the binaries: location of your SUMO/build/CMAKE
   - If SUMO is built successfully, you should see build/CMAKE directory under SUMO directory.
6. Configure the CmakeList under your project root directory (You can also refer to the `CmakeList.txt` in this repository):
   - Set SUMO_DIR to allow CMAKE to find SUMO (path: CMAKE build location in SUMO)
   ```<Cmake>
   set(SUMO_DIR "${CMAKE_SOURCE_DIR}/sumo/build/CMAKE")
   ```

   - Optional: Check if CMAKE finds SUMO
   ```<Cmake>
   find_package(SUMO REQUIRED)
   if(SUMO_FOUND)
       message(STATUS "SUMO found.")
   else()
       message(FATAL_ERROR "SUMO not found.")
   endif()
   ```
  - Don't forget to link SUMO library
    ```<Cmake>
    target_link_libraries(cmakeSumoLibtraci PUBLIC SUMO::libtracicpp SUMO::libsumocpp)
    ```
7. Once you finish the step 6, open CMAKE GUI, click configure and generate. 
8. You will find example c++ code to initiate the simulation in this repository (main.cpp). Also, the example SUMO scenario can also be found in this repository. If it runs successfully, you should see SumoGUI pops up.

## Helpful Links:
[SUMO GitHub Repository](https://github.com/eclipse-sumo/sumo),
[SUMO Documentation](https://sumo.dlr.de/docs/index.html)
