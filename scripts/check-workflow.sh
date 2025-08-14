#!/bin/bash

# Check GitHub Actions workflow status
# Requires: gh CLI tool and authentication

set -e

REPO="mrakitin/prime-number-calc"
WORKFLOW="build.yml"

echo "🔍 Checking GitHub Actions workflow status for $REPO"
echo ""

# Check if gh CLI is installed
if ! command -v gh &> /dev/null; then
    echo "❌ GitHub CLI (gh) is not installed."
    echo "Please install it from: https://cli.github.com/"
    exit 1
fi

# Check if authenticated
if ! gh auth status &> /dev/null; then
    echo "❌ Not authenticated with GitHub CLI."
    echo "Please run: gh auth login"
    exit 1
fi

echo "📊 Recent workflow runs:"
echo ""

# Get recent workflow runs
gh run list --repo "$REPO" --workflow "$WORKFLOW" --limit 5

echo ""
echo "📋 To view detailed logs, run:"
echo "  gh run view --repo $REPO <run-id>"
echo ""
echo "📦 To download artifacts, run:"
echo "  gh run download --repo $REPO <run-id>"
echo ""
echo "🚀 To trigger a new workflow run:"
echo "  gh workflow run --repo $REPO $WORKFLOW"
