use std::fs;

fn check_if_in_ranges(ranges: &Vec<String>, id: u64, counter: &mut u64) {
    for range in ranges {
        let parts: Vec<&str> = range.split('-').collect();
        let start: u64 = parts[0].parse().unwrap();
        let end: u64 = parts[1].parse().unwrap();

        if id >= start && id <= end {
            *counter += 1;
        }
    }

}

fn count_fresh_ingredients(ranges_str: &Vec<String>, counter: &mut u64) {

}

fn part_one(input_file: Result<String, std::io::Error>) {
    let mut counter: u64 = 0;
    let mut ranges: Vec<String> = Vec::new();
    let mut ids: Vec<u64> = Vec::new();

    let mut empty_line_found = false;
    for line in input_file.unwrap().lines() {
        if line.is_empty() {
            empty_line_found = true;
            continue;
        }

        if empty_line_found {
            ids.push(line.parse::<u64>().unwrap());
            continue;
        }

        ranges.push(line.to_string());
    }

    for id in ids {
        check_if_in_ranges(&ranges, id, &mut counter);
    }

    println!("Number fresh ingredients: {}", counter);
}

fn part_two(ranges_file: Result<String, std::io::Error>) {
    let mut counter: u64 = 0;
    let ranges: Vec<String> = ranges_file.unwrap().lines().map(|s| s.to_string()).collect();

    count_fresh_ingredients(&ranges, &mut counter);

    println!("Total fresh ingredients: {}", counter);
}

fn main() {
    let input_file = fs::read_to_string("./input.txt");
    let ranges_file = fs::read_to_string("./ranges.txt");
    part_two(ranges_file);
}
