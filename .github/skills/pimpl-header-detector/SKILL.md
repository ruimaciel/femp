---
name: pimpl-header-detector
description: Detect C++ and Qt UI header files that are good candidates for the PIMPL idiom, rank migration readiness, and generate a machine-readable JSON handoff. Use when assessing headers for PIMPL eligibility, compile-time improvement, ABI isolation, or UI implementation-detail exposure.
metadata:
  author: Rui Maciel
  version: "1.0"
---

# PIMPL Header Detection

Analyze C++ and Qt UI headers for PIMPL eligibility. This skill is read-only for source code and may write only the requested JSON handoff file.

## Scope

Analyze `.h`, `.hpp`, and `.hh` files in the requested directory, target, or project. Rank candidates by compile-time, ABI, and encapsulation benefit. Focus on widgets, dialogs, models, views, controllers, and other classes with implementation details exposed in public headers.

Do not edit source files, generate migrations, perform automated rewrites, commit changes, revert user changes, or propose unrelated redesigns.

## Detection Criteria

Rank a header as a stronger candidate when several of these signals are present:

- Private members require Qt widgets, layouts, models, views, OpenGL types, or other heavyweight headers.
- Includes are used only by private members or implementation helpers and can likely be replaced with forward declarations.
- A public class has a corresponding `.cpp` where most behavior is implemented.
- A Qt UI class uses `Q_OBJECT` while its state can move private and its signals, slots, properties, and public types can remain visible.
- The header is widely included or sits at a library boundary.
- Implementation changes are likely to trigger broad rebuilds.

Treat these as caution signals, not automatic exclusions:

- `Q_OBJECT`, `Q_GADGET`, properties, enums, signals, slots, and moc visibility.
- Inline methods that access private state.
- Public Qt inheritance, templates, value semantics, inline destructors, or exported classes.
- Copy/move operations, friend declarations, generated `ui_*.h`, and QObject parent ownership.
- A class layout or inline behavior intentionally exposed as part of a value-type API.

Rank a class weak when it is a small value type, already uses forward declarations effectively, has no meaningful implementation state, or is intentionally header-only.

Do not infer eligibility from include count alone. Identify which dependencies are implementation-only and compare the expected benefit with migration cost.

## Analysis Workflow

1. Resolve the requested scope and enumerate relevant headers.
2. Pair each header with its corresponding `.cpp`, if present.
3. Inspect declarations, includes, private members, inline methods, Qt macros, exports, and generated UI dependencies.
4. Search for include fan-out and existing `Private`, `Impl`, `unique_ptr`, `QScopedPointer`, or d-pointer conventions.
5. Inspect call sites or tests only when needed to resolve ownership, value semantics, or API constraints.
6. Assign each analyzed header a `strong`, `possible`, or `weak` rating.
7. Record evidence, risks, likely private members to move, open questions, and one focused validation command.
8. Verify every recommended source path exists.

## Handoff Output

Write JSON after analysis. Use the user-provided path, or `pimpl-handoff.json` at the workspace root when no path is supplied. If an existing handoff contains unrelated user-authored data, preserve it where possible rather than silently replacing it.

The output must be valid JSON, contain no prose outside the JSON document, use arrays for repeated values, and use `null` for unknown scalar values. Use `needs review` for uncertain conclusions. Validate the output against [the handoff schema](references/pimpl-handoff.schema.json).

For a new report, initialize the `migration` object with `state: "not_started"`, a `null` candidate, empty changes, problems, and validation arrays, and empty skill-tuning observations. When updating an existing report after a migration, preserve the existing `migration` object and its history so the next candidate can be assessed without losing prior results.

Include one candidate or deferred/excluded entry for every analyzed header. In the final chat response, summarize the prioritized shortlist and report the handoff path, but keep the persisted handoff itself machine-readable.