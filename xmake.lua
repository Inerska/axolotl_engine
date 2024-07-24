set_project("GameEngine")
set_version("0.1.0")

add_rules("mode.debug", "mode.release")
set_languages("c++20")

add_requires("glfw 3.4", {alias = "glfw"})
add_requires("glad 0.1.36", {alias = "glad"})
add_requires("glm 0.9.9", {alias = "glm"})
add_requires("conan::spdlog/1.14.1", {alias = "spdlog"})
add_requires("catch2 3.5.2", {alias = "catch2"})

target("game_engine")
    set_kind("static")
    add_files("src/**.cpp")
    add_headerfiles("include/(game_engine/**.hpp)")
    add_includedirs("include", {public = true})
    add_packages("glfw", "glad", "glm", "spdlog")

target("game_engine_exe")
    set_kind("binary")
    add_deps("game_engine")
    add_files("src/main.cpp")
    add_packages("glfw", "glad", "glm", "spdlog")

target("tests")
    set_kind("binary")
    add_deps("game_engine")
    add_files("tests/**.cpp")
    add_headerfiles("tests/**.hpp")
    add_packages("catch2", "glfw", "glad", "glm", "spdlog")

if is_mode("debug") then
    add_cxflags("-Wall", "-Wextra", "-Werror", "-Wpedantic")
end