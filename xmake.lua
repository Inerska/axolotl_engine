set_project("GameEngine")
set_version("0.1.0")

add_rules("mode.debug", "mode.release")
set_languages("c++20")

add_requires("glfw 3.4", {alias = "glfw"})
add_requires("glad 0.1.36", {alias = "glad"})
add_requires("glm 0.9.9", {alias = "glm"})
add_requires("conan::spdlog/1.14.1", {alias = "spdlog"})
add_requires("conan::catch2/3.6.0", {alias = "catch2"})

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
    add_includedirs("tests", "include")
    add_packages("catch2", "glfw", "glad", "glm", "spdlog")

on_load(function (target)
    local main_content = [[
            #define CATCH_CONFIG_MAIN
            #include <catch2/catch_all.hpp>
        ]]
    target:add("files", target:autogenfile("tests/main.cpp", main_content))
end)

if is_mode("debug") then
    add_cxflags("-Wall", "-Wextra", "-Werror", "-Wpedantic")
end