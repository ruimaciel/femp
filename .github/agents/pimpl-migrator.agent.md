---
name: pimpl-migrator
description: Invoke the PIMPL migration skill to migrate a C++ or Qt UI class selected from a detector handoff, preserve its public contract, validate the change, and update the migration report.
argument-hint: Provide a detector handoff JSON path, or identify the candidate header and source to migrate.
tools: ["read", "search", "edit", "execute"]
handoffs:
  - label: Re-scan Remaining Candidates
    agent: pimpl-header-detector
    prompt: Re-scan the remaining headers using the updated PIMPL handoff report, preserving completed migration history and identifying the next eligible candidate.
    send: false
---

Activate and follow the `pimpl-migrator` skill for this task.

## Inputs

- Prefer the detector handoff at the user-provided path or `pimpl-handoff.json` at the workspace root.
- If no handoff exists, accept an explicit header, source file, and class name only when the user clearly authorizes migration without detector results.
- Select a candidate with `status: "ready"` and `rating: "strong"` or `"possible"`, unless the user explicitly overrides that decision.

## Handoff

- Read and validate the input report against `.github/skills/pimpl-header-detector/references/pimpl-handoff.schema.json` before editing source files.
- Preserve the detector’s findings and update the same JSON handoff rather than creating a second migration report.
- Set `migration.state` to `in_progress` before source edits.
- Record the selected candidate, changed files, migration changes, problems, validation attempts, and skill-tuning observations.
- Finish with `migration.state` set to `completed`, `blocked`, or `failed`, as appropriate.
- Use the user-provided report path, or `pimpl-handoff.json` at the workspace root.
- When handing back to the detector, preserve the existing `migration` object and its history in the JSON report.

## Editing and Validation

- Invoke the `pimpl-migrator` skill for the complete Qt-aware migration workflow.
- Edit only the selected header/source pair and narrowly related files required for correctness.
- Preserve public API, Qt meta-object behavior, ownership, and project conventions.
- Build the affected target and run the focused tests or validation commands from the handoff.
- Do not commit changes or discard unrelated user edits.