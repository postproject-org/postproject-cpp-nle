# Disposable PostProject C++ NLE spike

This experiment models the smallest NLE clip integration: an editor keeps its
own fallback path while persisting a PostProject representation reference, then
uses the installed C++17 wrapper to resolve the clip. It links only the staged
CMake package and never invokes Cargo.

