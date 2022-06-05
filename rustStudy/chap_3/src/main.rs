fn main() {
    println!("Hello, world!");
}

fn FarenheitToCelcius(f: i32) -> i32 {
    return f+32;
}


fn Fibonacci(n: i32) -> i32 {
    if n==0{
        return 1;
    }
    return n+Fibonacci(n-1);
}