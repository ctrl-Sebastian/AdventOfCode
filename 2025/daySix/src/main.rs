use std::collections::HashMap;
use std::fs;

fn part_one(result: &mut i64, worksheet: &HashMap<i32, Vec<i64>>, last_line_numbers: &Vec<char>) {
    for k in 0..last_line_numbers.len() {
        if last_line_numbers[k] == '*' {
            *result += worksheet.get(&(k as i32)).unwrap().iter().product::<i64>();
        }

        if last_line_numbers[k] == '+' {
            *result += worksheet.get(&(k as i32)).unwrap().iter().sum::<i64>();
        }
    }

    println!("result: {:?}", result);
}

fn part_two(result: &mut i64, worksheet: &HashMap<i32, Vec<i64>>, last_line_numbers: &Vec<char>) {
    for k in 0..last_line_numbers.len() {

        // [4, 6, 827, 9472]

        let columns = worksheet.get(&(k as i32)).unwrap().iter().map(|n| n.to_string().len()).max().unwrap_or(0);
        let mut numbers_by_columns: Vec<i64> = vec![];
        for i in 0..columns {
            let mut current_column_digits: String = String::new();
            for n in worksheet.get(&(k as i32)).unwrap() {
                let num_str = n.to_string();
                if i < num_str.len() {
                    let digit_char = num_str.chars().nth(num_str.len() - 1 - i).unwrap();
                    current_column_digits.push(digit_char);
                }
            }
            if !current_column_digits.is_empty() {
                numbers_by_columns.push(current_column_digits.parse::<i64>().unwrap());
            }
        }
        if last_line_numbers[k] == '*' {
            println!("Multiplying column {}: {:?}", k, numbers_by_columns);
            *result += numbers_by_columns.iter().product::<i64>();
        }

        if last_line_numbers[k] == '+' {
            println!("Adding column {}: {:?}", k, numbers_by_columns);
            *result += numbers_by_columns.iter().sum::<i64>();
        }
    }

    println!("result: {:?}", result);
}

fn main() {
    let input_file = fs::read_to_string("./input.txt");
    let mut worksheet: HashMap<i32, Vec<i64>> = HashMap::new();
    let content = input_file.unwrap();
    let lines: Vec<&str> = content.lines().collect();
    let mut result: i64 = 0;

    for i in 0..lines.len() - 1 {
        let numbers: Vec<i64> = lines[i]
            .split_whitespace()
            .map(|num| num.parse::<i64>().unwrap())
            .collect();
        for j in 0..numbers.len() {
            worksheet
                .entry(j as i32)
                .or_insert(Vec::new())
                .push(numbers[j]);
        }
    }

    let last_line_numbers: Vec<char> = lines[lines.len() - 1]
        .split_whitespace()
        .map(|num| num.parse::<char>().unwrap())
        .collect();

    part_two(&mut result, &worksheet, &last_line_numbers);
}
