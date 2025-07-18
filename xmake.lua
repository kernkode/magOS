target("main")
    set_kind("binary")
    add_files("src/main.cpp")
    set_basename("magOS")
    set_targetdir("$(curdir)/bin")
    add_includedirs("src")
    set_pcxxheader("src/pch.h")
    add_files("src/*.cpp")
    set_languages("c++17")
    add_defines("DEBUG_MODE")