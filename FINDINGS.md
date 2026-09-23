# Findings

- The installed CMake target keeps Cargo entirely outside the NLE build.
- A host needs both a durable PostProject reference and its own display/fallback
  path; `HostObjectBinding` makes that split explicit and round-trippable.
- The copied C++ snapshots fit an editor's project/task boundary without native
  result-handle lifetime management.
- Resolution is intentionally an application decision point: the NLE must show
  ambiguity rather than accepting the first candidate.

