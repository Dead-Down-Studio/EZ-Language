cmake_minimum_required(VERSION 3.10)
project(EZLanguage)

set(CMAKE_CXX_STANDARD 17)

# Discover ANTLR4 runtime instead of relying on a single hardcoded location.
set(ANTLR4_RUNTIME_ROOT "" CACHE PATH "Optional ANTLR4 runtime install prefix")

find_path(ANTLR4_RUNTIME_INCLUDE_DIR
	NAMES antlr4-runtime.h
	HINTS
		${ANTLR4_RUNTIME_ROOT}
		ENV ANTLR4_RUNTIME_ROOT
		/opt/homebrew
		/usr/local
		/usr
	PATH_SUFFIXES
		include/antlr4-runtime
		include
		antlr4-runtime
)

find_library(ANTLR4_RUNTIME_LIBRARY
	NAMES antlr4-runtime libantlr4-runtime
	HINTS
		${ANTLR4_RUNTIME_ROOT}
		ENV ANTLR4_RUNTIME_ROOT
		/opt/homebrew
		/usr/local
		/usr
	PATH_SUFFIXES
		lib
		lib64
)

if (NOT ANTLR4_RUNTIME_INCLUDE_DIR OR NOT ANTLR4_RUNTIME_LIBRARY)
	message(FATAL_ERROR
		"Could not find ANTLR4 runtime. Set ANTLR4_RUNTIME_ROOT or ANTLR4_RUNTIME_INCLUDE_DIR/ANTLR4_RUNTIME_LIBRARY.")
endif()

# Include all src subdirectories for header files
include_directories(src src/core src/codegen src/config src/diagnostics src/friends src/util)
include_directories(${ANTLR4_RUNTIME_INCLUDE_DIR})

# Explicitly list ANTLR-generated sources to avoid GLOB issues
set(GENERATED_SRC
	generated/EZLanguageBaseListener.cpp
	generated/EZLanguageLexer.cpp
	generated/EZLanguageListener.cpp
	generated/EZLanguageParser.cpp
)

# Collect source files from all subdirectories
file(GLOB CORE_SRC "src/core/*.cpp")
file(GLOB CODEGEN_SRC "src/codegen/*.cpp")
file(GLOB CONFIG_SRC "src/config/*.cpp")
file(GLOB DIAG_SRC "src/diagnostics/*.cpp")
file(GLOB FRIENDS_SRC "src/friends/*.cpp")
file(GLOB UTIL_SRC "src/util/*.cpp")

set(SRC_FILES
	src/main.cpp
	${CORE_SRC}
	${CODEGEN_SRC}
	${CONFIG_SRC}
	${DIAG_SRC}
	${FRIENDS_SRC}
	${UTIL_SRC}
)

add_executable(ez_main ${SRC_FILES} ${GENERATED_SRC})
target_link_libraries(ez_main ${ANTLR4_RUNTIME_LIBRARY})