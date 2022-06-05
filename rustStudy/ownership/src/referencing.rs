fn main() {
    let s1 = String::from("hello");
    let s = String::from("hello");

    let len = calculate_length(&s1);

    println!("The length of '{}' is {}.", s1, len);
    //change(&s);
    //cannot change borrowed value
    println!("{}", s);
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn change(some_string: &String) {
    some_string.push_str(", world");
}