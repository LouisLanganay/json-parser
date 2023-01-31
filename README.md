
# json_parser lib

A json parser for RPG project

## Exe compilation

To compile this project run the following command at ``lib/jp``

```bash
    make
```

## Usefull functions

```c
parsed_data_t *jp_parse(char *filepath);
parsed_data_t *jp_search(parsed_data_t *data, char *name);
void jp_write(char *filepath, parsed_data_t *object);
```

## Example

### SEARCHER

```json
{
    "name": "Louis",
    "hp": 100,
    "alive": true,
    "pos": {
        "x": 11110, // -- HERE --
        "y": 220
    },
    "inventory": {
        "size": 12,
        "bag": true,
        "items": [
            1,
            2,
            40
        ]
    }
}
```

If I want to acces to player pos_x:
```c
parsed_data_t *data = jp_parse(JSON_FILE_PATH);
int pos_x = jp_search(data, "pos.x")->value.p_int;
```

### WRITER

```json
{
    "michel": {
        "dialogues": [
            {
                "id": 1,
                "posibilities": [
                    "Hello!",
                    "Bonjour aventurier !", // -- HERE --
                    "Salut à toi !"
                ]
            },            
            {
                "id": 2,
                "posibilities": [
                    "Merci"
                ]
            }
        ]
    }
}
```

If I want to modify second `posibility` of the first `dialogue` of `michel`:
```c
parsed_data_t *data = jp_parse(JSON_FILE_PATH);
jp_search(data, "michel.dialogues[0].posibilities[0]")->value.p_str = "Bonjour grand aventurier !";
jp_write(JSON_FILE_PATH, data);
```


## parsed_data_t struct

![JSON PARSER](https://user-images.githubusercontent.com/114762819/215821384-4724d72d-03c1-4236-b0bb-7018c87ac8fd.png)

## How Json Work ?

![1j](https://user-images.githubusercontent.com/114762819/215849382-1dcdd4a9-67f9-4c24-bf06-10ab50c954da.jpg)
![2j](https://user-images.githubusercontent.com/114762819/215849416-41f305c0-a7cd-495b-b912-d2d4b12fe495.jpg)
![3j](https://user-images.githubusercontent.com/114762819/215849429-8bbe2596-eef6-4a86-9e64-c369c4d9eaef.jpg)
![4j](https://user-images.githubusercontent.com/114762819/215849437-9c5f2cf1-0544-4f60-b7d5-40d9f4b59a43.jpg)
![5j](https://user-images.githubusercontent.com/114762819/215849443-0c1780a3-24d7-4431-8728-f941b1b0f8d3.jpg)
![6j](https://user-images.githubusercontent.com/114762819/215849459-ceb38dd5-822e-4a93-bc26-288c6802dc6d.jpg)


## Authors

- [@L.Langanay](https://github.com/LouisLanganay) [![wakatime](https://wakatime.com/badge/user/3372edb3-08ff-4829-807b-29bbe42cf52b/project/00808c22-7cfb-47b3-a618-84cc06c3f59b.svg)](https://wakatime.com/badge/user/3372edb3-08ff-4829-807b-29bbe42cf52b/project/00808c22-7cfb-47b3-a618-84cc06c3f59b)

![Logo](https://newsroom.ionis-group.com/wp-content/uploads/2021/10/EPITECH-TECHNOLOGY-QUADRI-2021.png)

