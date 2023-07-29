# 🌍 FdF - Explore 3D Wireframe Landscapes!

<div align="center">
    <img width="350" alt="Screen Shot 2023-07-27 at 6 55 39 PM" src="https://github.com/Neilus03/FdF-42/assets/87651732/4d698bda-f5a3-494d-a9bd-94541c60739c">
</div>

Welcome to **FdF**! This project is a part of the rigorous 42 curriculum, and it allows you to visualize 3D landscapes from a 2D representation, bringing the map to life right on your screen.

## 🚀 Features

- 🌐 **Real-time Interaction:** Rotate, zoom in and out, and shift the map using just your keyboard and mouse.
- 🎨 **Dynamic Colors:** Change color gradients on the fly.

## 🛠️ Usage

Ready to explore? Here's how you start your journey:

1. Build the project with `make`.

    ```sh
    make
    ```

2. Run FdF with a map file of your choice.

    ```sh
    ./fdf [map_file]
    ```

## 🎮 Controls

- 🧐 **Zoom in/out:** Scroll up or down.
- 🏃 **Move:** Use your arrow keys.
- 🌈 **Change color:** Hit the 'W' key.

## 📚 Project Structure

FdF is structured to be modular and maintainable. Here's what's inside:

- **libft:** This is where all the utility functions reside. They're used throughout the project.
- **ft_printf:** Here lies a handy function for printing formatted output to the stdout.
- **minilibx_macos:** A collection of functions that handle all the graphics magic.
- **srcs:** The heart of the project. This is where the main logic lies.
- **includes:** All the header files live here.

## 📁 Files

Let's take a closer look at the key players of the project, located inside the `srcs` and `includes` folders:

### srcs

- **color.c:** Conjures up colors based on height.
- **drawing.c:** The artist of the project. Draws lines and handles the rendering for rows and columns.
- **fdf.c:** The director. Initializes variables and runs mlx.
- **general_functions.c:** The all-rounder. Handles closing the window, key press, and mouse press.
- **read_fdf.c:** The reader. Reads the FdF file and creates a 2D array with the data.

### includes

- **fdf.h:** The blueprint. Contains all the structure definitions and function prototypes used in the project.
- **colors.h:** The color palette. Defines color codes.
- **keycodes.h:** The keyboard map. Defines key codes.

## 🗺️ Example Maps

Ready to start your adventure? You can find example maps in the `test_maps` folder.

## 👨‍💻 Author

Neil de la Fuente

Dive in, explore, and enjoy the landscapes!
