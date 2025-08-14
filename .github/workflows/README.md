# GitHub Actions Workflows

This directory contains the CI/CD workflows for the Prime Number Calculator project.

## Workflows

### build.yml

The main workflow that builds and tests the project on multiple platforms.

**Triggers:**
- Push to `main` or `develop` branches
- Pull requests to `main` or `develop` branches
- Manual workflow dispatch

**Platforms:**
- Ubuntu (GCC & Clang)
- macOS (Clang)
- Windows (MSVC)

**Features:**
- Automated dependency installation
- CMake-based builds
- Test execution
- Artifact upload
- Build summary generation

## Badges

Add these badges to your README.md to show build status:

```markdown
[![Build and Test](https://github.com/{username}/{repo}/actions/workflows/build.yml/badge.svg)](https://github.com/{username}/{repo}/actions/workflows/build.yml)
```

Replace `{username}` and `{repo}` with your actual GitHub username and repository name.

## Artifacts

Each successful build produces:
- **Main Program**: `prime-calculator-{platform}-{compiler}`
- **Test Suite**: `prime-calculator-test-{platform}-{compiler}`
- **Build Summary**: `build-summary`

Artifacts are retained for 30 days and can be downloaded from the Actions tab.
