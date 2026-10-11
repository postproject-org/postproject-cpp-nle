# PostProject C++ NLE validation

This focused integration models the smallest NLE clip boundary: an editor keeps its
own fallback path while persisting a PostProject representation reference, then
uses the installed C++17 wrapper to resolve the clip. It links only the staged
CMake package and never invokes Cargo.

This checkout requires the installed PostProject 0.9 development package.
The C++ wrapper uses checked resolution configurations; ordinary resolution
uses defaults without allocating a separate options object.
