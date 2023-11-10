
<!--
<a href="https://gitlab.com/joba14/view">
	<img src="./logo.svg" alt="Logo" width="400">
</a>
-->

[![License](https://img.shields.io/badge/license-View_GPLv1-brightgreen.svg?style=for-the-badge)](./license.md)
![Language Support](https://img.shields.io/badge/languages-C-brightgreen.svg?style=for-the-badge)
![Platform Support](https://img.shields.io/badge/platforms-Linux_|_Windows-brightgreen.svg?style=for-the-badge)

# View
**The View library for C**<br>[Report a bug](https://github.com/joba14/view/issues/new) · [Request a feature](https://github.com/joba14/view/issues/new)


## Table of Contents
 - [Overview](#overview)
 - [Features](#features)
 - [Getting Started](#getting-started)
 - [License](#license)


## Overview
The **view** library is a header-only C library designed to create and bind views on sequence-like structures, such as strings. It provides a flexible and intuitive way to handle various views, and has extensions API for working with the **string views** specifically.

[(to the top)](#view)


## Features
The "view" library in C distinguishes itself by offering a generic view structure, empowering users to seamlessly work with sequential C structures like strings and arrays. Notably, this library places a deliberate emphasis on user autonomy by abstaining from implementing strict memory safety measures, leaving users in control of memory management. This intentional design choice enables a lightweight and adaptable experience, allowing users to apply their own memory safety practices based on specific requirements. With a focus on flexibility and user responsibility, the "view" library provides a versatile tool for efficiently interacting with sequential C data structures while allowing users the freedom to implement their preferred memory safety practices.

[(to the top)](#view)


## Getting Started
Using **view** library is straightforward. Here's a basic example of a string view:
```c

#define enable_utf8_string_view_implementation
#include "../include/utf8_string_view.h"

#include <stdio.h>

signed int main(
	void)
{
	const utf8_string_view_s sv1 = utf8_string_view_from_cstring("hello");
	const utf8_string_view_s sv2 = utf8_string_view_from_parts("hello", 5);

	const bool equal = utf8_string_view_equal(sv1, sv2);
	printf("sv1 == sv2 => %s\n", equal ? "true" : "false");

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_from_cstring("+++++hello+++++")
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim_left(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim_right(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	printf(utf8_fmt "\n", utf8_arg(
		utf8_string_view_trim(
			utf8_string_view_from_cstring("+++++hello+++++"), '+'
		)
	));

	return 0;
}
```

[(to the top)](#view)


## License
The View project is released under the **View GPLv1** license. Users and contributors are required to review and comply with the license terms specified in the [license.md file](./license.md). The license outlines the permitted usage, distribution, and intellectual property rights associated with the View project.

Please refer to the [license.md file](./license.md) for more details. By using, modifying, or distributing the View project, you agree to be bound by the terms and conditions of the license.

[(to the top)](#view)