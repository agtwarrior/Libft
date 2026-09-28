*This project has been created as part of the 42 curriculum by davguerr.*

# Libft

## Description

**Libft** is the first project of the 42 Common Core. The goal is to write a C library that recreates a set of functions from the standard C library (libc), adds some extra utility functions and implements a basic linked list. This is the base library that later 42 projects build on.

The project's goals are:

- To understand how the standard functions work internally instead of using them as black boxes.
- To practise manual memory management (`malloc` / `free`), pointer arithmetic and byte-level memory manipulation.
- To learn to handle edge cases, allocation failures and memory leaks.
- To build a static library (`libft.a`) with a `Makefile` that can be reused in future projects.

All the code follows the **42 Norm** and is compiled with `-Wall -Wextra -Werror`.

## Instructions

### Compilation

```bash
make        # compiles every source file and creates libft.a
make clean  # removes the object files (.o)
make fclean # removes the object files and libft.a
make re     # runs fclean and then all
```

The Makefile compiles each `.c` into a `.o` with `cc -Wall -Wextra -Werror` and packs them into the static library with `ar rcs`. It does not relink: running `make` a second time does nothing if no source file has changed.

### Usage in another project

1. Include the header in your code:

   ```c
   #include "libft.h"
   ```

2. Compile your program linking against the library:

   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o program
   ```

   `-L.` tells the linker to look for libraries in the current directory, and `-lft` links `libft.a`.

### Example

```c
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello  42 madrid", ' ');
	i = 0;
	while (words && words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

## Library description

The library has three parts. Every function has the `ft_` prefix.

### Part 1 — libc functions

These reimplement standard libc functions and keep the same prototypes and behaviour as the originals.

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic. |
| `ft_isdigit` | Checks if a character is a digit (`0`-`9`). |
| `ft_isalnum` | Checks if a character is alphanumeric. |
| `ft_isascii` | Checks if a value is in the ASCII range (0-127). |
| `ft_isprint` | Checks if a character is printable (32-126). |
| `ft_strlen` | Returns the length of a string. |
| `ft_memset` | Fills `n` bytes of memory with a byte value. |
| `ft_bzero` | Sets `n` bytes of memory to zero. |
| `ft_memcpy` | Copies `n` bytes from `src` to `dest` (the areas must not overlap). |
| `ft_memmove` | Copies `n` bytes and handles overlapping areas correctly. |
| `ft_strlcpy` | Size-bounded string copy that always null-terminates. Returns `strlen(src)`. |
| `ft_strlcat` | Size-bounded string concatenation. Returns the length of the string it tried to create. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares up to `n` characters of two strings. |
| `ft_memchr` | Searches for a byte in the first `n` bytes of a memory area. |
| `ft_memcmp` | Compares the first `n` bytes of two memory areas. |
| `ft_strnstr` | Finds a substring within the first `n` characters of a string. |
| `ft_atoi` | Converts a string to an `int`. |
| `ft_calloc` | Allocates zero-initialised memory, with a check for multiplication overflow. |
| `ft_strdup` | Returns a newly allocated copy of a string. |

### Part 2 — Additional functions

These functions are not in libc (or are in it with a different form). Most of them return new memory allocated with `malloc`, which the caller must `free`.

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring of `s` starting at `start` with at most `len` characters. |
| `ft_strjoin` | Returns a new string made of `s1` followed by `s2`. |
| `ft_strtrim` | Returns a copy of `s1` with the characters in `set` removed from both ends. |
| `ft_split` | Splits a string by a delimiter character into a `NULL`-terminated array of strings. |
| `ft_itoa` | Converts an `int` to a newly allocated string (handles `INT_MIN`). |
| `ft_strmapi` | Applies a function to each character (with its index) and returns a new string. |
| `ft_striteri` | Applies a function to each character (with its index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3 — Linked lists

The list functions use this structure, which is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node with the given content. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Returns the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees a node's content with `del` and then frees the node. |
| `ft_lstclear` | Deletes and frees every node of the list and sets the head pointer to `NULL`. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. If an allocation fails, it frees everything it created. |

### Technical choices

- **`unsigned char` in memory functions**: `void *` cannot be dereferenced. The memory is read byte by byte as `unsigned char` so that every byte is a value from 0 to 255. This matters in `ft_memcmp` and `ft_memchr`, where bytes above 127 would otherwise be treated as negative.
- **`ft_memmove`**: when `dest` is after `src` it copies from the end to the beginning, so overlapping source bytes are not overwritten before they are read.
- **`long` in `ft_itoa` and `ft_putnbr_fd`**: the value is stored in a `long` so that `-INT_MIN` does not overflow.
- **Cleaning up on failure**: if an allocation fails partway, `ft_split` and `ft_lstmap` free everything they had already allocated, so nothing leaks.
- **`static` helper functions**: the internal helpers (for example `count_words` and `num_len`) are `static`. They are only visible in their own file, which avoids name conflicts inside the library.

## Resources

- `man` pages of the original functions (`man 3 strlcpy`, `man 3 memmove`, `man 3 atoi`...).
- [cppreference — C standard library](https://en.cppreference.com/w/c)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [`ar` — GNU Binutils documentation](https://sourceware.org/binutils/docs/binutils/ar.html)
- *The C Programming Language*, Brian W. Kernighan & Dennis M. Ritchie.
- [42 Norm (norminette)](https://github.com/42School/norminette)

### Use of AI

AI (Claude) was used as a **study and review tool**, not to write the library code:

- To review and explain concepts after the functions were written (why `unsigned char` is used in the memory functions, how `memmove` handles overlap, what `strlcpy`/`strlcat` return).
- To point out the most complex functions and their edge cases, and to prepare for the evaluation.
- To help write this README.

The source code of every function was written by the author.
