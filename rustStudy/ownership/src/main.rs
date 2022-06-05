fn main() {
    let mut s = String::from("Hello");

    s.push_str(", World!");
    println!("{}",s);


    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("s1 = {}, s2 = {}",s1, s2);

}



