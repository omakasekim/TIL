import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        
        //for-each =    traversing technique to iterate through the elements in an array/collection
        //              less steps, more readable
        //              less flexible

        String[] animals = {"Cat", "Dog", "Rat"};
        //ArrayList<String> animals = new ArrayList<String>();
        for(String animal : animals){
            System.out.println(animal);
        }
    }
}
