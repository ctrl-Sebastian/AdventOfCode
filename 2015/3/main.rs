use std::fs;
use std::collections::HashMap;
struct Position {
    x: i32,
    y: i32,
}

fn part_one() {
    for char in contents.chars() {
        match char {
            '>' => {
                santa_position.x += 1;
            }
            '<' => {
                santa_position.x -= 1;
            }
            '^' => {
                santa_position.y += 1;
            }
            'v' => {
                santa_position.y -= 1;
            }
            _ => {}
        }
        let current_position = (santa_position.x, santa_position.y);
        if grid.contains_key(&current_position) {
            grid.insert(current_position, grid[&current_position] + 1);
        } else {
            grid.insert(current_position, 1);
            houses_with_presents += 1;
        }
    }
    println!("Houses with presents: {}", houses_with_presents);
}

fn part_two() {
    
}

fn main() {
    let file_path = "./input.txt";
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");

    let mut grid: HashMap<(i32, i32), i32> = HashMap::new(); 
    let mut santa_position = Position { x: 0, y: 0 };
    let mut clone_position = Position { x: 0, y: 0 };

    let mut houses_with_presents = 0;
    
    
}