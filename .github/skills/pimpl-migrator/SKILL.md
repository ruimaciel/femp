---
name: pimpl-migrator
description: Migrate a C++ or Qt UI class from a header-and-source implementation to the PIMPL idiom. Use when applying a detector handoff, reducing public-header dependencies, improving compile-time isolation, or preserving ABI boundaries during a focused PIMPL refactor.
metadata:
  author: Rui Maciel
  version: "1.0"
---

# PIMPL Migration

Migrate one C++ class, usually a Qt UI class, to the PIMPL idiom while preserving its public API and runtime behavior. This skill may edit the selected header and source file, plus narrowly related tests or build metadata when required for correctness.

## Inputs

Accept one of these inputs:

- A detector handoff JSON file, normally `pimpl-handoff.json`.
- A specific header and corresponding source file.
- A class name plus the directory or target containing it.

When a detector handoff is provided, validate and consume it using [the handoff schema](../pimpl-header-detector/references/pimpl-handoff.schema.json). Prefer candidates with `status: "ready"` and `rating: "strong"` or `"possible"`. Do not migrate entries marked `needs review` or `deferred` until their risks are resolved. Preserve the detector findings while updating the report’s `migration` object.

If the handoff already contains migration results, treat it as resumable state. Review open or resolved problems, prior validation failures, and `migration.skill_tuning` observations before choosing the next action. Do not discard prior migration history.

## Guardrails

- Preserve the existing public API unless the user explicitly requests an API change.
- Do not migrate multiple classes in one pass unless the user explicitly requests a batch and each class has an independent validation path.
- Do not edit unrelated files, reformat surrounding code, or replace an established project convention without a concrete reason.
- Do not infer ownership from a raw pointer. Confirm QObject parent ownership, smart-pointer ownership, or external lifetime management first.
- Stop and report a blocker when the header/source pair is missing, the class has unresolved copy/value semantics, or the handoff identifies an unresolved ABI or generated-code risk.

## Migration Workflow

1. Read the selected handoff entry and verify that every referenced header, source file, class, call site, and target exists. If the report is resumable, review its prior state, problems, validation, and skill-tuning observations first.
2. Read the complete header and source, then inspect nearby PIMPL implementations and applicable project instructions.
3. Identify the public contract that must remain visible: inheritance, constructors, destructors, signals, slots, properties, enums, typedefs, public nested types, and exported declarations.
4. Identify implementation-only state and dependencies: private data members, helper types, widget/layout/model members, generated UI objects, private includes, and inline methods.
5. Form a concrete migration hypothesis and a cheap check that could disconfirm it, such as a focused target build or a search for inline/private-member use at call sites.
6. Choose the project’s established d-pointer convention. If none exists, prefer a forward-declared `Private` type owned by `std::unique_ptr<Private>`.
7. Move eligible implementation-only members and helpers into the private implementation. Keep Qt meta-object declarations and public types in the public class when moc or callers require them.
8. Add or preserve the owning pointer in the public class and declare special members correctly. For `std::unique_ptr<Private>`, declare the public destructor in the header and define it in the source file after `Private` is complete. Preserve or explicitly delete copy/move operations according to the original class semantics.
9. Define the private implementation in the source file, initialize it in the constructor, and move affected method bodies there. Keep QObject parent assignment and destruction order correct.
10. Remove only includes that are now implementation-only. Replace them with forward declarations where legal, while retaining complete types required by inheritance, inline code, templates, moc, properties, or public signatures.
11. Search for stale direct accesses, incomplete-type errors, accidental API changes, duplicate ownership, and methods that still require moved members.
12. Build the affected target, run the focused validation from the handoff, and run relevant unit or widget tests. Expand validation only when the class is shared or the migration changes a library boundary.
13. Update the handoff report after each meaningful phase: set `migration.state` to `in_progress`, `completed`, `blocked`, or `failed`; record the selected candidate, timestamp, changed files, changes made, problems, and validation results.
14. Record reusable observations in `migration.skill_tuning.observations` and concrete improvements in `migration.skill_tuning.recommended_changes`. Use these fields for problems that could improve future detection or migration runs, not for speculative commentary.

## Qt-Specific Rules

- Keep `Q_OBJECT`, signals, slots, properties, and public enums in the QObject-derived public class when Qt’s meta-object compiler or external callers need them.
- Do not hide a type required by a property declaration, signal/slot signature, queued connection, or generated UI contract without checking moc and compile behavior.
- Keep the public QObject inheritance unchanged unless explicitly requested.
- Ensure private child widgets and layouts retain the same parent, ownership, and destruction order.
- Treat generated `ui_*.h` members as implementation details only when the generated type is not needed by the public contract.
- Be cautious with `Q_PROPERTY` accessors, default member initializers, inline slots, and connections made in the constructor.

## Decision Points

- If the class is a value type with meaningful copy or move behavior, assess whether PIMPL changes its semantics or performance before editing.
- If the class is exported from a shared library, prioritize ABI stability but verify visibility macros and destructor placement.
- If the class is header-only or already forward-declared effectively, do not force a migration merely to apply the pattern.
- If the detector rating is weak, explain why the migration cost outweighs the benefit and stop unless the user overrides that recommendation.
- If no corresponding source file exists, either create one only when the project convention supports it and the user requested it, or stop and report that the candidate is unsuitable for this workflow.

## Validation Checklist

Before completion, confirm:

- The public declarations and Qt meta-object contract are preserved.
- The private implementation is complete where required by its owner and destructor.
- No private implementation type leaks through public signatures or inline definitions unintentionally.
- Ownership and destruction order match the pre-migration behavior.
- Header-only dependencies decreased or the tradeoff is documented.
- The affected target compiles with moc/uic generation enabled.
- Focused tests pass, or the exact blocker and command are reported.
- The detector handoff entry is reflected accurately in the result.
- The handoff report records the final migration state, all encountered problems with severity and resolution status, and every validation attempt.
- Any observation that could fine-tune this skill is recorded under `migration.skill_tuning`.

## Completion Report

Report:

- Header and source files changed.
- Class and PIMPL convention used.
- Members and includes moved or hidden.
- Public API and Qt behavior preserved.
- Risks, assumptions, and unresolved questions.
- Build and test commands with their outcomes.
- Updated handoff report path and migration state.
- Problems encountered, their severity, and whether they were resolved.
- Skill-tuning observations and recommended changes.