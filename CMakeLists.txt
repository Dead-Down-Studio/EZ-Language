cmake_minimum_required(VERSION 3.10)
project(EZLanguage)

set(CMAKE_CXX_STANDARD 17)

# Manually specify ANTLR runtime include and library paths
include_directories(/usr/local/include/antlr4-runtime)
link_directories(/usr/local/lib)

# Include all src subdirectories for header files
include_directories(src src/core src/codegen src/config src/diagnostics src/friends src/util)

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
target_link_libraries(ez_main antlr4-runtime)