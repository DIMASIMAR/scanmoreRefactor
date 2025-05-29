# ceflaTemplate
# C++ Onion Architecture Refactor Project

## 📌 Project Overview

This repository is a **refactor of an existing C++ codebase**. The goal is to restructure the project according to the **Onion Architecture**, enforce **strict coding rules**, and maintain **code quality** using automated tools.

All rules and expectations are documented in [`copilot-instructions.md`](./copilot-instructions.md).

---

## 🧱 Project Architecture

The project is structured using **Onion Architecture**:

```
/src
  /Domain           --> Business entities, interfaces (no dependencies)
  /Application      --> Use cases and application services
  /Infrastructure   --> Database, file system, device interaction
  /Interface        --> UI, CLI, REST APIs (optional)
```

Each layer depends only on the layers beneath it. Domain must remain dependency-free.

---

## 🧪 Development Environment

- **IDE**: Visual Studio 2022
- **C++ Standard**: C++20
- **Warnings**: `/W4` + Treat warnings as errors
- **Unit Tests**: Google Test (GTest)
- **Package Manager**: Conan
- **Code Formatter**: ClangFormat
- **Static Analysis**: Clang-Tidy
- **Build**: CMake or MSBuild (.vcxproj + shared .props)
- **Git Config**: `.gitattributes` for consistent line endings and merges

---

## 🧰 Required Tools

| Tool            | Install Guide                                                                 |
|-----------------|--------------------------------------------------------------------------------|
| Conan           | https://conan.io/downloads.html                                                |
| ClangFormat     | Bundled with Visual Studio or `brew install clang-format` / `choco install`   |
| Clang-Tidy      | Visual Studio + C++ workload or standalone via LLVM                           |
| GoogleTest      | Installed via Conan or manually                                                |
| Git             | Include `.gitattributes` in repo                                               |

---

## 🧩 Automation

### ✅ Code Formatting

Run ClangFormat automatically:

```sh
clang-format -i **/*.cpp **/*.h
```

Configure auto-format in Visual Studio:
```
Tools → Options → Text Editor → C/C++ → Formatting → General → [✓] Format on Save
```

See `.clang-format` for rules (based on LLVM with custom braces and indentation).

---

### ✅ Linting (Optional but Recommended)

Use `clang-tidy` to detect style and logic issues:

```sh
clang-tidy src/**/*.cpp -- -I./include
```

See `.clang-tidy` for enabled checks (readability, performance, modernize, etc.).

---

### ✅ Pre-commit Hook (optional)

You can add a Git hook to automatically format .cpp and .h files before each commit.
Create .git/hooks/pre-commit.ps1:

clang-format -i $(git diff --cached --name-only --diff-filter=ACM | grep -E '\.(cpp|h)$')
git add $(git diff --cached --name-only --diff-filter=ACM | grep -E '\.(cpp|h)$')
```

# Pre-commit hook for formatting C++ code with clang-format

$stagedFiles = git diff --cached --name-only --diff-filter=ACM | Where-Object { $_ -match '\.(cpp|h)$' }

if ($stagedFiles) {
    Write-Host "Running clang-format on staged C++ files..."
    foreach ($file in $stagedFiles) {
        clang-format -i $file
        git add $file
    }
}


Then, in .git/hooks/pre-commit:


#!/bin/sh
pwsh .git/hooks/pre-commit.ps1





---

## ✍️ Coding Rules Summary

| Aspect            | Rule                            |
|-------------------|----------------------------------|
| Language          | C++, all comments in English     |
| Docs              | Doxygen for public APIs          |
| Testing           | Google Test                      |
| Format            | ClangFormat                      |
| Naming (file)     | PascalCase                       |
| Naming (variable) | camelCase                        |
| Member vars       | m_ prefix                        |
| Namespaces        | snake_case                       |
| Const/Enum        | PascalCase                       |
| Functions         | camelCase                        |
| Headers           | Include guards (`#ifndef...`)    |
| Includes Order    | STL → Third-party → Local        |

See [`copilot-instructions.md`](./copilot-instructions.md) for full detail.

---

## 🚫 Not Allowed

- ❌ Use of Qt
- ❌ Raw pointers (use `std::unique_ptr`, `std::shared_ptr`)
- ❌ Exception-based flow control (exceptions only for exceptional states)

---

## 🧠 Tips for Copilot Usage

Copilot is guided by context. To improve suggestions:

- Keep naming conventions consistent
- Write instructive comments like:

  ```cpp
  // Follows SRP and RAII. Use camelCase. Document with Doxygen.
  ```

- Maintain a clean structure in line with Onion Architecture

---

## 🧭 References

- [Onion Architecture](https://jeffreypalermo.com/blog/the-onion-architecture-part-1/)
- [Rule of Five / Zero](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Doxygen](https://www.doxygen.nl/manual/docblocks.html)

---

## 🔧 Template Project Setup

The repository includes reusable `.props` and `.vcxproj` templates. Use these to create consistent modules/layers.

---

