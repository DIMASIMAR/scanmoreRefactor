# GitHub Copilot Instructions

## Project Context

This project is a **refactor of an existing repository** and must follow the **Onion Architecture** principles.

### Onion Architecture Guidelines

- Separate code into concentric layers:
  - **Domain Layer**: business entities, value objects, interfaces (pure C++ logic, no dependencies)
  - **Application Layer**: use cases, application services (depends only on domain layer)
  - **Infrastructure Layer**: frameworks, databases, file systems, device IO, third-party libraries
  - **Interface Layer** (optional): UI, APIs, CLI

- **Dependencies point inward**: outer layers may depend on inner ones, never the opposite.
- Use **dependency inversion**: depend on abstractions (interfaces), not concrete implementations.
- Keep the **Domain Layer free of external dependencies**.
- All data access, device interaction, and network logic should be abstracted and injected from outer layers.

> Example folder structure:
```
/src
  /Domain
  /Application
  /Infrastructure
  /workflows
  /Interface
```

# GitHub Copilot Instructions

## Coding Rules

- All **code** and **comments** must be written in **English**.
- Use **Doxygen** to document all public classes, functions, and methods.

  Example:
  ```cpp
  /**
   * Calculates the sum of all elements in the container.
   *
   * @tparam Container The container type
   * @param container The container with elements to sum
   * @return The sum of all elements
   * @throws std::overflow_error If sum exceeds numeric limits
   */
  template <typename Container>
  auto sum(const Container& container);
  ```

- Unit tests must be written using **Google Test (GTest)**.
- Use **Conan** as the package manager, integrated with **Visual Studio 2022** (see Scanmore's `nw-testautomation` for templates).
- Format code using **ClangFormat**, integrated in **Visual Studio 2022**.

## Development Environment

- **Visual Studio 2022**
- **C++20**
- Enable **Warning Level W4** and ensure **zero warnings** during compilation.
- Use **.gitattributes** for consistent Git behavior (see Scanmore projects as reference).
- Use shared **.props** files to create reusable **project templates** (`.vcxproj` and `.props` structure).
- **Do not** use **Qt**.

## Coding Style

### Header Files
- Use include guards:
  ```cpp
  #ifndef __MODULE_NAME_H__
  #define __MODULE_NAME_H__

  // Code...

  #endif // __MODULE_NAME_H__
  ```

### Include Order
1. C++ standard library
2. Third-party libraries
3. Project-specific headers

### Naming Conventions
| Element           | Convention     | Example              |
|-------------------|----------------|----------------------|
| Namespace         | `snake_case`   | `network_utils`      |
| File name         | `PascalCase`   | `NetworkManager.cpp` |
| Variable          | `camelCase`    | `connectionPool`     |
| Constant/Enum     | `PascalCase`   | `MaxRetries`         |
| Function          | `camelCase`    | `connectToServer()`  |
| Member variable   | `m_` prefix + `camelCase` | `m_bufferSize`   |

### Formatting

```cpp
void Function() {
    if (condition) {
        // Do something
    } else {
        // Do something else
    }
}
```

## Design Principles

- Apply **Single Responsibility Principle**.
- Use **RAII** for resource management.
- Follow the **Rule of Five** (or **Rule of Zero**) as appropriate:  
  [cppreference.com - Rule of five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three)

## Error Handling

- Use **exceptions** only for **exceptional conditions**, not for regular control flow.
- Document all exceptions that may be thrown by a function or method.
- Use `assert` **only** for conditions that should **never happen**.

## Memory Management

- Prefer **smart pointers** over raw pointers:
  - `std::unique_ptr` → for exclusive ownership
  - `std::shared_ptr` → for shared ownership
  - `std::weak_ptr` → to break reference cycles

## Performance Considerations

- Use **move semantics** when transferring ownership.
- Pass arguments by **const reference** or **reference** to avoid unnecessary copies.
