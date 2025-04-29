use std::fs;

fn main() {
    let file_path = "./input.txt";
    // --snip--
    println!("In file {file_path}");

    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");

    let mut floor = 0;
    let mut counter = 1;
    let mut has_entered_basement = false;
    let mut position_of_char_to_basement = 0;

    println!("Current floor: {floor} at position {counter}");
	println!("Santa starts now!");
    for char in contents.chars() {
        if char == '(' {
            floor += 1;
        } else if char == ')' {
            floor -= 1;
        }

        println!("Santa moved, current floor: {floor} char at position {counter}");

        if floor == -1 && has_entered_basement == false {
            position_of_char_to_basement = counter;
            has_entered_basement = true;
        }
        counter += 1;
    }
	if has_entered_basement {
		println!("First character to enter basement: {position_of_char_to_basement}");
	} else {
		println!("Never entered basement");
	}
    println!("Total: {floor}");
}
