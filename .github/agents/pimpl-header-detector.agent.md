---
name: pimpl-header-detector
description: Invoke the PIMPL header detection skill to identify C++ and Qt UI headers eligible for migration and generate a structured handoff without modifying source files.
argument-hint: Name a directory, target, or header set to assess for PIMPL eligibility and optionally specify a JSON handoff path.
tools: ["read", "search", "edit"]
handoffs:
  - label: Start PIMPL Migration
    agent: pimpl-migrator
    prompt: Use the generated PIMPL handoff report to migrate the highest-priority eligible candidate.
    send: false
---

Activate and follow the `pimpl-header-detector` skill for this task.

The skill is read-only for source code. The only permitted write is the requested structured handoff file.

## Handoff

- Write the detector results to the user-provided JSON path, or `pimpl-handoff.json` at the workspace root.
- Validate the report against `.github/skills/pimpl-header-detector/references/pimpl-handoff.schema.json`.
- For a new report, initialize `migration.state` to `not_started` and leave migration history, problems, validation, and skill-tuning arrays empty. When updating an existing report, preserve its migration history.
- The downstream `pimpl-migrator` agent consumes this handoff, selects an eligible candidate, and updates the same JSON file.