# FdF - 3D Wireframe Viewer

<img width="350" alt="Screen Shot 2023-07-27 at 6 55 39 PM" src="https://github.com/Neilus03/FdF-42/assets/87651732/4d698bda-f5a3-494d-a9bd-94541c60739c">


## Description
FdF (Fils de Fer) is a project from 42 curriculum. The goal of this project is to create a simplified 3D graphic representation of a relief landscape.

## Features

- Rotating, zooming, and shifting the map in real-time with keyboard and mouse.
- Changing color gradient.

## Usage

```sh
make
```
```sh
.\fdf [map_file]
```
## Controls

    -Zoom in/out: Scroll up/down.
    -Move: Arrow keys.
    -Change color: W key.

## Project structure

This project is divided into several parts:

    libft: Contains utility functions used throughout the project.
    ft_printf: Contains a function to print formatted output to the stdout.
    minilibx_macos: Contains functions to handle graphics.
    srcs: Contains the main logic of the project.
    includes: Contains the header files.

## Files

The main files of the project are located inside the srcs and includes folders. Here is a brief description of them:
srcs

    color.c: Functions to generate colors based on height.
    drawing.c: Functions to draw lines and handle drawing for rows and columns.
    fdf.c: Main function to initialize variables and run mlx.
    general_functions.c: General functions including closing window, key press, and mouse press.
    read_fdf.c: Functions to read the FdF file and create a 2D array with the data.

## includes

    colors.h: Defines color codes.
    fdf.h: Contains all the structure definitions and function prototypes used in the project.
    keycodes.h: Defines key codes.

## Example Maps

You can find example maps in the test_maps folder.

## Author

Neil de la Fuente
