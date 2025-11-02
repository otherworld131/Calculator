# Design Assumptions - Calculette MFC Application

* We only consider positive integers for addition. To be reviewed later if needed given the limited scope of the exercise.
* Max integer size is based on standard C++ `int` type.
* Log file is created in the same directory as the executable.
* Log file is going to be small - no log rotation or size management implemented.
* Context menu is triggered by right-clicking anywhere on the main dialog.
