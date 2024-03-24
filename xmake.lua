set_project("lipoy")
set_version("0.1.0-dev.0")

add_rules("mode.debug", "mode.release")
set_languages("c++20", "c17")

add_requires("raylib", "raygui")
add_requires("toml++")

target("lipoy")
    set_kind("binary")

    add_packages("raylib", "raygui")
    add_packages("toml++")
    
    add_files("src/*.cpp", "src/*.mpp")
    add_files("src/device/*.cpp", "src/device/*.mpp")
    add_files("src/renderer/*.cpp", "src/renderer/*.mpp")