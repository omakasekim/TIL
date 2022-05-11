public class App {
    public static void main(String[] args) throws Exception {
        
        String x = "water";
        String y = "Kool-Aid";

        System.out.println("x: " + x);
        System.out.println("y: " + y);

        String temp;
        temp = x;
        x = y;
        y = temp;
        System.out.println("x: " + x);
        System.out.println("y: " + y);

    }
}
