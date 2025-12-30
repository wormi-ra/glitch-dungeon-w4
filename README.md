# Glitch Dungeon WASM4

A game written in C++ for the [WASM-4](https://wasm4.org) fantasy console.

It is a complete reimplementation of the original [Glitch Dungeon](https://jakeonaut.itch.io/glitch-dungeon) game by [jakeonaut](https://jakeonaut.github.io/) with permission from the original author.

## Controls

The player is controlled with the gamepad 1,
Spells can be cast using either the BUTTON_1 (X) to cycle through spells,
or can be selected using the gamepad 2, or by clicking on the spell bar ingame.

### Gamepad 1

| Button    | Default Key | Action                            |
| ---       | ---         | ---                               |
| UP        | Up arrow    | Jump                              |
| LEFT      | Left arrow  | Move left                         |
| DOWN      | Down arrow  | Fallthrough / Interact with doors |
| RIGHT     | Right arrow | Move right                        |
| BUTTON_1  | X           | Cycle spell                       |
| BUTTON_2  | Z           | Respawn                           |

### Gamepad 2

| Button      | Default Key | Action  |
| ---         | ---         | ---     |
| UP          | Up arrow    | Spell 1 |
| LEFT        | Left arrow  | Spell 2 |
| DOWN        | Down arrow  | Spell 3 |
| RIGHT       | Right arrow | Spell 4 |
| BUTTON_1    | Tab         | Spell 5 |
| BUTTON_2    | Q           | Spell 6 |

### Reset all progress

Holding BUTTON_2 (Z) for 2 seconds will prompt you to reset your save file

## Building

To compile C/C++ projects you will need to download the [WASI SDK](https://github.com/WebAssembly/wasi-sdk) and set the $WASI_SDK_PATH environment variable.

[wasm-opt](https://github.com/WebAssembly/binaryen) is required to achieve smaller size builds

Build the cart by running:

```shell
make
```

Then run it with:

```shell
w4 run build/cart.wasm
```

For more info about setting up WASM-4, see the [quickstart guide](https://wasm4.org/docs/getting-started/setup?code-lang=cpp#quickstart).
