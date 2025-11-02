# Calculator

A simple calculator application written in C++ with MFC (Microsoft Foundation Classes).

## Features

- Add two positive integers
- Clear input and result fields
- Display result when Calculate is invoked (menu, context menu, or Enter)
- Tools menu with Calculate option
- Context menu with Calculate option
- Automatic logging of all calculations to a `calculations.log` file

## Requirements

- **Visual Studio 2022**
- **MFC++ component** from the Visual Studio installer
  - During installation, select "Desktop development with C++" workload
  - In the installation details, ensure "MSVC v143 build tools" and "Windows 10/11 SDK" include MFC support

## Building

1. Open `Calculator.sln` in Visual Studio 2022
2. Build the solution (Ctrl+Shift+B)
3. Run the application (F5)

## Implementation Notes

- Dialog-based MFC application using VS2022 template
- Basic error handling and input validation
- Calculations are logged to `calculations.log` in the application directory
