# doomISH

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white" alt="Docker" />
  <img src="https://img.shields.io/badge/MiniLibX-111111?style=for-the-badge" alt="MiniLibX" />
</p>

`doomISH` is a small raycasting engine written in C and inspired by Wolfenstein 3D.
The program loads a `.cub` map, validates it, loads `.xpm` textures, and renders a real-time 3D view using MiniLibX.

<p align="center">
  <img src="./DoomISH.gif" alt="doomISH preview" />
</p>

## Features

- `.cub` configuration file loading and validation
- Map closure checks
- Wall texture and ceiling/floor color handling
- Player movement and camera rotation
- Real-time rendering with MiniLibX

## Requirements

Before building, make sure you have:

- `gcc`
- `make`
- the X11 dependencies required by MiniLibX

## Quick Start

1. Open a terminal at the root of the project.
2. Build the project:

```bash
make
```

3. Run the generated binary with a `.cub` file:

```bash
./doomISH files/wolfenstein.cub
```

If you want to use another map, replace the path with any valid `.cub` file.

## Docker

The project can also be built and run inside a Docker container.

### Build the image

```bash
docker compose build
```

### Allow X11 access on Linux

Before starting the container, allow access to your X11 server.
This step is required or the window will not open.

```bash
xhost +si:localuser:$(whoami)
```

If your desktop session uses an `XAUTHORITY` file, make sure it is available in your shell before running Docker.
If you are unsure, check:

```bash
echo "$XAUTHORITY"
```

If it prints nothing, your session may not use one explicitly.

### Run the project

```bash
docker compose up --build
```

By default, the container runs:

```bash
./doomISH files/garden.cub
```

You do not need to type `./doomISH` manually when using Docker.
The compose file starts it automatically.

If you only want to run the program locally, use:

```bash
./doomISH files/garden.cub
```

### Stop the container

```bash
docker compose down
```

## Demo Maps

- `files/wolfenstein.cub`
- `files/garden.cub`
- `files/librairy.cub`
- `files/window.cub`

## Controls

- `W` - move forward
- `S` - move backward
- `A` - strafe left
- `D` - strafe right
- Left arrow - rotate left
- Right arrow - rotate right
- `ESC` - quit

## Clean Commands

```bash
make clean
make fclean
make re
```

## `.cub` File Format

A map file contains:

- 4 wall textures: `NO`, `SO`, `WE`, `EA`
- 2 colors: `C` for ceiling, `F` for floor
- a map made of `0`, `1`, and exactly one start position `N`, `S`, `E`, or `W`

Example:

```text
NO ./textures/wolfenstein/blue_stone.xpm
SO ./textures/wolfenstein/color_stone.xpm
WE ./textures/wolfenstein/grey_stone.xpm
EA ./textures/wolfenstein/purple_stone.xpm

C 245,245,245
F 10,10,10

1111111
1000001
1000001
100N001
1000001
1000001
1000001
1000001
1111111
```


## Troubleshooting

If the build fails on MiniLibX callbacks, make sure the functions passed to `mlx_hook` and `mlx_loop_hook` use a `void *` parameter.
