# CMakeList.txt : CMake project for game01P, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.9)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("game01P")

# Add source to this project's executable.
add_executable (game01P "src/game01P.cpp" "src/game01P.h")

find_package(SDL3 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

target_link_libraries( ${PROJECT_NAME} 
	PRIVATE 
		SDL3::SDL3 
		EnTT::EnTT
		glm::glm
		$<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>,SDL3_image::SDL3_image-shared,SDL3_image::SDL3_image-static>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET game01P PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.

