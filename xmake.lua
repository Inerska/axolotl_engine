add_rules("mode.debug", "mode.release")
add_requires("conan::glfw/3.4")

target("hello_world")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("conan::glfw/3.4")
