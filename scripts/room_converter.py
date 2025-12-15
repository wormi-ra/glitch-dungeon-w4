from pathlib import Path
from itertools import groupby
import os
import sys
import json
from typing import TextIO
from jinja2 import Environment, FileSystemLoader, select_autoescape

BASE_PATH = "assets/rooms/"
JINJA_ENV = Environment(
    loader=FileSystemLoader("scripts/templates/"),
    autoescape=select_autoescape(),
    lstrip_blocks=True,
    trim_blocks=True
)

ENTITY_I = 0
ENTITIES = []


def convert_tile(tile):
    mapping = {
        (0,0): 0,
        (1,0): 0,
        (0,1): 0,
        (1,1): 1,
        (2,0): 2,
        (3,0): 3,
        (0,2): 4,
        (1,2): 5,
        (2,1): 6,
        (3,1): 7,
        (0,3): 8,
        (1,3): 9,
        (2,2): 10,
        (3,2): 11,
        (0,4): 12,
        (1,4): 13,
        (2,3): 14,
        (3,3): 15
    }
    if "tx" not in tile:
        tile["tx"] = 0
    if "ty" not in tile:
        tile["ty"] = 0
    if "c" not in tile:
        tile["c"] = -1
    t = mapping[tile["tx"], tile["ty"]]
    c = tile["c"] + 1
    return t | (c << 4)


def rle_encode(iterable, max = 255):
    groups = [        
        (len(g[i:i + max]), k)
        for k, [*g] in groupby(iterable)
        for i in range(0, len(g), max)
    ]
    return [
        c for group in groups
        for c in group
    ]


def convert_entity(entity):
    entity["obj"]["x"] = round(entity["obj"]["x"])
    entity["obj"]["y"] = round(entity["obj"]["y"])
    if (entity["type"] == "Collection" and entity["obj"]["collection_id"] is None):
        entity["obj"]["collection_id"] = 0
    return entity


def convert_room(room):
    global ENTITY_I
    global ENTITIES
    data = rle_encode([
            convert_tile(tile)
            for line in room["tiles"]
            for tile in line
        ])
    room_entities = []
    for entity in room["entities"]:
        if entity["type"] == "Hat":
            continue
        ENTITIES.append(convert_entity(entity))
        room_entities.append(ENTITY_I)
        ENTITY_I += 1
    return {
        "entities": room_entities,
        "width": room["width"] // 8,
        "height": room["height"] // 8,
        "glitch_type": room["glitch_type"],
        "glitch_sequence": room["glitch_sequence"],
        "glitch_time_limit": room["glitch_time_limit"],
        "can_use_spellbook": room["can_use_spellbook"],
        "bg_code": room["bg_code"] if "bg_code" in room else None,
        "tile_data": {
            "len": len(data),
            "data": data
        }
    }


def generate_index_file(file: TextIO, index: list[str]):
    for name in index:
        file.write(f'export {{ ROOM as {name} }} from "./{name.lower()}";\n')


def generate_dungeon(file: TextIO):
    dungeon = [
        [
            f"rooms.ROOM_{x}_{y}" for x in range(0,6)
        ] for y in range(0,6)
    ]
    file.write((f"export const DUNGEON = [{',\n'.join(['['+', '.join(line)+']' for line in dungeon])}];\n"))


def output_rooms(rooms: list):
    template = JINJA_ENV.get_template("room.jinja")
    print(template.render(rooms=rooms))


def output_entities(entities: list):
    template = JINJA_ENV.get_template("entities.jinja")
    print(template.render(entities=entities))


if __name__=="__main__":
    index = []
    rooms = []
    for file in os.listdir(sys.argv[1]):
        path = Path(sys.argv[1], file)
        name = path.stem.upper()
        index.append(name)
        with open(path) as file:
            room = json.load(file)
            convert = convert_room(room)
            convert["name"] = name.upper()
            rooms.append(convert)
    output_rooms(rooms)
    # output_entities(ENTITIES)
    # generate_dungeon(sys.stdout)
