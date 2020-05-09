cmake_minimum_required(VERSION 2.8.4)
project(libtelegram)

set(CMAKE_BUILD_TYPE Release)

find_package(Boost 1.66 COMPONENTS system)

if (NOT OpenSSL_FOUND)
    message(FATAL_ERROR "Cannot find OpenSSL")
endif()

file(GLOB_RECURSE libtelegram_src
	"src/*.cpp"
)

add_library(${PROJECT_NAME} ${libtelegram_src})

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        NDEBUG
        TELEGRAM_NO_SIGNAL_HANDLER
        TELEGRAM_NO_LISTENER_FCGI
)
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        include
        "${OPENSSL_INCLUDE_DIR}"
        "${Boost_INCLUDE_DIRS}"
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        "${OPENSSL_LIBRARIES}"
        "${Boost_LIBRARIES}"
)

