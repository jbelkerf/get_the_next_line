# Get Next Line

Get Next Line (GNL) is a function that reads a file descriptor line by line. This project is part of the 42 curriculum and explores efficient file reading techniques using both an array-based approach and a linked list-based approach.

## Features

- Reads a file descriptor line by line
- Handles any valid file descriptor (files, stdin, pipes, etc.)
- Supports both static array-based and dynamic linked list implementations
- Works with multiple file descriptors simultaneously (bonus part)
- Efficient memory management

## Implementations

### Array-Based Version (`gnl_arrays/`)
This implementation stores buffered data in an array and processes it incrementally.
- **Pros**: Simple, fast for small buffers
- **Cons**: Less efficient for large files due to reallocations

Files:
- `get_next_line.c` – Core function for reading a line
- `get_next_line.h` – Header file with function prototypes
- `get_next_line_bonus.c` – Multi-file descriptor support (bonus)
- `get_next_line_bonus.h` – Header file for the bonus version
- `get_next_line_utils.c` – Utility functions (buffer handling, memory management)
- `get_next_line_utils_bonus.c` – Utility functions for the bonus version

### Linked List-Based Version (`gnl_linked_list/`)
This implementation stores buffered data in a linked list structure, avoiding unnecessary memory reallocations.
- **Pros**: More efficient memory usage, better for large files
- **Cons**: Slightly more complex data management

Files:
- `get_next_line.c` – Core function for reading a line
- `get_next_line.h` – Header file with function prototypes
- `get_next_line_bonus.c` – Multi-file descriptor support (bonus)
- `get_next_line_bonus.h` – Header file for the bonus version
- `get_next_line_utils.c` – Utility functions (linked list operations, memory management)
- `get_next_line_utils_bonus.c` – Utility functions for the bonus version
- `main.c` – Test program

## Installation

To compile and use Get Next Line, navigate to the respective folder and run:

```sh
make
```

This will generate an object file for integration into other projects.

## Usage

Include the appropriate header and compile your program with `get_next_line.c`:

```c
#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compile:

```sh
gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl
```

## Contributing

If you want to contribute, fork the repository, make changes, and submit a pull request.

## License

This project is open-source under the MIT License.

## Author

Developed by Jaouad Belkerf (jbelkerf) as part of the 42 curriculum.

