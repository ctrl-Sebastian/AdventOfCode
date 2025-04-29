use std::fs;

fn min_between(a: u32, b: u32, c: u32) -> u32 {
    let mut min = a;
    if b < a {
        min = b;
        if c < b {
            min = c;
        }
    } else if c < a {
        min = c;
        if b < c {
            min = b;
        }
    }
    return min;
}

fn get_paper_needed(w: u32, l: u32, h: u32) -> u32 {
    // calculate the area of the sides
    let lw = l * w;
    let lh = l * h;
    let wh = w * h;

    // calculate the total area
    let total_area = 2 * (lw + lh + wh);

    let smallest_side = min_between(lw, lh, wh);
    // calculate the smallest side
    return total_area + smallest_side;
}

fn get_ribbon_needed(w: u32, l: u32, h: u32) -> u32 {
    let volume = w * l * h;
    let smallest_perimeter = min_between(2 * (l + w), 2 * (l + h), 2 * (w + h));
    return volume + smallest_perimeter;    
}

fn main() {
    let file_path = "./input.txt";
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");
    let mut total_wrapping_paper = 0;
    let mut total_ribbon = 0;

    // make tuple of the line number and line content
    // contents.lines() is an iterator over the lines of the string
    // enumerate() is an iterator that yields pairs of (index, value)
    for (_i, line) in contents.lines().enumerate() {
        // parse the numbers in the line i.e.: "25x12x9" -> l=25, w=12, h=9
        let dimensions: Vec<u32> = line
            .split('x')
            .map(|s| s.parse().expect("Should be a number"))
            .collect();

        let l = dimensions[0];
        let w = dimensions[1];
        let h = dimensions[2];

        total_wrapping_paper += get_paper_needed(l, w, h);
        total_ribbon += get_ribbon_needed(l, w, h);

    }
    println!("Total wrapping paper needed: {}", total_wrapping_paper);
    println!("Total ribbon needed: {}", total_ribbon);
}
