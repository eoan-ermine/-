use std::io::Read;

fn main() {
    let mut buf = String::new();

    std::io::stdin().read_to_string(&mut buf).unwrap();
    let a: f64 = buf.parse().unwrap();

    std::io::stdin().read_to_string(&mut buf).unwrap();
    let b: f64 = buf.parse().unwrap();

    println!("{}", (a / b) as i64);
}