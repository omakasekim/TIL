import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        System.out.println("What is your name? ");
        String name = scanner.nextLine();
        System.out.println("How old are you? ");
        int age = scanner.nextInt();

        scanner.nextLine();

        System.out.println("What is your favorite food? ");
        String food = scanner.nextLine();


        System.out.println("Hello. "+ name + ", you are "+ age + " years old, you like "+food);
        scanner.close();
    }

}
