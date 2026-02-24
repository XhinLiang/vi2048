#!/usr/bin/env bash
set -euo pipefail

build_dir="${1:-build}"

cmake -S . -B "${build_dir}"
cmake --build "${build_dir}"

if [[ ! -f "${build_dir}/vi2048" && ! -f "${build_dir}/vi2048.exe" ]]; then
  echo "Expected build output not found in ${build_dir}" >&2
  exit 1
fi

echo "Smoke test passed: build output exists in ${build_dir}"
