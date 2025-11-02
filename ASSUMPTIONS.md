# Design Assumptions - Calculator MFC Application

* Decide on "Calculator" as the application name - in English to be consistent.
* We only consider positive integers for addition. To be reviewed later if needed given the limited scope of the exercise.
* Max integer size is based on standard C++ `int` type.
* Log file is created in the same directory as the executable.
* Pressing Enter triggers the calculation via the dialog's default button handling.
* In a production application, logging would be redirected to a user-writable folder (e.g., `%LOCALAPPDATA%`) instead of the executable directory to avoid permission issues.
* Log file is going to be small - no log rotation or size management implemented.
* Context menu is triggered by right-clicking anywhere on the main dialog.
