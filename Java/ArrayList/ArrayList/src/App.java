import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        //ArrayList = a resizable array.
        //            Elements can be added and removed after compilation phage
        //            store reference data types

        ArrayList<String> food = new ArrayList<String>();

        food.add("pizza");
        food.add("hamburger");
        food.add("hotdog");

        //food.set(0, "sushi");
        //food.remove(2);
        //food.clear();

        for(int i = 0; i < food.size(); i++){
            System.out.println(food.get(i));
        }
    }
}
