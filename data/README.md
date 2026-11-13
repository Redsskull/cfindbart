# World data

`worlds.json` holds an array of world objects under the `worlds` key.
Each world has:

- `id`: a stable identifier, independent of its displayed name.
- `name`: the name shown to the player.
- `description`: information shown before choosing a world.
- `clue`: a transmission from Bart when he is hiding on this world.
- `search_scene`: text shown when the player searches this world.

Standard JSON does not support comments, so explanations live here instead.
Use double-quoted keys and strings, with commas between fields and objects,
but no trailing commas.

The C game reads this file into a fixed buffer and prints it before gameplay.
It accepts at most 8,191 bytes, reserving one byte for the terminating zero.
It does not parse JSON yet, and gameplay still uses its built-in text.
Artwork fields can be added when the game needs them.
